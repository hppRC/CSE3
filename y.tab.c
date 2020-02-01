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
   53,   48,   48,    8,    8,    8,    8,
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
    1,    3,    3,    1,    1,    1,    3,    1,    4,    3,
    4,    1,    3,    1,    6,    3,    8,
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
   90,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   82,   83,   65,    0,   55,   68,    0,    0,   89,
   95,    0,   23,   20,   35,   32,   27,    0,   91,   49,
    0,    0,    0,   63,    0,    0,    0,    0,    0,   66,
   56,   97,   33,   28,    0,   52,   50,    0,    0,    0,
   67,    0,   53,    0,   60,
};
static const short yydgoto[] = {                          2,
    6,   91,   15,   47,   29,    8,    9,   24,   10,   16,
   17,   18,   19,   20,   21,   62,   61,   92,   65,   39,
  167,   63,   37,  166,  125,   68,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   75,   76,   77,  141,  177,
  169,  180,   82,  162,   98,  168,  182,  118,  149,  178,
   78,   79,   80,
};
static const short yysindex[] = {                      -260,
 -284,    0, -267, -227,    0, -231,   -5, -180,    0, -195,
    0, -235, -167, -159,    0, -145,    0,    0,    0,    0,
    0, -227, -126, -121, -103,  -95,  -84,  -77, -133,   -5,
    0,  -80,  -49,    0,    0,    0,  -66,    0,  -36, -133,
  -27, -164,  -22,    0,  -11,  -85,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -13,    0,   -9,   15,
    9,   18, -227, -195, -227, -195,    0, -257,    0, -104,
 -104, -164,    0,   10,    0,   80,   34,  -51,    0,    0,
   11, -164, -164, -164, -164, -164,   13,   20, -195, -195,
    0,    0, -280,    0, -210,    0, -133,   23,  -51,  -51,
 -229, -137, -104, -104, -164, -164, -164, -164, -164, -164,
    0, -104, -104,  -33,   61,  -81,   12,   33, -185,   12,
   39,   36, -192,  -25, -133,   40,   41,    0, -164,    0,
    0,  -21,  -51,  -51,   12,   12,   12,   12,   12,   12,
 -133,    0,    0,    0, -164,    0,    0, -164,   43,    0,
    0,   37,    0,    0,    0,    0,    0,   12,    0,    0,
 -109, -133,   12,    0,   45, -227, -227,   65,   76,    0,
    0,    0,    0,    0, -164,    0,    0,   52,   12, -133,
    0,   81,    0, -133,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -200,    0,    0, -191,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -238,  -55,   59,    0,    0,   57,   66,   72, -174,
    0,    0,    0, -236, -139,    0,    0,    0,    0, -206,
    0,    0,    0,    0,    0,  -65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -50,
    0,    0, -146,    0, -146,    0,    0,    0,    0,    0,
    0,    0,    0, -106,    0,    0,    0,  -72,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -206,    0,  -38,   -4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -16,   82,    0, -242,
    0,    0,    0,    0,   68,    0,    0,    0,    0,    0,
    0,    0,   30,   64, -246, -189, -154, -136, -118,  -40,
 -175,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   95,    0,    0,
    0, -175,    7,    0,    0, -146, -146,    0, -240,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  107, -175,
    0,    0,    0, -175,    0,
};
static const short yygindex[] = {                         0,
    0,  363,    0,  -39,    0,    0,  346,   94,    0,    0,
  339,    0,    0,    0,    0,    0,    0,  -60,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -29,  -70,  288,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  269,    0,    0,
  -62,  184,    0,
};
#define YYTABLESIZE 371
static const short yytable[] = {                         57,
   67,  101,   96,  126,   94,    1,   33,   99,  100,    3,
   57,   70,  116,  117,  119,  120,   47,   47,    5,   51,
    4,   70,    5,    5,    5,    5,    5,   25,    5,   26,
   97,  117,    5,    5,  135,  136,  137,  138,  139,  140,
  133,  134,    5,  103,  104,   47,   22,   51,   47,    5,
   51,   21,    5,   69,  130,    5,    4,  128,  158,   11,
    4,    4,    4,    4,    4,   10,    4,   57,   71,   10,
    4,    4,   10,  127,  161,   10,   33,  163,   71,   10,
   10,   69,   11,   69,   69,  155,   11,  103,  104,   11,
    4,  153,   11,    4,   33,   57,   11,   11,   23,   10,
  150,  160,   10,   73,  179,  173,  174,   22,   70,   71,
    4,   57,   69,   73,    4,   69,   11,    4,   72,   11,
    4,   72,  171,   40,    4,    4,   27,   41,   73,   74,
   42,   72,   57,   43,   28,   70,   71,   44,   45,   75,
  183,    4,   30,   19,  185,   72,  131,    4,   18,   75,
   57,   88,   88,   88,   57,   73,   74,   93,   32,   95,
   46,   88,   88,  103,  104,   33,   88,   88,   88,   88,
   88,   88,   88,   88,   88,   88,  170,   88,   72,   88,
   88,   88,  123,  124,   88,   76,   76,   76,   73,   74,
   34,  103,  104,   61,   61,   76,   76,   84,   35,   85,
   76,   76,  147,   36,   76,   76,   76,   76,   76,   76,
   38,   76,   59,   76,   76,   76,   64,   74,   76,   77,
   77,   77,   61,  112,  113,   61,   88,   74,   94,   77,
   77,   94,   94,   96,   77,   77,   96,   96,   77,   77,
   77,   77,   77,   77,   60,   77,   66,   77,   77,   77,
  144,  145,   77,   78,   78,   78,   12,   13,  154,   14,
   81,   33,  159,   78,   78,  148,   69,   92,   78,   78,
   92,   83,   78,   78,   78,   78,   78,   78,   86,   78,
   87,   78,   78,   78,  103,  104,   78,   79,   79,   79,
   93,   89,  102,   93,   85,  142,  143,   79,   79,   88,
   90,  111,   79,   79,  114,  121,   79,   79,   79,   79,
   79,   79,  122,   79,  129,   79,   79,   79,  146,  148,
   79,   80,   80,   80,  151,  152,  164,  156,  157,  165,
  172,   80,   80,  175,  176,  181,   80,   80,  184,   31,
   80,   80,   80,   80,   80,   80,    9,   80,   26,   80,
   80,   80,  103,  104,   80,   69,  105,  106,  107,  108,
  109,  110,   69,   58,   59,   62,    7,   31,   58,  115,
  132,
};
static const short yycheck[] = {                         29,
   40,   72,  260,  284,   65,  266,  287,   70,   71,  294,
   40,  258,   83,   84,   85,   86,  259,  260,  257,  260,
  288,  268,  261,  262,  263,  264,  265,  263,  267,  265,
  288,  102,  271,  272,  105,  106,  107,  108,  109,  110,
  103,  104,  270,  273,  274,  288,  283,  288,  291,  288,
  291,  288,  291,  260,  284,  294,  257,   97,  129,  291,
  261,  262,  263,  264,  265,  257,  267,   97,  258,  261,
  271,  272,  264,  284,  145,  267,  287,  148,  268,  271,
  272,  288,  257,  259,  260,  125,  261,  273,  274,  264,
  291,  284,  267,  294,  287,  125,  271,  272,  294,  291,
  286,  141,  294,  258,  175,  166,  167,  288,  273,  274,
  257,  141,  288,  268,  261,  291,  291,  264,  283,  294,
  267,  258,  162,  257,  271,  272,  294,  261,  293,  294,
  264,  268,  162,  267,  294,  273,  274,  271,  272,  258,
  180,  288,  288,  283,  184,  283,  284,  294,  288,  268,
  180,  258,  259,  260,  184,  293,  294,   64,  285,   66,
  294,  268,  269,  273,  274,  287,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  286,  284,  283,  286,
  287,  288,   89,   90,  291,  258,  259,  260,  293,  294,
  294,  273,  274,  259,  260,  268,  269,  283,  294,  285,
  273,  274,  284,  288,  277,  278,  279,  280,  281,  282,
  288,  284,  293,  286,  287,  288,  283,  258,  291,  258,
  259,  260,  288,  275,  276,  291,  292,  268,  284,  268,
  269,  287,  288,  284,  273,  274,  287,  288,  277,  278,
  279,  280,  281,  282,  294,  284,  283,  286,  287,  288,
  284,  285,  291,  258,  259,  260,  262,  263,  284,  265,
  283,  287,  284,  268,  269,  287,  294,  284,  273,  274,
  287,  283,  277,  278,  279,  280,  281,  282,  292,  284,
  290,  286,  287,  288,  273,  274,  291,  258,  259,  260,
  284,  283,  283,  287,  285,  112,  113,  268,  269,  285,
  283,  268,  273,  274,  294,  293,  277,  278,  279,  280,
  281,  282,  293,  284,  292,  286,  287,  288,  258,  287,
  291,  258,  259,  260,  286,  290,  284,  288,  288,  293,
  286,  268,  269,  269,  259,  284,  273,  274,  258,  283,
  277,  278,  279,  280,  281,  282,  288,  284,  283,  286,
  287,  288,  273,  274,  291,  288,  277,  278,  279,  280,
  281,  282,  291,  269,  258,  284,    4,   22,   30,   82,
  102,
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
"func_call : IDENT LPAREN RPAREN",
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
#line 495 "parser.y"


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
#line 492 "y.tab.c"

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
#line 245 "parser.y"
	{ insert_code(Store); }
break;
case 48:
#line 249 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 49:
#line 253 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        }
break;
case 51:
#line 261 "parser.y"
	{
        label_push(tmp.element[--tmp.top]);
        label_push(reg_counter);
        insert_code(Label);
        back_patch();
        }
break;
case 52:
#line 267 "parser.y"
	{ insert_code(Label); }
break;
case 53:
#line 267 "parser.y"
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
#line 278 "parser.y"
	{
        insert_code(BrUncond);
        tmp.element[tmp.top++] = reg_counter;
        tmp.element[tmp.top++] = reg_counter;
        insert_code(Label);
        }
break;
case 55:
#line 284 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 56:
#line 288 "parser.y"
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
#line 299 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 58:
#line 302 "parser.y"
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
#line 311 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 60:
#line 317 "parser.y"
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
#line 343 "parser.y"
	{;
        factor_push(create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top()));
        insert_code(Proc);
        }
