%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-structures.h"
#include "symbol-table.h"

extern Factor factor_pop();
extern void factor_push(Factor x);
extern void llvm_generate_code_by_command(LLVMcommand command);
extern void display_llvm();

extern void insert(int type, char *name, int val);
extern Node *lookup(char *);
extern void delete_local_node(void);


int scope = GLOBAL_VAR;

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
        PROGRAM IDENT SEMICOLON outblock PERIOD {display_llvm();}
        ;

outblock
        : var_decl_part subprog_decl_part {
                decl_insert("main", 0, NULL, NULL);
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
        }
        inblock
        {delete_local_node();
        scope = GLOBAL_VAR;}
        ;

proc_name
        : IDENT
        {
        insert(PROC_NAME, $1, 1);
        decl_insert($1, 0, NULL, NULL);
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
        Node *node_ptr = lookup($1);

        }
        ;

if_statement
        : IF condition THEN statement else_statement
        ;

else_statement
        : /* empty */
        | ELSE statement
        ;

while_statement
        : WHILE condition DO statement
        ;

for_statement
        : FOR IDENT ASSIGN expression TO expression DO statement
        {lookup($2);}
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        {lookup($1);}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
        {lookup($3);}
        ;

write_statement
        : WRITE LPAREN expression RPAREN
        ;

null_statement
        : /* empty */
        ;

condition
        : expression EQ expression
        | expression NEQ expression
        | expression LT expression
        | expression LE expression
        | expression GT expression
        | expression GE expression
        ;

expression
        : term
        | PLUS term
        | MINUS term
        | expression PLUS term
        {llvm_generate_code_by_command(Add);}
        | expression MINUS term
        {llvm_generate_code_by_command(Sub);
        }
        ;

term
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor
        : var_name
        | NUMBER {
        Factor x = {scope, "number", $1};
        factor_push(x);}
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT
        {Node *node_ptr = lookup($1);
        Factor x;
        x.type = scope;
        strcpy(x.name, node_ptr->name);
        x.val = node_ptr->val;
        factor_push(x);
        }
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT
        {insert(scope, $1, 0);
        if (scope == LOCAL_VAR) {
                llvm_generate_code_by_command(Alloca);
        };}
        | id_list COMMA IDENT
        {insert(scope, $3, 0);}
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
