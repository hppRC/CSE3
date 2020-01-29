#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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


/*前の値を積んでいくスタックを作るとネストにも対応できそう*/
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

#line 44 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 72 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    7,    3,    4,    4,    8,    8,   11,    9,    5,
    5,   12,   12,   13,   13,   17,   14,   18,   19,   14,
    1,   20,   15,   21,   22,   15,   23,   16,   24,   24,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   25,
   37,   39,   26,   38,   40,   38,   41,   42,   27,   43,
   44,   45,   28,   29,   47,   29,    2,   31,   32,   48,
   32,   33,   30,   36,   36,   36,   36,   36,   36,   35,
   35,   35,   35,   35,   49,   49,   49,   50,   50,   50,
   50,   34,   34,   51,   46,   46,   10,   10,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    0,    5,    0,    0,    9,
    1,    0,    5,    0,    0,    9,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    7,    0,    0,    3,    0,    0,    6,    0,
    0,    0,   11,    1,    0,    5,    1,    3,    4,    0,
    8,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    1,
    3,    1,    4,    4,    1,    3,    1,    6,    3,    8,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    2,    0,   13,   14,   15,    0,    0,
    0,    0,   21,    0,    0,    0,    6,    0,    0,   22,
    0,   16,    0,    0,    0,    0,    0,   47,    0,    0,
    0,    3,   31,   32,   33,   34,   35,   36,   37,   38,
   39,    0,   12,    0,    0,    0,    0,    0,    0,   30,
    0,   50,    0,    0,    0,   79,    0,    0,   78,    0,
    0,    0,   75,   80,    0,    0,    0,    0,    0,    0,
    0,    0,   27,   23,    0,   17,    0,   58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   81,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   76,   77,   59,    0,   48,   62,   83,    0,    0,   88,
    0,   28,   25,   19,    0,   84,   42,    0,    0,    0,
   56,    0,    0,    0,    0,    0,   60,   49,   90,   26,
   20,    0,   45,   43,    0,    0,    0,   61,    0,   46,
    0,   53,
};
static const short yydgoto[] = {                          2,
   68,   41,    6,   83,   14,   42,   25,    8,    9,   21,
   10,   15,   16,   17,   18,   84,   58,   33,  154,   56,
   31,  153,  115,   61,   43,   44,   45,   46,   47,   48,
   49,   50,   51,   69,   70,   71,  130,  164,  156,  167,
   76,  149,   90,  155,  169,  111,  139,  165,   72,   73,
   74,
};
static const short yysindex[] = {                      -235,
 -186,    0, -233, -183,    0, -196, -159, -168,    0, -155,
    0, -150, -140,    0, -153,    0,    0,    0, -183, -112,
 -117, -109,    0,  -95, -173, -159,    0, -122,  -90,    0,
  -78,    0,  -71, -173,  -80,  -76,  -70,    0,  -56,  -60,
  -44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -61,    0,  -48,  -53, -183, -155, -183, -155,    0,
 -241,    0, -214, -214,  -76,    0,  -60,  -40,    0,   94,
  -22, -271,    0,    0,  -47,  -76,  -76,  -76,  -76,  -76,
  -45,  -42,    0,    0, -216,    0, -125,    0, -173,  -31,
 -271, -271, -207,  -76, -214, -214,  -76,  -76,  -76,  -76,
  -76,  -76,    0, -214, -214, -222,   -6, -188, -266, -247,
  -28, -247,  -21,  -19, -173,  -16,  -15,    0,  -76,    0,
 -115, -271, -271, -247, -247, -247, -247, -247, -247, -173,
    0,    0,    0,  -76,    0,    0,    0,  -76,  -18,    0,
  -17,    0,    0,    0, -247,    0,    0, -263, -173, -247,
    0,  -12, -183, -183,    6,   18,    0,    0,    0,    0,
    0,  -76,    0,    0,   -4, -247, -173,    0,   24,    0,
 -173,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -154,    0,    0, -142,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -213, -259,
   -7,    2,    0,    3,    4, -116,    0,    0,    0,    0,
    0,    0,    0, -239,    0,    0,    0,    0,    0, -218,
 -199,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -123, -114,    0, -114,    0,    0,
    0,    0,    0,    0,    0,    0,  -92,    0,    0,    0,
    0,  -58,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -239,    0,
  -24,   10,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -81,
    9, -128,    0,    0,   11,    0,    0,    0,    0,    0,
    0,   44,   78, -246, -234, -215, -175, -135, -132,  -51,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,    0,    0,    0,  -51,  -46,
    0,    0, -114, -114,    0, -258,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   47,  -51,    0,    0,    0,
  -51,    0,
};
static const short yygindex[] = {                         0,
  293,    0,    0,  303,    0,  -33,    0,    0,  289,   55,
    0,    0,  283,    0,    0,  -52,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -25,  -62,  234,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  217,    0,    0,  -50,   23,
    0,
};
#define YYTABLESIZE 376
static const short yytable[] = {                         52,
   60,   44,   93,  104,  105,   86,   95,   96,   52,   95,
   96,   64,   91,   92,  108,  109,  110,  112,   88,  137,
   63,   64,  157,   65,   87,   95,   96,   87,   87,   44,
    1,  110,   44,   65,  124,  125,  126,  127,  128,  129,
   57,   57,   67,    5,  122,  123,   89,    5,   63,    5,
    5,    5,   67,    5,    4,  118,  145,    5,    5,   54,
   54,  133,  134,   52,   57,   95,   96,  116,   65,   57,
   29,  148,   57,   82,    5,  150,  120,    5,   66,   67,
    5,  142,   66,   34,   95,   96,    5,   35,   54,   52,
   36,   54,   66,   37,   11,  136,  147,   38,   39,  166,
  160,  161,    4,   12,   52,   13,    4,    3,    4,    4,
    4,   85,    4,   87,   10,  158,    4,    4,   10,   19,
   40,   10,   69,   52,   10,   68,  131,  132,   10,   10,
   40,   40,   69,  170,   26,   68,    4,  172,   20,    4,
   11,   52,    4,   22,   11,   52,    4,   11,   10,    4,
   11,   10,    4,   23,   11,   11,    4,    4,  117,   40,
   89,   29,   40,   89,   89,   82,   82,   82,  146,   29,
   54,  138,   28,    4,   11,   82,   82,   11,   30,    4,
   82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
   21,   82,   32,   82,   82,   82,   63,   64,   82,   70,
   70,   70,   85,   55,   57,   85,   65,   63,   63,   70,
   70,   59,   75,   62,   70,   70,   66,   67,   70,   70,
   70,   70,   70,   70,   78,   70,   77,   70,   70,   70,
   80,   82,   70,   71,   71,   71,   63,   86,   79,   63,
   86,   81,   94,   71,   71,  103,  106,  113,   71,   71,
  114,  135,   71,   71,   71,   71,   71,   71,  138,   71,
  119,   71,   71,   71,  140,  151,   71,   72,   72,   72,
  141,  143,  144,  159,  162,  152,  163,   72,   72,  168,
    9,  171,   72,   72,   24,   18,   72,   72,   72,   72,
   72,   72,   55,   72,   63,   72,   72,   72,   63,   51,
   72,   73,   73,   73,   52,   24,    7,   27,   53,  107,
  121,   73,   73,    0,    0,    0,   73,   73,    0,    0,
   73,   73,   73,   73,   73,   73,    0,   73,    0,   73,
   73,   73,    0,    0,   73,   74,   74,   74,    0,    0,
    0,    0,    0,    0,    0,   74,   74,    0,    0,    0,
   74,   74,    0,    0,   74,   74,   74,   74,   74,   74,
    0,   74,    0,   74,   74,   74,   95,   96,   74,    0,
   97,   98,   99,  100,  101,  102,
};
static const short yycheck[] = {                         25,
   34,  260,   65,  275,  276,   58,  273,  274,   34,  273,
  274,  258,   63,   64,   77,   78,   79,   80,  260,  286,
  260,  268,  286,  258,  284,  273,  274,  287,  288,  288,
  266,   94,  291,  268,   97,   98,   99,  100,  101,  102,
  259,  260,  258,  257,   95,   96,  288,  261,  288,  263,
  264,  265,  268,  267,  288,   89,  119,  271,  272,  259,
  260,  284,  285,   89,  283,  273,  274,  284,  283,  288,
  287,  134,  291,  292,  288,  138,  284,  291,  293,  294,
  294,  115,  258,  257,  273,  274,  270,  261,  288,  115,
  264,  291,  268,  267,  291,  284,  130,  271,  272,  162,
  153,  154,  257,  263,  130,  265,  261,  294,  263,  264,
  265,   57,  267,   59,  257,  149,  271,  272,  261,  288,
  294,  264,  258,  149,  267,  258,  104,  105,  271,  272,
  259,  260,  268,  167,  288,  268,  291,  171,  294,  294,
  257,  167,  257,  294,  261,  171,  261,  264,  291,  264,
  267,  294,  267,  294,  271,  272,  271,  272,  284,  288,
  284,  287,  291,  287,  288,  258,  259,  260,  284,  287,
  293,  287,  285,  288,  291,  268,  269,  294,  288,  294,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  288,  286,  287,  288,  273,  274,  291,  258,
  259,  260,  284,  294,  283,  287,  283,  259,  260,  268,
  269,  283,  283,  294,  273,  274,  293,  294,  277,  278,
  279,  280,  281,  282,  285,  284,  283,  286,  287,  288,
  292,  285,  291,  258,  259,  260,  288,  284,  283,  291,
  287,  290,  283,  268,  269,  268,  294,  293,  273,  274,
  293,  258,  277,  278,  279,  280,  281,  282,  287,  284,
  292,  286,  287,  288,  286,  284,  291,  258,  259,  260,
  290,  288,  288,  286,  269,  293,  259,  268,  269,  284,
  288,  258,  273,  274,  283,  283,  277,  278,  279,  280,
  281,  282,  284,  284,  291,  286,  287,  288,  288,  269,
  291,  258,  259,  260,  258,   13,    4,   19,   26,   76,
   94,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,  286,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,   -1,  286,  287,  288,  273,  274,  291,   -1,
  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"$$1 :",
"outblock : var_decl_part subprog_decl_part $$1 statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"$$2 :",
"var_decl : VAR $$2 id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"subprog_decl : func_decl",
"$$3 :",
"proc_decl : PROCEDURE proc_func_name SEMICOLON $$3 inblock",
"$$4 :",
"$$5 :",
"proc_decl : PROCEDURE proc_func_name $$4 LPAREN id_list RPAREN SEMICOLON $$5 inblock",
"proc_func_name : IDENT",
"$$6 :",
"func_decl : FUNCTION IDENT SEMICOLON $$6 inblock",
"$$7 :",
"$$8 :",
"func_decl : FUNCTION IDENT $$7 LPAREN id_list RPAREN SEMICOLON $$8 inblock",
"$$9 :",
"inblock : var_decl_part $$9 statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : var_name ASSIGN expression",
"$$10 :",
"$$11 :",
"if_statement : IF condition THEN $$10 statement $$11 else_statement",
"else_statement :",
"$$12 :",
"else_statement : ELSE $$12 statement",
"$$13 :",
"$$14 :",
"while_statement : WHILE $$13 condition DO $$14 statement",
"$$15 :",
"$$16 :",
"$$17 :",
"for_statement : FOR IDENT $$15 ASSIGN expression $$16 TO expression $$17 DO statement",
"proc_call_statement : proc_call_name",
"$$18 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$18 RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"$$19 :",
"read_statement : READ LPAREN IDENT LBRACKET expression RBRACKET $$19 RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : func_call",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"var_name : IDENT LBRACKET expression RBRACKET",
"func_call : proc_func_name LPAREN arg_list RPAREN",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
"id_list : id_list COMMA IDENT",
"id_list : id_list COMMA IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 526 "parser.y"


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
#line 486 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 70 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 78 "parser.y"
	{
        insert_decl("main", 0, NULL, VOID);
        /*mainが引数をとるようになるならここにoverwriteの処理を挟む*/
        reg_counter = 1;
        insert_code(Alloca);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        insert_code(Store);
        }
break;
case 3:
#line 87 "parser.y"
	{
        }
break;
case 8:
#line 102 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 104 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 16:
#line 125 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 0);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
break;
case 17:
#line 135 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 18:
#line 141 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, count);
        arity_mode = TRUE;
        }
