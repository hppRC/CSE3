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

FILE *fp;
static const char *filename = "result.ll";

static int scope = GLOBAL_VAR;
static int count = 0;
extern reg_counter;
extern ret_type;


Stack tmp = {{}, 0};

int i = 0;
Bool var_mode = FALSE;
Bool arity_mode = FALSE;
Bool func_mode = FALSE;

int var_num = 0;
int arity_num = 0;

Factor tmp1_element[100];
Factor tmp2_element[100];

#line 38 "parser.y"
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
#line 66 "y.tab.c"

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
    0,    5,    1,    2,    2,    6,    6,    9,    7,    3,
    3,   10,   10,   11,   11,   11,   11,   14,   16,   14,
   15,   17,   15,   19,   12,   20,   21,   12,   22,   13,
   23,   24,   13,   25,   18,   26,   26,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   27,   39,   41,   28,
   40,   42,   40,   43,   44,   29,   45,   46,   47,   30,
   31,   49,   31,   33,   34,   50,   34,   35,   32,   38,
   38,   38,   38,   38,   38,   37,   37,   37,   37,   37,
   51,   51,   51,   52,   52,   52,   52,   36,   36,   53,
   48,   48,    8,    8,    8,    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    1,    1,    3,    0,    7,
    3,    0,    7,    0,    5,    0,    0,    9,    0,    5,
    0,    0,    9,    0,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    0,    0,    7,
    0,    0,    3,    0,    0,    6,    0,    0,    0,   11,
    1,    0,    5,    3,    4,    0,    8,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    1,    3,    1,    4,    4,
    1,    3,    1,    6,    3,    8,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    0,    2,    0,   13,   14,   15,   16,
   17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    0,    0,    0,   29,    0,   24,    0,    0,
    0,    0,    0,   54,    0,    0,    3,   38,   39,   40,
   41,   42,   43,   44,   45,   46,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,   37,    0,   57,    0,
    0,    0,   85,    0,   84,    0,    0,    0,   81,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   34,   30,    0,   25,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,    0,   87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   82,   83,   65,    0,   55,   68,    0,    0,   89,   94,
    0,   23,   20,   35,   32,   27,    0,   90,   49,    0,
    0,    0,   63,    0,    0,    0,    0,    0,   66,   56,
   96,   33,   28,    0,   52,   50,    0,    0,    0,   67,
    0,   53,    0,   60,
};
static const short yydgoto[] = {                          2,
    6,   91,   15,   47,   29,    8,    9,   24,   10,   16,
   17,   18,   19,   20,   21,   62,   61,   92,   65,   39,
  166,   63,   37,  165,  125,   68,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   75,   76,   77,  140,  176,
  168,  179,   82,  161,   98,  167,  181,  118,  148,  177,
   78,   79,   80,
};
static const short yysindex[] = {                      -260,
 -284,    0, -267, -225,    0, -231,  -46, -219,    0, -210,
    0, -235, -173, -145,    0, -130,    0,    0,    0,    0,
    0, -225, -120, -111,  -82,  -67,  -78,  -64, -138,  -46,
    0,  -48,  -43,    0,    0,    0,  -31,    0,  -22, -138,
  -28,  -36,  -11,    0,   -2, -190,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -13,    0,  -23,    1,
    2,    9, -225, -210, -225, -210,    0, -257,    0, -148,
 -148,  -36,    0,    8,    0,   80,   26,  -84,    0,    0,
    3,  -36,  -36,  -36,  -36,  -36,    7,   12, -210, -210,
    0,    0, -280,    0,  -61,    0, -138,    4,  -84,  -84,
 -230,  -36, -148, -148,  -36,  -36,  -36,  -36,  -36,  -36,
    0, -148, -148,  -87,   37, -136,  -71,   14, -158,  -71,
   16,   23,  -59,  -55, -138,   18,   27,    0,  -36,    0,
  -25,  -84,  -84,  -71,  -71,  -71,  -71,  -71,  -71, -138,
    0,    0,    0,  -36,    0,    0,  -36,   35,    0,    0,
   32,    0,    0,    0,    0,    0,  -71,    0,    0, -131,
 -138,  -71,    0,   34, -225, -225,   57,   68,    0,    0,
    0,    0,    0,  -36,    0,    0,   44,  -71, -138,    0,
   71,    0, -138,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -200,    0,    0, -191,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -238, -124,   42,    0,    0,   48,   51,   45, -182,
    0,    0,    0, -236, -170,    0,    0,    0,    0, -205,
    0,    0,    0,    0,    0, -161,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -94,
    0,    0, -147,    0, -147,    0,    0,    0,    0,    0,
    0,    0,    0, -107,    0,    0,    0,  -73,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -205,    0,  -38,   -4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -24,   55,    0, -242,
    0,    0,    0,    0,   47,    0,    0,    0,    0,    0,
    0,   30,   64, -246, -180, -171, -166,  -80,  -69, -152,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,    0,    0,    0,
 -152,  -16,    0,    0, -147, -147,    0, -240,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82, -152,    0,
    0,    0, -152,    0,
};
static const short yygindex[] = {                         0,
    0,  345,    0,  -39,    0,    0,  334,   93,    0,    0,
  333,    0,    0,    0,    0,    0,    0,  -60,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -29,  -70,  282,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  263,    0,    0,
  -62,  121,    0,
};
#define YYTABLESIZE 365
static const short yytable[] = {                         57,
   67,  101,   96,  126,   94,    1,   33,   99,  100,    3,
   57,   70,  116,  117,  119,  120,   47,   47,    5,   51,
    4,   70,    5,    5,    5,    5,    5,   25,    5,   26,
   97,  117,    5,    5,  134,  135,  136,  137,  138,  139,
  132,  133,  103,  104,    5,   47,   22,   51,   47,    5,
   51,   21,    5,  130,   69,    5,    4,  128,  157,   11,
    4,    4,    4,    4,    4,   10,    4,   57,   22,   10,
    4,    4,   10,  160,   11,   10,  162,   71,   11,   10,
   10,   11,   69,   23,   11,  154,   73,   71,   11,   11,
    4,   72,   84,    4,   85,   57,   73,   61,   61,   10,
  159,   72,   10,  178,  172,  173,   69,   69,   11,    4,
   57,   11,   19,    4,  103,  104,    4,   18,   40,    4,
   27,  170,   41,    4,    4,   42,   61,  149,   43,   61,
   88,   57,   44,   45,   72,   69,  103,  104,   69,  182,
    4,  103,  104,  184,   73,   74,    4,  146,   28,   57,
   88,   88,   88,   57,  169,   46,   93,   30,   95,   93,
   88,   88,   93,   93,   32,   88,   88,   88,   88,   88,
   88,   88,   88,   88,   88,   33,   88,   75,   88,   88,
   88,  123,  124,   88,   76,   76,   76,   75,   74,   95,
  112,  113,   95,   95,   76,   76,  143,  144,   74,   76,
   76,  103,  104,   76,   76,   76,   76,   76,   76,   36,
   76,   34,   76,   76,   76,   12,   13,   76,   14,   77,
   77,   77,  127,   38,  152,   33,   35,   33,  153,   77,
   77,   33,  141,  142,   77,   77,   70,   71,   77,   77,
   77,   77,   77,   77,   59,   77,   72,   77,   77,   77,
   60,   64,   77,   78,   78,   78,   73,   74,  158,   91,
   66,  147,   91,   78,   78,   69,   87,   92,   78,   78,
   92,   81,   78,   78,   78,   78,   78,   78,   86,   78,
   83,   78,   78,   78,   89,   88,   78,   79,   79,   79,
  102,   90,   85,  111,  145,  129,  114,   79,   79,  121,
  147,  150,   79,   79,  122,  155,   79,   79,   79,   79,
   79,   79,  151,   79,  156,   79,   79,   79,  163,  171,
   79,   80,   80,   80,  164,  174,  175,  180,  183,    9,
   31,   80,   80,   26,   69,   69,   80,   80,   62,   59,
   80,   80,   80,   80,   80,   80,   58,   80,    7,   80,
   80,   80,  103,  104,   80,   31,  105,  106,  107,  108,
  109,  110,   58,  115,  131,
};
static const short yycheck[] = {                         29,
   40,   72,  260,  284,   65,  266,  287,   70,   71,  294,
   40,  258,   83,   84,   85,   86,  259,  260,  257,  260,
  288,  268,  261,  262,  263,  264,  265,  263,  267,  265,
  288,  102,  271,  272,  105,  106,  107,  108,  109,  110,
  103,  104,  273,  274,  270,  288,  283,  288,  291,  288,
  291,  288,  291,  284,  260,  294,  257,   97,  129,  291,
  261,  262,  263,  264,  265,  257,  267,   97,  288,  261,
  271,  272,  264,  144,  257,  267,  147,  258,  261,  271,
  272,  264,  288,  294,  267,  125,  258,  268,  271,  272,
  291,  258,  283,  294,  285,  125,  268,  259,  260,  291,
  140,  268,  294,  174,  165,  166,  259,  260,  291,  257,
  140,  294,  283,  261,  273,  274,  264,  288,  257,  267,
  294,  161,  261,  271,  272,  264,  288,  286,  267,  291,
  292,  161,  271,  272,  283,  288,  273,  274,  291,  179,
  288,  273,  274,  183,  293,  294,  294,  284,  294,  179,
  258,  259,  260,  183,  286,  294,   64,  288,   66,  284,
  268,  269,  287,  288,  285,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  287,  284,  258,  286,  287,
  288,   89,   90,  291,  258,  259,  260,  268,  258,  284,
  275,  276,  287,  288,  268,  269,  284,  285,  268,  273,
  274,  273,  274,  277,  278,  279,  280,  281,  282,  288,
  284,  294,  286,  287,  288,  262,  263,  291,  265,  258,
  259,  260,  284,  288,  284,  287,  294,  287,  284,  268,
  269,  287,  112,  113,  273,  274,  273,  274,  277,  278,
  279,  280,  281,  282,  293,  284,  283,  286,  287,  288,
  294,  283,  291,  258,  259,  260,  293,  294,  284,  284,
  283,  287,  287,  268,  269,  294,  290,  284,  273,  274,
  287,  283,  277,  278,  279,  280,  281,  282,  292,  284,
  283,  286,  287,  288,  283,  285,  291,  258,  259,  260,
  283,  283,  285,  268,  258,  292,  294,  268,  269,  293,
  287,  286,  273,  274,  293,  288,  277,  278,  279,  280,
  281,  282,  290,  284,  288,  286,  287,  288,  284,  286,
  291,  258,  259,  260,  293,  269,  259,  284,  258,  288,
  283,  268,  269,  283,  288,  291,  273,  274,  284,  258,
  277,  278,  279,  280,  281,  282,  269,  284,    4,  286,
  287,  288,  273,  274,  291,   22,  277,  278,  279,  280,
  281,  282,   30,   82,  102,
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
"proc_call_statement : IDENT",
"$$20 :",
"proc_call_statement : IDENT LPAREN arg_list $$20 RPAREN",
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
#line 494 "parser.y"


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
#line 63 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 71 "parser.y"
	{
        insert_decl("main", 0, NULL, VOID);
        reg_counter = 1;
        }
break;
case 8:
#line 89 "parser.y"
	{ var_mode = TRUE; }
break;
case 9:
#line 89 "parser.y"
	{ var_mode = FALSE; }
break;
case 18:
#line 110 "parser.y"
	{ insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 0); }
