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
                if ((fp = fopen(filename, "w")) == NULL) {
                        fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                return EXIT_FAILURE;
                }
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
        } statement
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
        : PROCEDURE proc_name SEMICOLON
        {
        scope = LOCAL_VAR;
        count = 1;
        }
        inblock
        {
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
        ;

proc_name
        : IDENT
        {
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
        : IDENT ASSIGN expression
        {
        Factor x = create_factor_by_name($1);
        factor_push(x);
        insert_code(Store);
        }
        ;

if_statement
        : IF condition THEN {insert_code(BrCond);insert_code(Label);} statement else_statement
        ;

else_statement
        : /* empty */ {insert_code(BrUncond);insert_code(Label);}
        | ELSE  statement {insert_code(BrCond);insert_code(Label);}
        ;

while_statement
        : WHILE {insert_code(BrUncond);insert_code(Label);}
        condition DO {insert_code(BrCond);insert_code(Label);} statement
        ;

for_statement
        : FOR IDENT ASSIGN expression TO expression DO statement
        {lookup_symbol($2);}
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT {lookup_symbol($1);}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN {lookup_symbol($3);}
        ;

write_statement
        : WRITE LPAREN expression RPAREN
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
        : IDENT
        {
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
        : IDENT
        {
                insert_symbol(scope, $1, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
        | id_list COMMA IDENT
        {
                insert_symbol(scope, $3, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
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