break;
case 19:
#line 149 "parser.y"
	{
        arity_mode = FALSE;
        /*レジスタの値は返り値分一つ増やしておく*/
        /*reg_counter: 引数(n個),返り値(1個),局所変数(m個), 中身(k個)の順に番号づけされる*/
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
break;
case 20:
#line 158 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 22:
#line 172 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[-1].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[-1].ident, count);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 23:
#line 181 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-3].ident);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }
break;
case 24:
#line 191 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[0].ident, count);
        func_mode = TRUE;
        arity_mode = TRUE;
        }
break;
case 25:
#line 199 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 26:
#line 205 "parser.y"
	{
        func_mode = FALSE;
        Factor x = create_factor_by_name(yystack.l_mark[-7].ident);
        factor_push(x);
        insert_code(Load);
        insert_code(Ret);
        delete_local_symbol();
        ret_type = VOID;
        scope = GLOBAL_VAR;
        }
break;
case 27:
#line 218 "parser.y"
	{
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
                /*記号表のアドレスの更新,新しいlocal varを突っ込む,引数は全てlocalだから上書きオッケー*/
                /*関数呼び出しの時は、返り値用の変数が事前に宣言されていると考える*/
                overwrite_symbol_val(var_num + func_mode, arity_num);
        }
break;
case 40:
#line 261 "parser.y"
	{
        insert_code(Store);
        }