break;
case 19:
#line 111 "parser.y"
	{
        count = var_num = arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 0);
        arity_mode = TRUE;
        }
break;
case 20:
#line 116 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-4].ident, arity_num);
        }
break;
case 21:
#line 123 "parser.y"
	{ insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, 0); }
break;
case 22:
#line 124 "parser.y"
	{
        count = var_num = arity_num = 0;
        insert_symbol(FUNC_NAME, yystack.l_mark[0].ident, 0);
        arity_mode = TRUE;
        }
break;
case 23:
#line 129 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-4].ident, arity_num);
        }
break;
case 24:
#line 136 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 0);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, VOID);
        reg_counter = count + 1;
        count++;
        }
break;
case 25:
#line 144 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 26:
#line 149 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, count);
        arity_mode = TRUE;
        }
break;
case 27:
#line 155 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, VOID);
        reg_counter = count++ + 1;
        }
break;
case 28:
#line 161 "parser.y"
	{
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 29:
#line 170 "parser.y"
	{
        scope = LOCAL_VAR;
        count = var_num = arity_num = 0;
        ret_type = INT;
        insert_symbol(FUNC_NAME, yystack.l_mark[-1].ident, count);
        insert_symbol(LOCAL_VAR, yystack.l_mark[-1].ident, count);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL, INT);
        reg_counter = count++ + 1;
        }