break;
case 62:
#line 347 "parser.y"
	{;
        factor_push(create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top()));
        insert_code(Proc);
        }
break;
case 65:
#line 358 "parser.y"
	{
        set_read_flag(TRUE);
        factor_push(create_factor_by_name(yystack.l_mark[-1].ident));
        insert_code(Read);
        }
break;
case 66:
#line 363 "parser.y"
	{
        Symbol *sym = lookup_symbol(yystack.l_mark[-3].ident);
        Factor x = {CONSTANT, "", sym->start};
        factor_push(x);
        insert_code(Sub);
        }
break;
case 67:
#line 368 "parser.y"
	{
        set_read_flag(TRUE);
        insert_code(Sext);
        factor_push(create_factor_by_name(yystack.l_mark[-5].ident));
        insert_code(GEP);
        insert_code(Read);
        }
break;
case 68:
#line 378 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 70:
#line 389 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 71:
#line 390 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 72:
#line 391 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 73:
#line 392 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 74:
#line 393 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 75:
#line 394 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 79:
#line 401 "parser.y"
	{insert_code(Add);}
break;
case 80:
#line 402 "parser.y"
	{insert_code(Sub);}
break;
case 82:
#line 407 "parser.y"
	{insert_code(Mult);}
break;
case 83:
#line 408 "parser.y"
	{insert_code(Div);}
break;
case 84:
#line 412 "parser.y"
	{ insert_code(Load); }
break;
case 85:
#line 413 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);}
break;
case 88:
#line 421 "parser.y"
	{ factor_push(create_factor_by_name(yystack.l_mark[0].ident)); }
break;
case 89:
#line 422 "parser.y"
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
#line 436 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        
        }
break;
case 91:
#line 443 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
        x.type = FUNC_NAME;
        factor_push(x);
        insert_code(Func);
        }
break;
case 92:
#line 453 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 93:
#line 457 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        }
break;
case 94:
#line 464 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 95:
#line 471 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
case 96:
#line 478 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 97:
#line 485 "parser.y"
	{
        if (var_mode && scope == LOCAL_VAR) var_num++;
        else if (arity_mode) arity_num++;
        insert_array_symbol(scope, yystack.l_mark[-5].ident, count++, yystack.l_mark[-3].num, yystack.l_mark[-1].num);
        Factor x = create_factor_by_name(yystack.l_mark[-5].ident);
        factor_push(x);
        }
break;
#line 1187 "y.tab.c"
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
