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


/*前の値を積んでいくスタックを作るとネストにも対応できそう*/
int tmp;
int tmp1,tmp2, tmp3;
int arity = 0;

#line 31 "parser.y"
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
#line 59 "y.tab.c"

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
    0,    7,    3,    4,    4,    8,    8,    9,    5,    5,
   11,   11,   12,   15,   13,   16,   17,   13,    1,   14,
   18,   18,    6,    6,    6,    6,    6,    6,    6,    6,
    6,   19,   30,   32,   20,   31,   33,   31,   34,   35,
   21,   36,   37,   22,   23,   39,   23,    2,   25,   26,
   27,   24,   29,   29,   29,   29,   29,   29,   28,   28,
   28,   28,   28,   40,   40,   40,   41,   41,   41,   42,
   38,   38,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    0,    5,    0,    0,    9,    1,    2,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    0,    0,    7,    0,    0,    3,    0,    0,
    6,    0,    0,   10,    1,    0,    5,    1,    3,    4,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   73,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   19,
    0,    0,    0,    6,   74,   14,    0,    0,    0,    0,
    0,   39,    0,    0,    0,    3,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   11,    0,    0,   22,    0,
    0,    0,    0,    0,   68,   70,    0,    0,    0,   64,
   67,    0,    0,    0,    0,    0,    0,   15,    0,   49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   33,    0,    0,    0,    0,    0,    0,
    0,    0,   20,    0,   21,    0,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   65,   66,   50,   40,
   51,    0,    0,   17,    0,   34,    0,    0,   47,    0,
    0,    0,   41,   18,    0,   37,   35,    0,    0,    0,
   38,   44,
};
static const short yydgoto[] = {                          2,
   21,   35,    6,   67,   14,   36,   22,    8,    9,   11,
   15,   16,   17,   68,   47,   27,  120,   50,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   57,   58,  106,
  127,  122,  129,   63,  117,  115,  128,   92,  113,   59,
   60,   61,
};
static const short yysindex[] = {                      -260,
 -272,    0, -247, -212, -229, -217, -198, -203,    0,    0,
 -189,    0, -194,    0, -197,    0,    0, -212, -183,    0,
 -171, -149, -198,    0,    0,    0, -178, -149, -175, -139,
 -151,    0, -150, -153, -143,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -212, -229,    0, -253,
 -140, -273, -273, -139,    0,    0,   21, -110, -252,    0,
    0, -135, -139, -139, -139, -139, -149,    0, -270,    0,
 -149, -139, -252, -252, -109, -273, -273, -139, -139, -139,
 -139, -139, -139,    0, -273, -273, -118,  -85, -106, -224,
 -224, -113,    0, -102,    0, -224,    0, -252, -252, -224,
 -224, -224, -224, -224, -224, -149,    0,    0,    0,    0,
    0, -139,  -96,    0,  -76,    0, -149, -224,    0, -212,
 -139,  -60,    0,    0, -224,    0,    0,  -58, -149, -149,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -210,    0,    0, -201,    0,    0,    0,
  -84,    0,    0,    0,    0,    0,    0, -219,    0,    0,
  -80,  -83, -184,    0,    0,    0,    0, -244,    0,    0,
    0,    0,    0, -251, -257,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -158,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -131,    0,
    0,    0,    0,    0,    0,    0,  -81,    0,    0,    0,
 -244,    0,  -97,  -63,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -255,
 -269,  -75,    0,    0,    0,  -57,    0,  -29,    5, -182,
 -164, -142, -127,  -79,  -66,  -90,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -90, -205,    0, -158,
    0, -196,    0,    0,  -45,    0,    0,    0,  -90,  -90,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  216,    0,  -28,    0,    0,  204,  175,
    0,  203,    0,  107,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -53,  169,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   44,
   39,    0,
};
#define YYTABLESIZE 303
static const short yytable[] = {                         49,
   75,   45,   45,   32,   32,    1,   70,   48,   48,   54,
   89,   90,   91,   94,   71,   52,   19,   71,   96,   55,
   56,    3,   85,   86,  100,  101,  102,  103,  104,  105,
   45,   48,   32,   45,   71,   32,   48,    5,   93,   48,
    4,    5,   95,   52,    5,    5,    4,    5,   76,   77,
    4,    5,    5,    4,    4,    9,    4,    5,  118,    9,
    4,    4,    9,   36,   10,    9,   13,  125,    5,    9,
    9,    5,   10,   12,    5,   53,   10,  116,   72,   10,
    4,   72,   10,    4,   18,   53,   10,   10,  123,    9,
   23,   36,    9,   54,   36,   73,   74,   19,    4,   20,
  131,  132,    4,   54,   48,    4,   10,   28,    4,   10,
   25,   29,    4,    4,   30,   56,   26,   31,   51,   98,
   99,   32,   33,  107,  108,   56,   59,   59,   59,    4,
   55,   62,   64,   52,   53,    4,   59,   59,   65,   66,
   55,   59,   59,   54,   34,   59,   59,   59,   59,   59,
   59,   72,   59,   55,   56,   59,   59,   84,   87,   59,
   60,   60,   60,   76,   77,  109,   76,   77,   52,   52,
   60,   60,  110,  112,   97,   60,   60,  111,   58,   60,
   60,   60,   60,   60,   60,  114,   60,  119,   58,   60,
   60,   57,  121,   60,   61,   61,   61,   52,  126,  130,
   52,   57,   16,    8,   61,   61,   52,   52,   46,   61,
   61,   42,   43,   61,   61,   61,   61,   61,   61,    7,
   61,   24,   69,   61,   61,   46,  124,   61,   62,   62,
   62,   88,    0,    0,    0,    0,    0,    0,   62,   62,
    0,    0,    0,   62,   62,    0,    0,   62,   62,   62,
   62,   62,   62,    0,   62,    0,    0,   62,   62,    0,
    0,   62,   63,   63,   63,    0,    0,    0,    0,    0,
    0,    0,   63,   63,    0,    0,    0,   63,   63,    0,
    0,   63,   63,   63,   63,   63,   63,    0,   63,    0,
    0,   63,   63,   76,   77,   63,    0,   78,   79,   80,
   81,   82,   83,
};
static const short yycheck[] = {                         28,
   54,  259,  260,  259,  260,  266,  260,  259,  260,  283,
   64,   65,   66,  284,  284,  260,  287,  287,   72,  293,
  294,  294,  275,  276,   78,   79,   80,   81,   82,   83,
  288,  283,  288,  291,  288,  291,  288,  257,   67,  291,
  288,  261,   71,  288,  264,  265,  257,  267,  273,  274,
  261,  271,  272,  264,  265,  257,  267,  270,  112,  261,
  271,  272,  264,  260,  294,  267,  265,  121,  288,  271,
  272,  291,  257,  291,  294,  258,  261,  106,  284,  264,
  291,  287,  267,  294,  288,  268,  271,  272,  117,  291,
  288,  288,  294,  258,  291,   52,   53,  287,  257,  294,
  129,  130,  261,  268,  283,  264,  291,  257,  267,  294,
  294,  261,  271,  272,  264,  258,  288,  267,  294,   76,
   77,  271,  272,   85,   86,  268,  258,  259,  260,  288,
  258,  283,  283,  273,  274,  294,  268,  269,  292,  283,
  268,  273,  274,  283,  294,  277,  278,  279,  280,  281,
  282,  292,  284,  293,  294,  287,  288,  268,  294,  291,
  258,  259,  260,  273,  274,  284,  273,  274,  259,  260,
  268,  269,  258,  287,  284,  273,  274,  284,  258,  277,
  278,  279,  280,  281,  282,  288,  284,  284,  268,  287,
  288,  258,  269,  291,  258,  259,  260,  288,  259,  258,
  291,  268,  283,  288,  268,  269,  288,  291,  284,  273,
  274,  269,  258,  277,  278,  279,  280,  281,  282,    4,
  284,   18,   48,  287,  288,   23,  120,  291,  258,  259,
  260,   63,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,   -1,
   -1,  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,   -1,
   -1,  287,  288,  273,  274,  291,   -1,  277,  278,  279,
  280,  281,  282,
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
"var_decl : VAR id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"$$2 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$2 inblock",
"$$3 :",
"$$4 :",
"proc_decl : PROCEDURE proc_name $$3 LPAREN id_list RPAREN SEMICOLON $$4 inblock",
"proc_name : IDENT",
"inblock : var_decl_part statement",
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
"$$5 :",
"$$6 :",
"if_statement : IF condition THEN $$5 statement $$6 else_statement",
"else_statement :",
"$$7 :",
"else_statement : ELSE $$7 statement",
"$$8 :",
"$$9 :",
"while_statement : WHILE $$8 condition DO $$9 statement",
"$$10 :",
"$$11 :",
"for_statement : FOR IDENT ASSIGN expression $$10 TO expression $$11 DO statement",
"proc_call_statement : proc_call_name",
"$$12 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$12 RPAREN",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
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
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

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
#line 360 "parser.y"


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
#line 427 "y.tab.c"

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
#line 58 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 66 "parser.y"
	{
        insert_decl("main", 0, NULL);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        insert_code(Alloca);
        insert_code(Store);
        }
break;
case 3:
#line 73 "parser.y"
	{
        back_patch();
        /*insert_code(Load);*/
        /*insert_code(Ret);*/
        }
break;
case 14:
#line 109 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 1);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL);
        }