break;
case 30:
#line 178 "parser.y"
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
#line 188 "parser.y"
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
#line 196 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count++ + 1;
        }
break;
case 33:
#line 201 "parser.y"
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
#line 214 "parser.y"
	{
                for (i = 0; i < var_num + arity_num; i++) tmp1_element[i] = factor_pop();
                for (i = 0; i < var_num + arity_num + func_mode; i++) insert_code(Alloca);
                for (i = 0; i < var_num + arity_num; i++) tmp2_element[i] = factor_pop();

                for (i = var_num + arity_num ; i > var_num; i--) {
                        factor_push(tmp2_element[i-1]);
                        factor_push(tmp1_element[i-1]);
                        insert_code(Store);
                }
                overwrite_symbol_val(var_num + func_mode, arity_num);
        }
break;
case 47:
#line 246 "parser.y"
	{
        insert_code(Store);
        }
break;
case 48:
#line 252 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 49:
#line 256 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        }
break;
case 51:
#line 264 "parser.y"
	{
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 52:
#line 270 "parser.y"
	{
        insert_code(Label);
        }
break;
case 53:
#line 273 "parser.y"
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
#line 284 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
break;
case 55:
#line 290 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 56:
#line 294 "parser.y"
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
#line 305 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 58:
#line 308 "parser.y"
	{
        insert_code(Store);
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        factor_push(create_factor_by_name(yystack.l_mark[-3].ident));
        insert_code(Load);
        }
break;
case 59:
#line 317 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 60:
#line 323 "parser.y"
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
#line 349 "parser.y"
	{;
        factor_push(create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top()));
        insert_code(Proc);
        }