break;
case 41:
#line 267 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 42:
#line 271 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        }
break;
case 44:
#line 279 "parser.y"
	{
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 45:
#line 285 "parser.y"
	{
        insert_code(Label);
        }
break;
case 46:
#line 288 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 47:
#line 299 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
break;
case 48:
#line 305 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 49:
#line 309 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
break;
case 50:
#line 320 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 51:
#line 323 "parser.y"
	{
        insert_code(Store);
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name(yystack.l_mark[-3].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 52:
#line 333 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 53:
#line 339 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name(yystack.l_mark[-9].ident);
        factor_push(x);
        factor_push(x);
        insert_code(Load);
        Factor for_factor = {CONSTANT, "", 1};
        factor_push(for_factor);
        insert_code(Add);
        insert_code(Store);
        insert_code(BrUncond);
        int tmp1 = tmp.element[--tmp.top];
        int tmp2 = tmp.element[--tmp.top];
        int tmp3 = tmp.element[--tmp.top];
        label_push(tmp3);
        label_push(reg_counter);
        label_push(tmp1);
        label_push(tmp2);
        insert_code(Label);
        back_patch();
        }
break;
case 54:
#line 365 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 55:
#line 370 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 59:
#line 386 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 60:
#line 392 "parser.y"
	{
        Symbol *sym = lookup_symbol(yystack.l_mark[-3].ident);
        Factor x = {CONSTANT, "", sym->start};
        factor_push(x);
        insert_code(Sub);
        }
break;
case 61:
#line 397 "parser.y"
	{
        set_read_flag(TRUE);
        insert_code(Sext);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        insert_code(GEP);
        insert_code(Read);
        }
break;
case 62:
#line 408 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 64:
#line 419 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 65:
#line 420 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 66:
#line 421 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 67:
#line 422 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 68:
#line 423 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 69:
#line 424 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 73:
#line 431 "parser.y"
	{insert_code(Add);}
break;
case 74:
#line 432 "parser.y"
	{insert_code(Sub);}
break;
case 76:
#line 437 "parser.y"
	{insert_code(Mult);}
break;
case 77:
#line 438 "parser.y"
	{insert_code(Div);}
break;
case 78:
#line 442 "parser.y"
	{
        insert_code(Load);
        }
break;
case 79:
#line 445 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 82:
#line 454 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 83:
#line 458 "parser.y"
	{
        Symbol *sym = lookup_symbol(yystack.l_mark[-3].ident);
        Factor x = {CONSTANT, "", sym->start};
        factor_push(x);
        insert_code(Sub);
        insert_code(Sext);
        x = create_factor_by_name(yystack.l_mark[-3].ident);
        factor_push(x);
        insert_code(GEP);
        }
break;
case 84:
#line 472 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
        /*create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる*/
        /*関数名と返り値の名前が一緒なのでこれでオケ*/
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
break;
case 85:
#line 484 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 86:
#line 488 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 87:
#line 495 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 88:
#line 502 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
case 89:
#line 509 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 90:
#line 516 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
#line 1185 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