break;
case 15:
#line 115 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 16:
#line 120 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 1);
        insert_decl(yystack.l_mark[0].ident, 0, NULL);
        }
break;
case 17:
#line 125 "parser.y"
	{
        printf("%s\n", yystack.l_mark[-5].ident); /*同じ遷移規則内ならカッコをまたいでsemantics valueを取れる*/
        }
break;
case 18:
#line 128 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 32:
#line 161 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 33:
#line 169 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 34:
#line 173 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        }
break;
case 36:
#line 181 "parser.y"
	{
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 37:
#line 185 "parser.y"
	{
        insert_code(Label);
        }
break;
case 38:
#line 188 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 39:
#line 197 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
break;
case 40:
#line 203 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 41:
#line 207 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
break;
case 42:
#line 216 "parser.y"
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
case 43:
#line 227 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 44:
#line 233 "parser.y"
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
case 45:
#line 255 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 46:
#line 260 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 50:
#line 276 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 51:
#line 285 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 53:
#line 296 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 54:
#line 297 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 55:
#line 298 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 56:
#line 299 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 57:
#line 300 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 58:
#line 301 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 62:
#line 308 "parser.y"
	{insert_code(Add);}
break;
case 63:
#line 309 "parser.y"
	{insert_code(Sub);}
break;
case 65:
#line 314 "parser.y"
	{insert_code(Mult);}
break;
case 66:
#line 315 "parser.y"
	{insert_code(Div);}
break;
case 68:
#line 320 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 70:
#line 328 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 71:
#line 336 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 72:
#line 341 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 73:
#line 349 "parser.y"
	{
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        if (scope == LOCAL_VAR) insert_code(Alloca);
        }
break;
case 74:
#line 353 "parser.y"
	{
        insert_symbol(scope, yystack.l_mark[0].ident, count++);
        if (scope == LOCAL_VAR) insert_code(Alloca);
        }
break;
#line 930 "y.tab.c"
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
