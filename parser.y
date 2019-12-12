%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  CONSTANT    /* 定数     */
} Scope;


/* 変数もしくは定数の型 */
typedef struct {
  Scope type;      /* 変数（のレジスタ）か整数の区別 */
  char *vname; /* 変数の場合の変数名 */
  int val;         /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct {
  Factor element[100];  /* スタック（最大要素数は100まで） */
  unsigned int top;     /* スタックのトップの位置         */
} Factorstack;

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */
int scope = GLOBAL_VAR;

Factor factorpop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void print_all_factor() {
  printf("-------------\n");
  int now = fstack.top;
  while (now > 0) {
    printf("%d, %s, %d\n",fstack.element[now].type, fstack.element[now].vname, fstack.element[now].val);
    now--;
  }
  return;
}

void factorpush(Factor x) {
  fstack.top++;
  fstack.element[fstack.top].type = x.type;
  fstack.element[fstack.top].vname = (char *)malloc(sizeof(char) * (strlen(x.vname) + 1));
  strcpy(fstack.element[fstack.top].vname, x.vname);
  fstack.element[fstack.top].val = x.val;
  return;
}


Factor lookup_data(char *name) {
  int now = fstack.top;
  while (now > 0) {
    Factor x = fstack.element[now];
    if (strcmp(x.vname, name) == 0) {
      return x;
    }
    now--;
  }
}

void delete_data() {
  int now = fstack.top;
  while (now > 0) {
    if (fstack.element[now].type == LOCAL_VAR) {
      free(fstack.element[now]);
      fstack.top--;
    }
    now--;
  }
  return;
}


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
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        {print_all_factor();}
        ;

outblock
        : var_decl_part subprog_decl_part statement
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
        {scope = LOCAL_VAR;}
        inblock
        {delete_data();
                scope = GLOBAL_VAR;}
        ;

proc_name
        : IDENT
        {
        Factor x = {scope, $1, 1};
        factorpush(x);
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
        {lookup_data($1);}
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
        {lookup_data($2);}
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        {lookup_data($1);}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
        {lookup_data($3);}
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
        | expression MINUS term
        ;

term
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor
        : var_name
        | NUMBER
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT
        {lookup_data($1);}
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT
        {Factor x = {scope, $1, 1};
        factorpush(x);}
        | id_list COMMA IDENT
        {
        Factor x = {scope, $3, 1};
        factorpush(x);}
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
