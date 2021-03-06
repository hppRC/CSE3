%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "data-structures.h"
#include "symbol-table.h"

FILE *fp;
static const char *filename = "result.ll";

static int scope = GLOBAL_VAR;
static int count = 0;
extern reg_counter;
//前の値を積んでいくスタックを作るとネストにも対応できそう
int tmp;
int tmp1,tmp2, tmp3;

%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%%

program
        :
        PROGRAM IDENT SEMICOLON outblock PERIOD {
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
        ;

outblock
        : var_decl_part subprog_decl_part {
        insert_decl("main", 0, NULL);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        insert_code(Alloca);
        insert_code(Store);
        }
        statement {
        back_patch();
        //insert_code(Load);
        //insert_code(Ret);
        }
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : /* empty */
        | subprog_decl_list SEMICOLON
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON {
        scope = LOCAL_VAR;
        count = 1;
        }
        inblock {
        back_patch();
        //insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
        ;

proc_name
        : IDENT {
        insert_symbol(PROC_NAME, $1, 1);
        insert_decl($1, 0, NULL);
        }
        ;

inblock
        : var_decl_part statement
        ;

statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : IDENT ASSIGN expression {
        Factor x = create_factor_by_name($1);
        factor_push(x);
        insert_code(Store);
        }
        ;

if_statement
        : IF condition THEN {
        insert_code(BrCond);
        insert_code(Label);
        }
        statement {
        insert_code(BrUncond);
        label_push(reg_counter);


        }
        else_statement
        ;

else_statement
        : /* empty */ {
        label_push(reg_counter);
        insert_code(Label);
        }
        | ELSE {
        insert_code(Label);
        }
        statement {
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
        ;

while_statement
        : WHILE {
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
        condition DO {
        insert_code(BrCond);
        insert_code(Label);
        }
        statement {
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
        ;

for_statement
        : FOR IDENT ASSIGN expression {
        Factor x = create_factor_by_name($2);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp1 = reg_counter;
        insert_code(Label);
        factor_push(x);
        insert_code(Load);
        }
        TO expression {
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
        DO statement {
        insert_code(BrUncond);
        tmp2 = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name($2);
        factor_push(x);
        insert_code(Load);
        Factor for_factor = {CONSTANT, "", 1};
        factor_push(for_factor);
        insert_code(Add);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        tmp3 = reg_counter;
        label_push(tmp3);
        label_push(tmp2);
        label_push(tmp1);
        insert_code(Label);
        }
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        {
        Factor x = create_factor_by_name($1);
        factor_push(x);
        insert_code(Proc);
        }
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN {
        set_read_flag(TRUE);
        Factor x = create_factor_by_name($3);
        factor_push(x);
        insert_code(Read);
        }
        ;

write_statement
        : WRITE LPAREN expression RPAREN {
        set_write_flag(TRUE);
        insert_code(Write);
        }
        ;

null_statement
        : /* empty */
        ;

condition
        : expression EQ expression {set_cmp_type(EQUAL); insert_code(Icmp);}
        | expression NEQ expression {set_cmp_type(NE); insert_code(Icmp);}
        | expression LT expression {set_cmp_type(SLT); insert_code(Icmp);}
        | expression LE expression {set_cmp_type(SLE); insert_code(Icmp);}
        | expression GT expression {set_cmp_type(SGT); insert_code(Icmp);}
        | expression GE expression {set_cmp_type(SGE); insert_code(Icmp);}
        ;

expression
        : term
        | PLUS term
        | MINUS term
        | expression PLUS term {insert_code(Add);}
        | expression MINUS term {insert_code(Sub);
        }
        ;

term
        : factor
        | term MULT factor {insert_code(Mult);}
        | term DIV factor {insert_code(Div);}
        ;

factor
        : var_name
        | NUMBER {Factor x = {CONSTANT, "", $1}; factor_push(x);}
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT {
        Factor x = create_factor_by_name($1);
        factor_push(x);
        insert_code(Load);
        }
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT {
        insert_symbol(scope, $1, count++);
        if (scope == LOCAL_VAR) insert_code(Alloca);
        }
        | id_list COMMA IDENT {
        insert_symbol(scope, $3, count++);
        if (scope == LOCAL_VAR) insert_code(Alloca);
        }
        ;

%%


yyerror(char *s)
{
        extern int yylineno;
        extern char *yytext;

        fprintf(
                stderr,
                "%s\nline number: %d\nmessage:\n%s\n",
                s, yylineno, yytext
        );
}
