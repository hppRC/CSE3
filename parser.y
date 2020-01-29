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
extern ret_type;


//前の値を積んでいくスタックを作るとネストにも対応できそう
Stack tmp = {{}, 0};

int i = 0;
int var_mode = FALSE;
int arity_mode = FALSE;
int func_mode = FALSE;

int var_num = 0;
int arity_num = 0;

Factor tmp1_element[100];
int tmp1_top = 0;

Factor tmp2_element[100];
int tmp2_top = 0;

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

%type<ident> proc_func_name
%type<ident> proc_call_name

%%

program
        : PROGRAM IDENT SEMICOLON outblock PERIOD {
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
        ;

outblock
        : var_decl_part subprog_decl_part {
        insert_decl("main", 0, NULL, VOID);
        //mainが引数をとるようになるならここにoverwriteの処理を挟む
        reg_counter = 1;
        insert_code(Alloca);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        insert_code(Store);
        }
        statement {
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
        : VAR {
        var_mode = TRUE;
        } id_list {
        var_mode = FALSE;
        }
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
        | func_decl
        ;

proc_decl
        : PROCEDURE proc_func_name SEMICOLON {
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, $2, 0);
        insert_decl($2, 0, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
        inblock {
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }

        | PROCEDURE proc_func_name {
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, $2, count);
        arity_mode = TRUE;
        }
        LPAREN id_list RPAREN SEMICOLON {
        arity_mode = FALSE;
        //レジスタの値は返り値分一つ増やしておく
        //reg_counter: 引数(n個),返り値(1個),局所変数(m個), 中身(k個)の順に番号づけされる
        overwrite_symbol_arity($2, arity_num);
        insert_decl($2, arity_num, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
        inblock {
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
        ;

proc_func_name
        : IDENT
        ;



func_decl
        : FUNCTION IDENT SEMICOLON {
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, $2, count);
        insert_symbol(LOCAL_VAR, $2, count);
        insert_decl($2, 0, NULL, INT);
        reg_counter = count + 1;
        count++;
        } inblock {
        Factor x = create_factor_by_name($2);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }

        | FUNCTION IDENT {
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, $2, count);
        insert_symbol(LOCAL_VAR, $2, count);
        func_mode = TRUE;
        arity_mode = TRUE;
        } LPAREN id_list RPAREN SEMICOLON {
        arity_mode = FALSE;
        overwrite_symbol_arity($2, arity_num);
        insert_decl($2, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        } inblock {
        func_mode = FALSE;
        Factor x = create_factor_by_name($2);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }
        ;

inblock
        : var_decl_part {
                for (i = 0; i < var_num + arity_num; i++) {
                        tmp1_element[i] = factor_pop();
                        tmp1_top++;
                }
                for (i = 0; i < var_num + arity_num + func_mode; i++) {
                        insert_code(Alloca);
                }
                for (i = 0; i < var_num + arity_num; i++) {
                        tmp2_element[i] = factor_pop();
                        tmp2_top++;
                }
                for (i = var_num + arity_num ; i > var_num; i--) {
                        factor_push(tmp2_element[i-1]);
                        factor_push(tmp1_element[i-1]);
                        insert_code(Store);
                }
                tmp1_top = 0;
                tmp2_top = 0;
                //記号表のアドレスの更新,新しいlocal varを突っ込む,引数は全てlocalだから上書きオッケー
                //関数呼び出しの時は、返り値用の変数が事前に宣言されていると考える
                overwrite_symbol_val(var_num + func_mode, arity_num);
        } statement
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
        : var_name ASSIGN expression {
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
        tmp.element[tmp.top++] = reg_counter;
        }
        else_statement
        ;

else_statement
        : /* empty */ {
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
        | ELSE {
        insert_code(Label);
        }
        statement {
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
        ;

while_statement
        : WHILE {
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
        condition DO {
        insert_code(BrCond);
        insert_code(Label);
        }
        statement {
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
        ;

for_statement
        : FOR IDENT {
        Factor x = create_factor_by_name($2);
        factor_push(x);
        } ASSIGN expression {
        insert_code(Store);
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name($2);
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
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name($2);
        factor_push(x);
        factor_push(x);
        insert_code(Load);
        Factor for_factor = {CONSTANT, "", 1};
        factor_push(for_factor);
        insert_code(Add);
        insert_code(Store);
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        label_push(tmp.element[--tmp.top]);
        label_push(tmp.element[--tmp.top]);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
        ;

proc_call_statement
        : proc_call_name {
        Factor x = create_proc_or_func_factor($1, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
        | proc_call_name LPAREN arg_list {
        Factor x = create_proc_or_func_factor($1, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        } RPAREN
        ;

proc_call_name
        : IDENT
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
        | READ LPAREN IDENT LBRACKET expression RBRACKET {
        Factor x = {CONSTANT, "", 1};
        factor_push(x);
        insert_code(Sub);
        } RPAREN {
        set_read_flag(TRUE);
        insert_code(Sext);
        Factor x = create_factor_by_name($3);
        factor_push(x);
        insert_code(GEP);
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
        | expression MINUS term {insert_code(Sub);}
        ;

term
        : factor
        | term MULT factor {insert_code(Mult);}
        | term DIV factor {insert_code(Div);}
        ;

factor
        : var_name {
        insert_code(Load);
        }
        | NUMBER {
        Factor x = {CONSTANT, "", $1};
        factor_push(x);
        }
        | func_call
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT {
        Factor x = create_factor_by_name($1);
        factor_push(x);
        }
        | IDENT LBRACKET expression RBRACKET {
        Factor x = {CONSTANT, "", 1};
        factor_push(x);
        insert_code(Sub);
        insert_code(Sext);
        x = create_factor_by_name($1);
        factor_push(x);
        insert_code(GEP);
        }
        ;


func_call
        : proc_func_name LPAREN arg_list RPAREN {
        Factor x = create_proc_or_func_factor($1, get_aritystack_top());
        //create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる
        //関数名と返り値の名前が一緒なのでこれでオケ
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
        ;


arg_list
        : expression {
        Factor x = factor_pop();
        arity_push(x);
        }
        | arg_list COMMA expression {
        Factor x = factor_pop();
        arity_push(x);
        }
        ;

id_list
        : IDENT {
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, $1, count++);
        Factor x = create_factor_by_name($1);
        factor_push(x);
        }
        | IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET {
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, $1, count++, $3, $5);
        Factor x = create_factor_by_name($1);
        factor_push(x);
        }
        | id_list COMMA IDENT {
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, $3, count++);
        Factor x = create_factor_by_name($3);
        factor_push(x);
        }
        | id_list COMMA IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET {
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, $3, count++, $5, $7);
        Factor x = create_factor_by_name($3);
        factor_push(x);
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
