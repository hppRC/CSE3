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
   35,   25,   37,   39,   26,   38,   40,   38,   41,   42,
   27,   43,   44,   28,   29,   46,   29,    2,   31,   32,
   47,   32,   33,   30,   36,   36,   36,   36,   36,   36,
   34,   34,   34,   34,   34,   48,   48,   48,   49,   49,
   49,   49,   50,   50,   51,   45,   45,   10,   10,   10,
   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    0,    5,    0,    0,    9,
    1,    0,    5,    0,    0,    9,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    7,    0,    0,    7,    0,    0,    3,    0,    0,
    6,    0,    0,   10,    1,    0,    5,    1,    3,    4,
    0,    8,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    1,    3,    1,    4,    4,    1,    3,    1,    6,    3,
    8,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    2,    0,   13,   14,   15,    0,    0,
    0,    0,   21,    0,    0,    0,    6,    0,    0,   22,
    0,   16,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    3,   31,   32,   33,   34,   35,   36,   37,   38,
   39,   12,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,    0,   80,    0,    0,    0,    0,    0,
   76,   79,   81,    0,    0,    0,    0,    0,    0,    0,
    0,   27,   23,    0,   17,    0,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   77,   78,   60,    0,   50,   63,   41,    0,    0,
   89,    0,   28,   25,   19,    0,   84,   85,   44,    0,
    0,    0,    0,   57,    0,    0,    0,    0,    0,   61,
   51,    0,   91,   26,   20,    0,   47,   45,    0,    0,
    0,    0,   62,    0,   48,   54,
};
static const short yydgoto[] = {                          2,
   67,   41,    6,   82,   14,   42,   25,    8,    9,   21,
   10,   15,   16,   17,   18,   83,   57,   33,  157,   55,
   31,  156,  115,   60,   43,   44,   45,   46,   47,   48,
   49,   50,   51,   68,  152,   69,  131,  168,  159,  172,
   75,  151,  146,  171,  112,  140,  169,   70,   71,   72,
   73,
};
static const short yysindex[] = {                      -234,
 -246,    0, -236, -210,    0, -225, -104, -217,    0, -198,
    0, -173, -168,    0, -178,    0,    0,    0, -210, -153,
 -143,  -99,    0,  -95, -118, -104,    0, -124, -100,    0,
  -82,    0,  -75, -118,  -85, -268,  -69,    0,  -48, -271,
  -41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -67,  -64, -210, -198, -210, -198,    0, -258,
  -65, -270, -270, -268,    0,  -57,  -35,   90,  -25, -248,
    0,    0,    0,  -39, -268, -268, -268, -268, -268,  -36,
  -32,    0,    0, -119,    0,  -84,    0, -118, -268, -248,
 -248, -191, -268, -268, -270, -270, -268, -268, -268, -268,
 -268, -268,    0, -270, -270, -194,    4, -179, -266, -107,
 -107,  -19,  -17,  -18, -118,  -15,  -12,    0, -107,    0,
 -264,  -74, -248, -248, -107, -107, -107, -107, -107, -107,
 -118,    0,    0,    0, -268,    0,    0,    0, -268,  -13,
    0,  -16,    0,    0,    0,    9,    0,    0,    0, -201,
 -118,  -11, -107,    0,   -4, -210, -210, -268,   30,    0,
    0, -268,    0,    0,    0, -107,    0,    0,    7, -107,
   37, -118,    0, -118,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -202,    0,    0, -158,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -214, -159,
    8,   18,    0,   19,   12, -149,    0,    0,    0,    0,
    0,    0,    0, -257,    0,    0,    0,    0,    0, -172,
 -224,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -132, -137,    0, -137,    0,    0,    0,
    0,    0,    0,    0,    0,  -96,    0,    0,    0,  -62,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -257,    0,  -28,
    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -89,
  -50,   20,    0,    0,   17,    0,    0,    0,   38,    0,
    0,    0,   40,   74, -212, -190, -127, -121, -110, -108,
  -55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -55,    0,  -40,    0,    0, -137, -137,    0, -184,    0,
    0,    0,    0,    0,    0,   48,    0,    0,    0,  -21,
    0,  -55,    0,  -55,    0,    0,
};
static const short yygindex[] = {                         0,
  297,    0,    0,  307,    0,  -34,    0,    0,  293,   28,
    0,    0,  289,    0,    0,  -56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -60,    0,  241,    0,    0,    0,    0,
    0,    0,    0,    0,  229,    0,    0,  -51,   70,    0,
    0,
};
#define YYTABLESIZE 372
static const short yytable[] = {                         59,
   85,   87,   64,   92,   62,   63,   95,   96,   95,   96,
   90,   91,   64,   77,   64,  108,  109,  110,  111,  138,
   78,  147,   65,   66,   65,   66,  104,  105,  119,   88,
   64,    1,  121,  111,   55,   55,  125,  126,  127,  128,
  129,  130,    5,  123,  124,   65,    5,    3,    5,    5,
    5,    4,    5,  118,    4,   65,    5,    5,    4,    5,
    4,    4,    4,   55,    4,   11,   55,   66,    4,    4,
   19,   95,   96,    5,  150,   46,    5,   66,  153,    5,
  143,   95,   96,   84,  160,   86,   58,   58,    4,  134,
  135,    4,  120,   95,   96,   20,  149,  166,   10,  164,
  165,  170,   10,   46,  137,   10,   46,   11,   10,   26,
   58,   11,   10,   10,   11,   58,  161,   11,   58,    4,
   22,   11,   11,    4,   88,   23,    4,   88,   88,    4,
   68,   28,   10,    4,    4,   10,   67,  175,   34,  176,
   68,   11,   35,   29,   11,   36,   67,   70,   37,   69,
    4,   90,   38,   39,   90,   90,    4,   70,   12,   69,
   13,   83,   83,   83,  116,   95,   96,   29,   53,   40,
   40,   83,   83,  132,  133,   40,   83,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   21,   83,   30,   83,
   83,   83,   32,   54,   83,   71,   71,   71,   40,  117,
   56,   40,   29,   64,   64,   71,   71,   58,   61,  148,
   71,   71,  139,   74,   71,   71,   71,   71,   71,   71,
   81,   71,   80,   71,   71,   71,   89,   93,   71,   72,
   72,   72,   64,   86,   76,   64,   86,   42,   42,   72,
   72,   79,  103,   87,   72,   72,   87,   94,   72,   72,
   72,   72,   72,   72,  106,   72,  113,   72,   72,   72,
  114,  136,   72,   73,   73,   73,   42,  139,  141,   42,
  154,  142,  144,   73,   73,  145,  155,  158,   73,   73,
  162,  163,   73,   73,   73,   73,   73,   73,  167,   73,
  173,   73,   73,   73,  174,    9,   73,   74,   74,   74,
   24,   18,   64,   56,   64,   53,   52,   74,   74,   24,
    7,   27,   74,   74,   52,  107,   74,   74,   74,   74,
   74,   74,  122,   74,    0,   74,   74,   74,    0,    0,
   74,   75,   75,   75,    0,    0,    0,    0,    0,    0,
    0,   75,   75,    0,    0,    0,   75,   75,    0,    0,
   75,   75,   75,   75,   75,   75,    0,   75,    0,   75,
   75,   75,   95,   96,   75,    0,   97,   98,   99,  100,
  101,  102,
};
static const short yycheck[] = {                         34,
   57,  260,  260,   64,  273,  274,  273,  274,  273,  274,
   62,   63,  283,  285,  283,   76,   77,   78,   79,  286,
  292,  286,  293,  294,  293,  294,  275,  276,   89,  288,
  288,  266,   93,   94,  259,  260,   97,   98,   99,  100,
  101,  102,  257,   95,   96,  258,  261,  294,  263,  264,
  265,  288,  267,   88,  257,  268,  271,  272,  261,  270,
  263,  264,  265,  288,  267,  291,  291,  258,  271,  272,
  288,  273,  274,  288,  135,  260,  291,  268,  139,  294,
  115,  273,  274,   56,  286,   58,  259,  260,  291,  284,
  285,  294,  284,  273,  274,  294,  131,  158,  257,  156,
  157,  162,  261,  288,  284,  264,  291,  257,  267,  288,
  283,  261,  271,  272,  264,  288,  151,  267,  291,  257,
  294,  271,  272,  261,  284,  294,  264,  287,  288,  267,
  258,  285,  291,  271,  272,  294,  258,  172,  257,  174,
  268,  291,  261,  287,  294,  264,  268,  258,  267,  258,
  288,  284,  271,  272,  287,  288,  294,  268,  263,  268,
  265,  258,  259,  260,  284,  273,  274,  287,  293,  259,
  260,  268,  269,  104,  105,  294,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  288,  286,
  287,  288,  288,  294,  291,  258,  259,  260,  288,  284,
  283,  291,  287,  259,  260,  268,  269,  283,  294,  284,
  273,  274,  287,  283,  277,  278,  279,  280,  281,  282,
  285,  284,  290,  286,  287,  288,  292,  285,  291,  258,
  259,  260,  288,  284,  283,  291,  287,  259,  260,  268,
  269,  283,  268,  284,  273,  274,  287,  283,  277,  278,
  279,  280,  281,  282,  294,  284,  293,  286,  287,  288,
  293,  258,  291,  258,  259,  260,  288,  287,  286,  291,
  284,  290,  288,  268,  269,  288,  293,  269,  273,  274,
  292,  286,  277,  278,  279,  280,  281,  282,  259,  284,
  284,  286,  287,  288,  258,  288,  291,  258,  259,  260,
  283,  283,  291,  284,  288,  258,  269,  268,  269,   13,
    4,   19,  273,  274,   26,   75,  277,  278,  279,  280,
  281,  282,   94,  284,   -1,  286,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,  286,
  287,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
  281,  282,
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
"assignment_statement : IDENT ASSIGN expression",
"$$10 :",
"assignment_statement : IDENT LBRACKET expression RBRACKET $$10 ASSIGN expression",
"$$11 :",
"$$12 :",
"if_statement : IF condition THEN $$11 statement $$12 else_statement",
"else_statement :",
"$$13 :",
"else_statement : ELSE $$13 statement",
"$$14 :",
"$$15 :",
"while_statement : WHILE $$14 condition DO $$15 statement",
"$$16 :",
"$$17 :",
"for_statement : FOR IDENT ASSIGN expression $$16 TO expression $$17 DO statement",
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
#line 534 "parser.y"


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
#line 489 "y.tab.c"

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
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        /*mainが引数をとるようになるならここにoverwriteの処理を挟む*/
        reg_counter = 1;
        insert_code(Alloca);
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
        count = 0;
        var_num = 0;
        arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[-1].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[-1].ident, count);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 23:
