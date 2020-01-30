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
    0,    6,    2,    3,    3,    7,    7,   10,    8,    4,
    4,   11,   11,   12,   12,   12,   12,   15,   17,   15,
   16,   18,   16,   20,   13,   21,   22,   13,   23,   14,
   24,   25,   14,   26,   19,   27,   27,    5,    5,    5,
    5,    5,    5,    5,    5,    5,   28,   40,   42,   29,
   41,   43,   41,   44,   45,   30,   46,   47,   48,   31,
   32,   50,   32,    1,   34,   35,   51,   35,   36,   33,
   39,   39,   39,   39,   39,   39,   38,   38,   38,   38,
   38,   52,   52,   52,   53,   53,   53,   53,   37,   37,
   54,   49,   49,    9,    9,    9,    9,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    1,    1,    3,    0,    7,
    3,    0,    7,    0,    5,    0,    0,    9,    0,    5,
    0,    0,    9,    0,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    0,    0,    7,
    0,    0,    3,    0,    0,    6,    0,    0,    0,   11,
    1,    0,    5,    1,    3,    4,    0,    8,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    2,    3,
    3,    1,    3,    3,    1,    1,    1,    3,    1,    4,
    4,    1,    3,    1,    6,    3,    8,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    0,    2,    0,   13,   14,   15,   16,
   17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    0,    0,    0,   29,    0,   24,    0,    0,
    0,    0,    0,   54,    0,    0,    0,    3,   38,   39,
   40,   41,   42,   43,   44,   45,   46,    0,   12,    0,
    0,    0,    0,    0,    0,    0,    0,   37,    0,   57,
    0,    0,    0,   86,    0,   85,    0,    0,    0,   82,
   87,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   34,   30,    0,   25,    0,   65,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   48,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,
   88,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   83,   84,   66,    0,   55,   69,   90,    0,    0,
   95,    0,   23,   20,   35,   32,   27,    0,   91,   49,
    0,    0,    0,   63,    0,    0,    0,    0,    0,   67,
   56,   97,   33,   28,    0,   52,   50,    0,    0,    0,
   68,    0,   53,    0,   60,
};
static const short yydgoto[] = {                          2,
   47,    6,   92,   15,   48,   29,    8,    9,   24,   10,
   16,   17,   18,   19,   20,   21,   63,   62,   93,   66,
   39,  167,   64,   37,  166,  126,   69,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   76,   77,   78,  141,
  177,  169,  180,   83,  162,   99,  168,  182,  120,  150,
  178,   79,   80,   81,
};
static const short yysindex[] = {                      -259,
 -248,    0, -227, -200,    0, -206,   29, -174,    0, -175,
    0, -234, -147, -144,    0, -111,    0,    0,    0,    0,
    0, -200, -119, -108,  -95,  -83, -105,  -93, -137,   29,
    0,  -67,  -61,    0,    0,    0,  -51,    0,  -49, -137,
  -47,  -56,  -32,    0,  -31,  -40,  -11,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -34,    0,  -23,
   -6,   -2,    2, -200, -175, -200, -175,    0, -256,    0,
 -281, -281,  -56,    0, -187,    0,   80,   27, -253,    0,
    0,   -8,  -56,  -56,  -56,  -56,  -56,    8,   20, -175,
 -175,    0,    0, -279,    0,  -25,    0, -137,   14, -253,
 -253, -229,  -56, -281, -281,  -56,  -56,  -56,  -56,  -56,
  -56,    0, -281, -281, -126,   57, -135, -157, -109,   32,
 -109,   34,   35,  -21,  -16, -137,   38,   39,    0,  -56,
    0,    9, -253, -253, -109, -109, -109, -109, -109, -109,
 -137,    0,    0,    0,  -56,    0,    0,    0,  -56,   44,
    0,   36,    0,    0,    0,    0,    0, -109,    0,    0,
 -130, -137, -109,    0,   45, -200, -200,   61,   75,    0,
    0,    0,    0,    0,  -56,    0,    0,   51, -109, -137,
    0,   78,    0, -137,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -199,    0,    0, -190,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -237,  -59,   52,    0,    0,   56,   66,   65, -181,
    0,    0,    0, -235, -194,    0,    0,    0,    0, -204,
    0,    0,    0,    0,    0,  -99, -241,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -27,    0,    0, -146,    0, -146,    0,    0,    0,    0,
    0,    0,    0,    0, -106,    0,    0,    0,  -72,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -204,    0,  -38,
   -4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   13,   63,
 -160,    0,    0,    0,    0,   76,    0,    0,    0,    0,
    0,    0,   30,   64, -180, -165, -136, -122,  -64,  -55,
 -151,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   94,    0,    0,
    0, -151,   18,    0,    0, -146, -146,    0, -239,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  107, -151,
    0,    0,    0, -151,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  362,    0,  -39,    0,    0,  345,  133,    0,
    0,  338,    0,    0,    0,    0,    0,    0,  -60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -29,  -70,  286,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  267,    0,
    0,  -62,   77,    0,
};
#define YYTABLESIZE 370
static const short yytable[] = {                         58,
   68,   73,  102,   97,  127,   95,    1,   33,  100,  101,
   58,   74,   75,  117,  118,  119,  121,   61,   61,    5,
   51,  113,  114,    5,    5,    5,    5,    5,   25,    5,
   26,   98,  119,    5,    5,  135,  136,  137,  138,  139,
  140,  133,  134,  104,  105,    3,   61,   22,   51,   61,
    5,   51,   21,    5,  131,   70,    5,    4,  129,  158,
    4,    4,    4,    4,    4,    4,   10,    4,   58,    5,
   10,    4,    4,   10,  161,   11,   10,   71,  163,   11,
   10,   10,   11,   70,   11,   11,  155,   71,   19,   11,
   11,    4,   72,   18,    4,  103,   58,   85,   47,   47,
   10,  160,   72,   10,  179,  173,  174,   70,   70,   11,
    4,   58,   11,   22,    4,  104,  105,    4,   23,   40,
    4,   74,  171,   41,    4,    4,   42,   47,  148,   43,
   47,   74,   58,   44,   45,   73,   70,  104,  105,   70,
  183,    4,  104,  105,  185,   73,   27,    4,  147,   28,
   58,   89,   89,   89,   58,  170,   46,  144,  145,   64,
   64,   89,   89,  104,  105,   32,   89,   89,   89,   89,
   89,   89,   89,   89,   89,   89,   30,   89,   33,   89,
   89,   89,   36,   64,   89,   77,   77,   77,   64,  142,
  143,   64,   89,   76,   38,   77,   77,   94,   34,   96,
   77,   77,   75,   76,   77,   77,   77,   77,   77,   77,
   35,   77,   75,   77,   77,   77,   71,   72,   77,   78,
   78,   78,  124,  125,   94,   60,   73,   94,   94,   78,
   78,   65,   61,   67,   78,   78,   74,   75,   78,   78,
   78,   78,   78,   78,   85,   78,   70,   78,   78,   78,
   82,   84,   78,   79,   79,   79,   96,   87,  128,   96,
   96,   33,  153,   79,   79,   33,   88,  154,   79,   79,
   33,   86,   79,   79,   79,   79,   79,   79,   89,   79,
   90,   79,   79,   79,   91,  115,   79,   80,   80,   80,
   12,   13,  159,   14,  112,  149,   92,   80,   80,   92,
  122,   93,   80,   80,   93,  130,   80,   80,   80,   80,
   80,   80,  123,   80,  146,   80,   80,   80,  149,  151,
   80,   81,   81,   81,  152,  156,  157,  164,  165,  175,
  172,   81,   81,  176,  181,  184,   81,   81,   31,    9,
   81,   81,   81,   81,   81,   81,   62,   81,   26,   81,
   81,   81,  104,  105,   81,   70,  106,  107,  108,  109,
  110,  111,   58,   70,   59,    7,   31,   59,  116,  132,
};
static const short yycheck[] = {                         29,
   40,  283,   73,  260,  284,   66,  266,  287,   71,   72,
   40,  293,  294,   84,   85,   86,   87,  259,  260,  257,
  260,  275,  276,  261,  262,  263,  264,  265,  263,  267,
  265,  288,  103,  271,  272,  106,  107,  108,  109,  110,
  111,  104,  105,  273,  274,  294,  288,  283,  288,  291,
  288,  291,  288,  291,  284,  260,  294,  257,   98,  130,
  288,  261,  262,  263,  264,  265,  257,  267,   98,  270,
  261,  271,  272,  264,  145,  257,  267,  258,  149,  261,
  271,  272,  264,  288,  291,  267,  126,  268,  283,  271,
  272,  291,  258,  288,  294,  283,  126,  285,  259,  260,
  291,  141,  268,  294,  175,  166,  167,  259,  260,  291,
  257,  141,  294,  288,  261,  273,  274,  264,  294,  257,
  267,  258,  162,  261,  271,  272,  264,  288,  286,  267,
  291,  268,  162,  271,  272,  258,  288,  273,  274,  291,
  180,  288,  273,  274,  184,  268,  294,  294,  284,  294,
  180,  258,  259,  260,  184,  286,  294,  284,  285,  259,
  260,  268,  269,  273,  274,  285,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  288,  284,  287,  286,
  287,  288,  288,  283,  291,  258,  259,  260,  288,  113,
  114,  291,  292,  258,  288,  268,  269,   65,  294,   67,
  273,  274,  258,  268,  277,  278,  279,  280,  281,  282,
  294,  284,  268,  286,  287,  288,  273,  274,  291,  258,
  259,  260,   90,   91,  284,  293,  283,  287,  288,  268,
  269,  283,  294,  283,  273,  274,  293,  294,  277,  278,
  279,  280,  281,  282,  285,  284,  294,  286,  287,  288,
  283,  283,  291,  258,  259,  260,  284,  292,  284,  287,
  288,  287,  284,  268,  269,  287,  290,  284,  273,  274,
  287,  283,  277,  278,  279,  280,  281,  282,  285,  284,
  283,  286,  287,  288,  283,  294,  291,  258,  259,  260,
  262,  263,  284,  265,  268,  287,  284,  268,  269,  287,
  293,  284,  273,  274,  287,  292,  277,  278,  279,  280,
  281,  282,  293,  284,  258,  286,  287,  288,  287,  286,
  291,  258,  259,  260,  290,  288,  288,  284,  293,  269,
  286,  268,  269,  259,  284,  258,  273,  274,  283,  288,
  277,  278,  279,  280,  281,  282,  284,  284,  283,  286,
  287,  288,  273,  274,  291,  291,  277,  278,  279,  280,
  281,  282,  269,  288,  258,    4,   22,   30,   83,  103,
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
"subprog_decl : forward_proc_decl",
"subprog_decl : forward_func_decl",
"forward_proc_decl : FORWARD PROCEDURE IDENT",
"$$3 :",
"forward_proc_decl : FORWARD PROCEDURE IDENT $$3 LPAREN id_list RPAREN",
"forward_func_decl : FORWARD FUNCTION IDENT",
"$$4 :",
"forward_func_decl : FORWARD FUNCTION IDENT $$4 LPAREN id_list RPAREN",
"$$5 :",
"proc_decl : PROCEDURE IDENT SEMICOLON $$5 inblock",
"$$6 :",
"$$7 :",
"proc_decl : PROCEDURE IDENT $$6 LPAREN id_list RPAREN SEMICOLON $$7 inblock",
"$$8 :",
"func_decl : FUNCTION IDENT SEMICOLON $$8 inblock",
"$$9 :",
"$$10 :",
"func_decl : FUNCTION IDENT $$9 LPAREN id_list RPAREN SEMICOLON $$10 inblock",
"$$11 :",
"inblock : var_decl_part $$11 statement",
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
"$$12 :",
"$$13 :",
"if_statement : IF condition THEN $$12 statement $$13 else_statement",
"else_statement :",
"$$14 :",
"else_statement : ELSE $$14 statement",
"$$15 :",
"$$16 :",
"while_statement : WHILE $$15 condition DO $$16 statement",
"$$17 :",
"$$18 :",
"$$19 :",
"for_statement : FOR IDENT $$17 ASSIGN expression $$18 TO expression $$19 DO statement",
"proc_call_statement : proc_call_name",
"$$20 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$20 RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"$$21 :",
"read_statement : READ LPAREN IDENT LBRACKET expression RBRACKET $$21 RPAREN",
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
"func_call : IDENT LPAREN arg_list RPAREN",
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
#line 549 "parser.y"


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
#line 496 "y.tab.c"

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
        }