break;
case 62:
#line 353 "parser.y"
	{;
        factor_push(create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top()));
        insert_code(Proc);
        }
break;
case 65:
#line 364 "parser.y"
	{
        set_read_flag(TRUE);
        factor_push(create_factor_by_name(yystack.l_mark[-1].ident));
        insert_code(Read);
        }
break;
case 66:
#line 369 "parser.y"
	{
        Symbol *sym = lookup_symbol(yystack.l_mark[-3].ident);
        Factor x = {CONSTANT, "", sym->start};
        factor_push(x);
        insert_code(Sub);
        }
break;
case 67:
#line 374 "parser.y"
	{
        set_read_flag(TRUE);
        insert_code(Sext);
        factor_push(create_factor_by_name(yystack.l_mark[-5].ident));
        insert_code(GEP);
        insert_code(Read);
        }
break;
case 68:
#line 384 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 70:
#line 395 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 71:
#line 396 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 72:
#line 397 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 73:
#line 398 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 74:
#line 399 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 75:
#line 400 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 79:
#line 407 "parser.y"
	{insert_code(Add);}
break;
case 80:
#line 408 "parser.y"
	{insert_code(Sub);}
break;
case 82:
#line 413 "parser.y"
	{insert_code(Mult);}
break;
case 83:
#line 414 "parser.y"
	{insert_code(Div);}
break;
case 84:
#line 418 "parser.y"
	{ insert_code(Load); }
break;
case 85:
#line 419 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);}
break;
case 88:
#line 427 "parser.y"
	{ factor_push(create_factor_by_name(yystack.l_mark[0].ident)); }
break;
case 89:
#line 428 "parser.y"
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
case 90:
#line 442 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
break;
case 91:
#line 452 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 92:
#line 456 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 93:
#line 463 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 94:
#line 470 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
case 95:
#line 477 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 96:
#line 484 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
#line 1179 "y.tab.c"
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