#line 183 "parser.y"
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
#line 193 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[0].ident, count);
        func_mode = TRUE;
        arity_mode = TRUE;
        }
break;
case 25:
#line 203 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 26:
#line 209 "parser.y"
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
#line 222 "parser.y"
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
                        factor_push(tmp1_element[i-1]);
                        factor_push(tmp2_element[i-1]);
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
#line 265 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 41:
#line 270 "parser.y"
	{
        }
break;
case 42:
#line 271 "parser.y"
	{
        insert_code(Sext);
        Factor x = create_factor_by_name(yystack.l_mark[-6].ident);
        factor_push(x);
        insert_code(GEP);
        insert_code(Store);
        }
break;
case 43:
#line 281 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 44:
#line 285 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        }
break;
case 46:
#line 293 "parser.y"
	{
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 47:
#line 299 "parser.y"
	{
        insert_code(Label);
        }
break;
case 48:
#line 302 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 49:
#line 313 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
break;
case 50:
#line 319 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 51:
#line 323 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
break;
case 52:
#line 334 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        factor_push(x);
        insert_code(Load);
        }
break;
case 53:
#line 345 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 54:
#line 351 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        Factor x = create_factor_by_name(yystack.l_mark[-8].ident);
        factor_push(x);
        insert_code(Load);
        Factor for_factor = {CONSTANT, "", 1};
        factor_push(for_factor);
        insert_code(Add);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        label_push(tmp.element[--tmp.top]);
        label_push(tmp.element[--tmp.top]);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