break;
case 8:
#line 97 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 99 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 18:
#line 122 "parser.y"
	{
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 0);
        }
break;
case 19:
#line 125 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 0);
        arity_mode = TRUE;
        }
break;
case 20:
#line 131 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-4].ident, arity_num);
        }
break;
case 21:
#line 138 "parser.y"
	{
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, 0);
        }
break;
case 22:
#line 141 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, 0);
        arity_mode = TRUE;
        }
break;
case 23:
#line 147 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-4].ident, arity_num);
        }
break;
case 24:
#line 154 "parser.y"
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
case 25:
#line 164 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 26:
#line 169 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, count);
        arity_mode = TRUE;
        }
break;
case 27:
#line 177 "parser.y"
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
case 28:
#line 186 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 29:
#line 195 "parser.y"
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
case 30:
#line 204 "parser.y"
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
case 31:
#line 214 "parser.y"
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
case 32:
#line 222 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 33:
#line 228 "parser.y"
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
case 34:
#line 241 "parser.y"
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
case 47:
#line 284 "parser.y"
	{
        insert_code(Store);
        }
break;
case 48:
#line 290 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 49:
#line 294 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        }
break;
case 51:
#line 302 "parser.y"
	{
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 52:
#line 308 "parser.y"
	{
        insert_code(Label);
        }
break;
case 53:
#line 311 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 54:
#line 322 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
break;
case 55:
#line 328 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 56:
#line 332 "parser.y"
	{
        insert_code(BrUncond);
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        label_push(tmp.element[--tmp.top]);
        insert_code(Label);
        back_patch();
        }
break;
case 57:
#line 343 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 58:
#line 346 "parser.y"
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
case 59:
#line 356 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 60:
#line 362 "parser.y"
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
case 61:
#line 388 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 62:
#line 393 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 66:
#line 409 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 67:
#line 415 "parser.y"
	{
        Symbol *sym = lookup_symbol(yystack.l_mark[-3].ident);
        Factor x = {CONSTANT, "", sym->start};
        factor_push(x);
        insert_code(Sub);
        }
break;
case 68:
#line 420 "parser.y"
	{
        set_read_flag(TRUE);
        insert_code(Sext);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        insert_code(GEP);
        insert_code(Read);
        }
break;
case 69:
#line 431 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 71:
#line 442 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 72:
#line 443 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 73:
#line 444 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 74:
#line 445 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 75:
#line 446 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 76:
#line 447 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 80:
#line 454 "parser.y"
	{insert_code(Add);}
break;
case 81:
#line 455 "parser.y"
	{insert_code(Sub);}
break;
case 83:
#line 460 "parser.y"
	{insert_code(Mult);}
break;
case 84:
#line 461 "parser.y"
	{insert_code(Div);}
break;
case 85:
#line 465 "parser.y"
	{
        insert_code(Load);
        }
break;
case 86:
#line 468 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 89:
#line 477 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 90:
#line 481 "parser.y"
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
case 91:
#line 495 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
        /*create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる*/
        /*関数名と返り値の名前が一緒なのでこれでオケ*/
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
break;
case 92:
#line 507 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 93:
#line 511 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 94:
#line 518 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 95:
#line 525 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
case 96:
#line 532 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 97:
#line 539 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
#line 1230 "y.tab.c"
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
