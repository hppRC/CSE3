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
int tmp;
int tmp1,tmp2, tmp3;

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

#line 45 "parser.y"
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
#line 73 "y.tab.c"

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
   25,   36,   38,   26,   37,   39,   37,   40,   41,   27,
   42,   43,   28,   29,   45,   29,    2,   31,   32,   32,
   33,   30,   35,   35,   35,   35,   35,   35,   34,   34,
   34,   34,   34,   46,   46,   46,   47,   47,   47,   47,
   48,   48,   49,   44,   44,   10,   10,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    1,    0,    5,    0,    0,    9,
    1,    0,    5,    0,    0,    9,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    6,    0,    0,    7,    0,    0,    3,    0,    0,    6,
    0,    0,   10,    1,    0,    5,    1,    3,    4,    7,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    1,    3,
    1,    4,    4,    1,    3,    1,    6,    3,    8,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    0,    2,    0,   13,   14,   15,    0,    0,
    0,    0,   21,    0,    0,    0,    6,    0,    0,   22,
    0,   16,    0,    0,    0,    0,    0,   48,    0,    0,
    0,    3,   31,   32,   33,   34,   35,   36,   37,   38,
   39,   12,    0,    0,    0,    0,    0,    0,   30,    0,
    0,    0,    0,    0,   78,    0,    0,    0,    0,    0,
   74,   77,   79,    0,    0,    0,    0,    0,    0,    0,
    0,   27,   23,    0,   17,    0,   58,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   75,   76,   59,    0,   49,   61,    0,    0,    0,
   87,    0,   28,   25,   19,    0,   82,   83,   43,    0,
    0,    0,    0,   56,    0,    0,    0,    0,    0,    0,
   50,    0,   89,   26,   20,    0,   46,   44,   60,    0,
    0,    0,   47,   53,
};
static const short yydgoto[] = {                          2,
   67,   41,    6,   82,   14,   42,   25,    8,    9,   21,
   10,   15,   16,   17,   18,   83,   57,   33,  157,   55,
   31,  156,  115,   60,   43,   44,   45,   46,   47,   48,
   49,   50,   51,   68,   69,  131,  168,  159,  171,   75,
  151,  146,  170,  112,  140,   70,   71,   72,   73,
};
static const short yysindex[] = {                      -246,
 -235,    0, -244, -199,    0, -207,  -97, -189,    0, -188,
    0, -171, -167,    0, -153,    0,    0,    0, -199, -139,
 -126, -121,    0, -107, -131,  -97,    0,  -99,  -94,    0,
  -78,    0,  -77, -131,  -93, -270,  -68,    0,  -64, -280,
  -49,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -55,  -72, -199, -188, -199, -188,    0, -242,
  -65, -136, -136, -270,    0,  -38,  -30,   82,  -14, -250,
    0,    0,    0,  -74, -270, -270, -270, -270, -270,  -44,
  -20,    0,    0, -276,    0,  -58,    0, -131, -270, -250,
 -250, -125, -270, -270, -136, -136, -270, -270, -270, -270,
 -270, -270,    0, -136, -136, -174,   11,  -82, -267, -142,
 -142,  -17,  -12,   -9, -131,   -5,   -1,    0, -142,    0,
 -206,  -24, -250, -250, -142, -142, -142, -142, -142, -142,
 -131,    0,    0,    0, -270,    0,    0,   -4, -270,    9,
    0,    1,    0,    0,    0,   26,    0,    0,    0, -204,
 -131, -270, -142,    0,   10, -199, -199, -270,   38,   14,
    0, -142,    0,    0,    0, -142,    0,    0,    0,   41,
 -131, -131,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -178,    0,    0, -169,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -216, -180,
   15,   19,    0,   21,   16, -152,    0,    0,    0,    0,
    0,    0,    0, -197,    0,    0,    0,    0,    0, -231,
 -238,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -48, -143,    0, -143,    0,    0,    0,
    0,    0,    0,    0,    0, -104,    0,    0,    0,  -70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -197,    0,  -36,
   -2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -226,
  -23,   24,    0,    0,   27,    0,    0,    0,   48,    0,
    0,    0,   32,   66, -194, -192, -124, -115, -108, -106,
  -63,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -63,    0,  -19,    0,    0, -143, -143,    0, -230,    0,
    0,  -29,    0,    0,    0,   63,    0,    0,    0,    0,
  -63,  -63,    0,    0,
};
static const short yygindex[] = {                         0,
  309,    0,    0,  323,    0,  -34,    0,    0,  310,  137,
    0,    0,  302,    0,    0,  -56,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -62,  255,    0,    0,    0,    0,    0,
    0,    0,    0,  237,    0,  -53,   81,    0,    0,
};
#define YYTABLESIZE 364
static const short yytable[] = {                         59,
   85,   92,   62,   63,   77,   95,   96,  116,   90,   91,
   29,   78,   64,  108,  109,  110,  111,   87,  138,    1,
   54,   54,   65,   66,  104,  105,  119,   57,   57,   45,
  121,  111,   40,   40,  125,  126,  127,  128,  129,  130,
    5,  123,  124,    4,    5,   88,    5,    5,    5,   54,
    5,   57,   54,  118,    5,    5,   57,   45,    3,   57,
   45,   40,   62,   63,   40,   64,   95,   96,   95,   96,
    5,    5,  150,   63,    5,   64,  153,    5,    4,  147,
  143,  160,    4,   11,    4,    4,    4,   10,    4,  162,
   62,   10,    4,    4,   10,  166,  149,   10,   19,  164,
  165,   10,   10,   86,   11,   20,   86,   86,   11,  134,
  135,   11,    4,    4,   11,    4,  161,    4,   11,   11,
    4,   10,   22,    4,   10,   34,   23,    4,    4,   35,
   95,   96,   36,   66,   26,   37,  173,  174,   11,   38,
   39,   11,   65,   66,    4,   28,   64,   95,   96,   68,
    4,   67,   65,   81,   81,   81,   65,   66,  120,   68,
   29,   67,   40,   81,   81,   12,   30,   13,   81,   81,
   81,   81,   81,   81,   81,   81,   81,   81,   21,   81,
   32,   81,   81,   81,  132,  133,   81,   69,   69,   69,
   95,   96,   84,   53,   86,   62,   62,   69,   69,   54,
   61,  137,   69,   69,   56,   58,   69,   69,   69,   69,
   69,   69,   81,   69,   74,   69,   69,   69,   76,  106,
   69,   70,   70,   70,   62,  117,   89,   62,   29,   41,
   41,   70,   70,   79,   80,   88,   70,   70,   88,   88,
   70,   70,   70,   70,   70,   70,   93,   70,  113,   70,
   70,   70,   94,  103,   70,   71,   71,   71,   41,  148,
   84,   41,  139,   84,   85,   71,   71,   85,  136,  139,
   71,   71,  114,  141,   71,   71,   71,   71,   71,   71,
  142,   71,  144,   71,   71,   71,  145,  152,   71,   72,
   72,   72,  154,  155,  158,  163,  167,  169,  172,   72,
   72,   24,    9,   18,   72,   72,   62,   55,   72,   72,
   72,   72,   72,   72,   62,   72,   51,   72,   72,   72,
   52,   24,   72,   73,   73,   73,    7,   52,   27,  107,
  122,    0,    0,   73,   73,    0,    0,    0,   73,   73,
    0,    0,   73,   73,   73,   73,   73,   73,    0,   73,
    0,   73,   73,   73,   95,   96,   73,    0,   97,   98,
   99,  100,  101,  102,
};
static const short yycheck[] = {                         34,
   57,   64,  273,  274,  285,  273,  274,  284,   62,   63,
  287,  292,  283,   76,   77,   78,   79,  260,  286,  266,
  259,  260,  293,  294,  275,  276,   89,  259,  260,  260,
   93,   94,  259,  260,   97,   98,   99,  100,  101,  102,
  257,   95,   96,  288,  261,  288,  263,  264,  265,  288,
  267,  283,  291,   88,  271,  272,  288,  288,  294,  291,
  291,  288,  260,  258,  291,  258,  273,  274,  273,  274,
  270,  288,  135,  268,  291,  268,  139,  294,  257,  286,
  115,  286,  261,  291,  263,  264,  265,  257,  267,  152,
  288,  261,  271,  272,  264,  158,  131,  267,  288,  156,
  157,  271,  272,  284,  257,  294,  287,  288,  261,  284,
  285,  264,  291,  257,  267,  294,  151,  261,  271,  272,
  264,  291,  294,  267,  294,  257,  294,  271,  272,  261,
  273,  274,  264,  258,  288,  267,  171,  172,  291,  271,
  272,  294,  258,  268,  288,  285,  283,  273,  274,  258,
  294,  258,  268,  258,  259,  260,  293,  294,  284,  268,
  287,  268,  294,  268,  269,  263,  288,  265,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  288,  286,  287,  288,  104,  105,  291,  258,  259,  260,
  273,  274,   56,  293,   58,  259,  260,  268,  269,  294,
  294,  284,  273,  274,  283,  283,  277,  278,  279,  280,
  281,  282,  285,  284,  283,  286,  287,  288,  283,  294,
  291,  258,  259,  260,  288,  284,  292,  291,  287,  259,
  260,  268,  269,  283,  290,  284,  273,  274,  287,  288,
  277,  278,  279,  280,  281,  282,  285,  284,  293,  286,
  287,  288,  283,  268,  291,  258,  259,  260,  288,  284,
  284,  291,  287,  287,  284,  268,  269,  287,  258,  287,
  273,  274,  293,  286,  277,  278,  279,  280,  281,  282,
  290,  284,  288,  286,  287,  288,  288,  292,  291,  258,
  259,  260,  284,  293,  269,  286,  259,  284,  258,  268,
  269,  283,  288,  283,  273,  274,  291,  284,  277,  278,
  279,  280,  281,  282,  288,  284,  269,  286,  287,  288,
  258,   13,  291,  258,  259,  260,    4,   26,   19,   75,
   94,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,  286,  287,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,
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
"assignment_statement : IDENT LBRACKET expression RBRACKET ASSIGN expression",
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
"for_statement : FOR IDENT ASSIGN expression $$15 TO expression $$16 DO statement",
"proc_call_statement : proc_call_name",
"$$17 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$17 RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"read_statement : READ LPAREN IDENT LBRACKET expression RBRACKET RPAREN",
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
#line 504 "parser.y"


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
#line 482 "y.tab.c"

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
#line 71 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 79 "parser.y"
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
#line 88 "parser.y"
	{
        back_patch();
        }
break;
case 8:
#line 104 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 106 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 16:
#line 127 "parser.y"
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
#line 137 "parser.y"
	{
        back_patch();
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 18:
#line 144 "parser.y"
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
#line 152 "parser.y"
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
#line 161 "parser.y"
	{
        back_patch();
        insert_code(Ret);
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 22:
#line 176 "parser.y"
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
#line 187 "parser.y"
	{
        back_patch();
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
#line 198 "parser.y"
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
#line 208 "parser.y"
	{
        arity_mode = FALSE;
        overwrite_symbol_arity(yystack.l_mark[-5].ident, arity_num);
        insert_decl(yystack.l_mark[-5].ident, arity_num, NULL, INT);
        reg_counter = count + 1;
        count++;
        }
break;
case 26:
#line 214 "parser.y"
	{
        func_mode = FALSE;
        back_patch();
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
#line 228 "parser.y"
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
#line 271 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 42:
#line 280 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 43:
#line 284 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        }
break;
case 45:
#line 292 "parser.y"
	{
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 46:
#line 296 "parser.y"
	{
        insert_code(Label);
        }
break;
case 47:
#line 299 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 48:
#line 308 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
break;
case 49:
#line 314 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 50:
#line 318 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
break;
case 51:
#line 327 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp1 = reg_counter;
        insert_code(Label);
        factor_push(x);
        insert_code(Load);
        }
break;
case 52:
#line 338 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 53:
#line 344 "parser.y"
	{
        insert_code(BrUncond);
        tmp2 = reg_counter;
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
        tmp3 = reg_counter;
        label_push(tmp3);
        label_push(tmp2);
        label_push(tmp1);
        insert_code(Label);
        }
break;
case 54:
#line 366 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[0].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 55:
#line 371 "parser.y"
	{
        Factor x = create_proc_or_func_factor(yystack.l_mark[-2].ident, get_aritystack_top());
        factor_push(x);
        insert_code(Proc);
        }
break;
case 59:
#line 387 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 61:
#line 397 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 63:
#line 408 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 64:
#line 409 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 65:
#line 410 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 66:
#line 411 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 67:
#line 412 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 68:
#line 413 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 72:
#line 420 "parser.y"
	{insert_code(Add);}
break;
case 73:
#line 421 "parser.y"
	{insert_code(Sub);}
break;
case 75:
#line 426 "parser.y"
	{insert_code(Mult);}
break;
case 76:
#line 427 "parser.y"
	{insert_code(Div);}
break;
case 78:
#line 432 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 81:
#line 441 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 83:
#line 450 "parser.y"
	{
                Factor x = create_proc_or_func_factor(yystack.l_mark[-3].ident, get_aritystack_top());
                /*create_factor_by_name()で帰ってくるのはlocal varなので加工してあげる*/
                /*関数名と返り値の名前が一緒なのでこれでオケ*/
                x.type = FUNC_NAME;
                factor_push(x);
                insert_code(Func);
        }
break;
case 84:
#line 462 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 85:
#line 467 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 86:
#line 475 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        else if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 88:
#line 488 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        else if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
#line 1130 "y.tab.c"
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