break;
case 55:
#line 374 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 56:
#line 379 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 60:
#line 395 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 61:
#line 401 "parser.y"
	{
        Factor x = {CONSTANT, "", 1};
        factor_push(x);
        insert_code(Sub);
        }
break;
case 62:
#line 405 "parser.y"
	{
        set_read_flag(TRUE);
        insert_code(Sext);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        insert_code(GEP);
        insert_code(Read);
        }
break;
case 63:
#line 416 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 65:
#line 427 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 66:
#line 428 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 67:
#line 429 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 68:
#line 430 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 69:
#line 431 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 70:
#line 432 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 74:
#line 439 "parser.y"
	{insert_code(Add);}
break;
case 75:
#line 440 "parser.y"
	{insert_code(Sub);}
break;
case 77:
#line 445 "parser.y"
	{insert_code(Mult);}
break;
case 78:
#line 446 "parser.y"
	{insert_code(Div);}
break;
case 80:
#line 451 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 83:
#line 460 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 84:
#line 465 "parser.y"
	{
        Factor x = {CONSTANT, "", 1};
        factor_push(x);
        insert_code(Sub);
        insert_code(Sext);
        x = create_factor_by_name(yystack.l_mark[-3].ident);
        factor_push(x);
        insert_code(GEP);
        insert_code(Load);
        }
break;
case 85:
#line 478 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
        /*create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる*/
        /*関数名と返り値の名前が一緒なのでこれでオケ*/
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
break;
case 86:
#line 490 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 87:
#line 495 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 88:
#line 503 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 89:
#line 510 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
case 90:
#line 517 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 91:
#line 524 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
#line 1196 "y.tab.c"
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
