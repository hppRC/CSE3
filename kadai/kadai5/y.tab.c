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


#line 25 "parser.y"
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
#line 53 "y.tab.c"

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
    0,    5,    1,    2,    2,    6,    6,    7,    3,    3,
    9,    9,   10,   14,   11,   12,   13,   15,   15,    4,
    4,    4,    4,    4,    4,    4,    4,    4,   16,   27,
   17,   28,   29,   28,   30,   31,   18,   19,   20,   32,
   22,   23,   24,   21,   26,   26,   26,   26,   26,   26,
   25,   25,   25,   25,   25,   33,   33,   33,   34,   34,
   34,   35,   36,   36,    8,    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    0,    5,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    0,
    6,    0,    0,    3,    0,    0,    6,    8,    1,    1,
    3,    4,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   65,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   16,
    0,    0,    0,    6,   66,   14,    0,    0,    0,    0,
   35,    0,    0,    3,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   39,   11,    0,   19,    0,    0,    0,
    0,    0,   60,   62,    0,    0,    0,   56,   59,    0,
    0,    0,    0,    0,   15,   41,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,    0,    0,    0,   17,   18,    0,   61,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
   58,   42,   36,   43,    0,    0,    0,    0,   33,   31,
   37,    0,    0,   38,   34,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   34,   22,    8,    9,   11,   15,   16,
   17,   21,   65,   46,   48,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   55,   56,   99,  110,  113,   61,
  107,   44,   57,   58,   59,    0,
};
static const short yysindex[] = {                      -264,
 -285,    0, -273, -222, -243, -234, -210, -229,    0,    0,
 -182,    0, -195,    0, -146,    0,    0, -222, -160,    0,
 -129, -251, -210,    0,    0,    0, -251, -130, -165, -122,
    0, -118, -126,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -222,    0, -246, -123, -205,
 -205, -165,    0,    0,   -9,  -98, -159,    0,    0, -117,
 -165, -165, -165, -251,    0,    0, -251, -165, -159, -159,
 -192, -205, -205, -165, -165, -165, -165, -165, -165,    0,
 -205, -205, -101,  -74, -154, -135,    0,    0, -266,    0,
 -159, -159, -135, -135, -135, -135, -135, -135, -251,    0,
    0,    0,    0,    0, -165,  -73, -251, -162,    0,    0,
    0, -251, -251,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -201,    0,    0, -188,    0,    0,    0,
 -100,    0,    0,    0,    0,    0,    0, -226,    0,    0,
    0, -104, -170,    0,    0,    0, -211,    0,    0,    0,
    0,    0, -255,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -157,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -133,    0,    0,    0,
    0,    0,    0,  -97,    0,    0, -211,    0, -106,  -79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -241,    0,    0,    0,    0,
  -52,  -25, -236, -224, -145, -136, -125, -108, -230,    0,
    0,    0,    0,    0,    0, -193, -230,    0,    0,    0,
    0, -230, -230,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  146,    0,  -27,    0,    0,  175,    0,    0,  173,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -51,  136,    0,    0,    0,    0,
    0,    0,    2,   75,    0,    0,
};
#define YYTABLESIZE 273
static const short yytable[] = {                         47,
   71,    1,  105,   40,   40,   27,   72,   73,    3,   28,
   85,   86,   29,   66,    4,   30,   89,   29,   29,   31,
   32,   45,   93,   94,   95,   96,   97,   98,   44,   44,
    5,   45,   40,   46,    5,   40,   87,    5,    5,   88,
    5,   67,   33,   46,    5,    5,   29,    5,   44,   29,
   10,   69,   70,  108,   13,    4,   12,   44,   18,    4,
   44,    5,    4,    4,    5,    4,   32,    5,    9,    4,
    4,  106,    9,   91,   92,    9,   44,   52,    9,  111,
   72,   73,    9,    9,  114,  115,   10,   53,   54,    4,
   10,   90,    4,   10,   32,  112,   10,   32,   20,    4,
   10,   10,    9,    4,   19,    9,    4,   50,   51,    4,
   72,   73,   48,    4,    4,   81,   82,   52,   72,   73,
   10,   47,   48,   10,   51,   51,   51,   53,   54,  104,
    4,   47,   50,   25,   51,   51,    4,   72,   73,   51,
   51,   23,   50,   51,   51,   51,   51,   51,   51,   49,
   51,   52,   52,   52,   51,  100,  101,   51,   26,   49,
   60,   52,   52,   49,   62,   63,   52,   52,   68,   80,
   52,   52,   52,   52,   52,   52,   83,   52,   53,   53,
   53,   52,  102,  103,   52,  109,   44,    8,   53,   53,
   44,   64,   24,   53,   53,   45,   84,   53,   53,   53,
   53,   53,   53,    0,   53,   54,   54,   54,   53,    0,
    0,   53,    0,    0,    0,   54,   54,    0,    0,    0,
   54,   54,    0,    0,   54,   54,   54,   54,   54,   54,
    0,   54,   55,   55,   55,   54,    0,    0,   54,    0,
    0,    0,   55,   55,    0,    0,    0,   55,   55,    0,
    0,   55,   55,   55,   55,   55,   55,    0,   55,    0,
    0,    0,   55,   72,   73,   55,    0,   74,   75,   76,
   77,   78,   79,
};
static const short yycheck[] = {                         27,
   52,  266,  269,  259,  260,  257,  273,  274,  294,  261,
   62,   63,  264,  260,  288,  267,   68,  259,  260,  271,
  272,  258,   74,   75,   76,   77,   78,   79,  259,  260,
  257,  268,  288,  258,  261,  291,   64,  264,  265,   67,
  267,  288,  294,  268,  271,  272,  288,  270,  260,  291,
  294,   50,   51,  105,  265,  257,  291,  288,  288,  261,
  291,  288,  264,  265,  291,  267,  260,  294,  257,  271,
  272,   99,  261,   72,   73,  264,  288,  283,  267,  107,
  273,  274,  271,  272,  112,  113,  257,  293,  294,  291,
  261,  284,  294,  264,  288,  258,  267,  291,  294,  257,
  271,  272,  291,  261,  287,  294,  264,  273,  274,  267,
  273,  274,  258,  271,  272,  275,  276,  283,  273,  274,
  291,  258,  268,  294,  258,  259,  260,  293,  294,  284,
  288,  268,  258,  294,  268,  269,  294,  273,  274,  273,
  274,  288,  268,  277,  278,  279,  280,  281,  282,  258,
  284,  258,  259,  260,  288,   81,   82,  291,  288,  268,
  283,  268,  269,  294,  283,  292,  273,  274,  292,  268,
  277,  278,  279,  280,  281,  282,  294,  284,  258,  259,
  260,  288,  284,  258,  291,  259,  291,  288,  268,  269,
  288,   46,   18,  273,  274,   23,   61,  277,  278,  279,
  280,  281,  282,   -1,  284,  258,  259,  260,  288,   -1,
   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,   -1,
   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,   -1,
   -1,   -1,  288,  273,  274,  291,   -1,  277,  278,  279,
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
"$$3 :",
"if_statement : IF condition THEN $$3 statement else_statement",
"else_statement :",
"$$4 :",
"else_statement : ELSE $$4 statement",
"$$5 :",
"$$6 :",
"while_statement : WHILE $$5 condition DO $$6 statement",
"for_statement : FOR IDENT ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
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
#line 272 "parser.y"


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
#line 397 "y.tab.c"

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
#line 49 "parser.y"
	{
                if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
                display_llvm();
                fclose(fp);
        }
break;
case 2:
#line 58 "parser.y"
	{
                insert_decl("main", 0, NULL);
                Factor x = {CONSTANT, "1", 0};
                factor_push(x);
                insert_code(Alloca);
                insert_code(Store);
        }
break;
case 3:
#line 66 "parser.y"
	{
                insert_code(Load);
                /*insert_code(Ret);*/
        }
break;
case 14:
#line 102 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        }
break;
case 15:
#line 107 "parser.y"
	{
        /*insert_code(Ret);*/
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 16:
#line 116 "parser.y"
	{
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 1);
        insert_decl(yystack.l_mark[0].ident, 0, NULL);
        }
break;
case 29:
#line 145 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 30:
#line 153 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 32:
#line 158 "parser.y"
	{insert_code(BrUncond);insert_code(Label);}
break;
case 33:
#line 159 "parser.y"
	{insert_code(Label);}
break;
case 34:
#line 160 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 35:
#line 164 "parser.y"
	{insert_code(BrUncond);insert_code(Label);}
break;
case 36:
#line 165 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 37:
#line 166 "parser.y"
	{insert_code(BrUncond);insert_code(Label);}
break;
case 38:
#line 171 "parser.y"
	{lookup_symbol(yystack.l_mark[-6].ident);}
break;
case 40:
#line 180 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 42:
#line 192 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 43:
#line 201 "parser.y"
	{insert_code(Write);}
break;
case 45:
#line 209 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 46:
#line 210 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 47:
#line 211 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 48:
#line 212 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 49:
#line 213 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 50:
#line 214 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 54:
#line 221 "parser.y"
	{insert_code(Add);}
break;
case 55:
#line 222 "parser.y"
	{insert_code(Sub);
        }
break;
case 57:
#line 228 "parser.y"
	{insert_code(Mult);}
break;
case 58:
#line 229 "parser.y"
	{insert_code(Div);}
break;
case 60:
#line 234 "parser.y"
	{Factor x = {CONSTANT, "", yystack.l_mark[0].num}; factor_push(x);}
break;
case 62:
#line 240 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 65:
#line 254 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
case 66:
#line 262 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
#line 783 "y.tab.c"
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
