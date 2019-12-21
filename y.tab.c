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
   17,   28,   28,   29,   30,   18,   19,   20,   31,   22,
   23,   24,   21,   26,   26,   26,   26,   26,   26,   25,
   25,   25,   25,   25,   32,   32,   32,   33,   33,   33,
   34,   35,   35,    8,    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    0,    5,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    0,
    6,    0,    2,    0,    0,    6,    8,    1,    1,    3,
    4,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   64,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   16,
    0,    0,    0,    6,   65,   14,    0,    0,    0,    0,
   34,    0,    0,    3,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   38,   11,    0,   19,    0,    0,    0,
    0,    0,   59,   61,    0,    0,    0,   55,   58,    0,
    0,    0,    0,    0,   15,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,    0,    0,    0,   17,   18,    0,   60,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   57,   41,   35,   42,    0,    0,    0,    0,    0,   31,
   36,    0,   33,   37,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   34,   22,    8,    9,   11,   15,   16,
   17,   21,   65,   46,   48,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   55,   56,   99,  110,   61,  107,
   44,   57,   58,   59,    0,
};
static const short yysindex[] = {                      -264,
 -285,    0, -236, -248, -239, -220, -190, -211,    0,    0,
 -177,    0, -196,    0, -172,    0,    0, -248, -163,    0,
 -156, -251, -190,    0,    0,    0, -251, -159,  -40, -133,
    0, -129, -149,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -248,    0, -228, -135, -171,
 -171,  -40,    0,    0,  -16, -110, -261,    0,    0, -132,
  -40,  -40,  -40, -251,    0,    0, -251,  -40, -261, -261,
 -121, -171, -171,  -40,  -40,  -40,  -40,  -40,  -40,    0,
 -171, -171, -114,  -82,  -94, -181,    0,    0, -266,    0,
 -261, -261, -181, -181, -181, -181, -181, -181, -251,    0,
    0,    0,    0,    0,  -40,  -78, -251, -207, -251,    0,
    0, -251,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -208,    0,    0, -183,    0,    0,    0,
 -111,    0,    0,    0,    0,    0,    0, -226,    0,    0,
    0, -107, -170,    0,    0,    0, -212,    0,    0,    0,
    0,    0, -255,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -158,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -140,    0,    0,    0,
    0,    0,    0, -103,    0,    0, -212,    0, -113,  -86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -241,    0,    0,    0,    0,
  -59,  -32, -224, -189, -168, -151, -143, -109, -230,    0,
    0,    0,    0,    0,    0, -218, -230,    0, -230,    0,
    0, -230,    0,    0,
};
static const short yygindex[] = {                         0,
    0,  140,    0,  -27,    0,    0,  171,    0,    0,  174,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -51,  142,    0,    0,    0,    0,
    0,   54,   14,    0,    0,
};
#define YYTABLESIZE 266
static const short yytable[] = {                         47,
   71,    1,  105,   39,   39,   27,   72,   73,    3,   28,
   85,   86,   29,   81,   82,   30,   89,   29,   29,   31,
   32,    5,   93,   94,   95,   96,   97,   98,   43,   43,
    5,   66,   39,   44,    5,   39,   87,    5,    5,   88,
    5,   32,   33,   44,    5,    5,   29,   43,    4,   29,
  112,    4,    4,  108,   10,    4,    4,   43,    4,   67,
   43,    5,    4,    4,    5,   72,   73,    5,   45,   32,
   12,  106,   32,    9,   13,   43,   18,    9,   45,  111,
    9,  113,    4,    9,  114,    4,   10,    9,    9,   47,
   10,   72,   73,   10,  100,  101,   10,   20,    4,   47,
   10,   10,    4,   69,   70,    4,   46,    9,    4,   19,
    9,   52,    4,    4,   49,   23,   46,   50,   50,   50,
   10,   53,   54,   10,   49,   91,   92,   50,   50,    4,
   25,   26,   50,   50,   49,    4,   50,   50,   50,   50,
   50,   50,   63,   50,   51,   51,   51,   50,   48,   60,
   50,   72,   73,   62,   51,   51,   68,   80,   48,   51,
   51,   83,   90,   51,   51,   51,   51,   51,   51,  102,
   51,   52,   52,   52,   51,  103,    8,   51,   72,   73,
  109,   52,   52,   43,   43,   64,   52,   52,   24,  104,
   52,   52,   52,   52,   52,   52,   45,   52,   53,   53,
   53,   52,   84,    0,   52,    0,    0,    0,   53,   53,
    0,    0,    0,   53,   53,    0,    0,   53,   53,   53,
   53,   53,   53,    0,   53,   54,   54,   54,   53,    0,
    0,   53,   50,   51,    0,   54,   54,    0,    0,    0,
   54,   54,   52,    0,   54,   54,   54,   54,   54,   54,
    0,   54,   53,   54,    0,   54,   72,   73,   54,    0,
   74,   75,   76,   77,   78,   79,
};
static const short yycheck[] = {                         27,
   52,  266,  269,  259,  260,  257,  273,  274,  294,  261,
   62,   63,  264,  275,  276,  267,   68,  259,  260,  271,
  272,  270,   74,   75,   76,   77,   78,   79,  259,  260,
  257,  260,  288,  258,  261,  291,   64,  264,  265,   67,
  267,  260,  294,  268,  271,  272,  288,  260,  257,  291,
  258,  288,  261,  105,  294,  264,  265,  288,  267,  288,
  291,  288,  271,  272,  291,  273,  274,  294,  258,  288,
  291,   99,  291,  257,  265,  288,  288,  261,  268,  107,
  264,  109,  291,  267,  112,  294,  257,  271,  272,  258,
  261,  273,  274,  264,   81,   82,  267,  294,  257,  268,
  271,  272,  261,   50,   51,  264,  258,  291,  267,  287,
  294,  283,  271,  272,  258,  288,  268,  258,  259,  260,
  291,  293,  294,  294,  268,   72,   73,  268,  269,  288,
  294,  288,  273,  274,  294,  294,  277,  278,  279,  280,
  281,  282,  292,  284,  258,  259,  260,  288,  258,  283,
  291,  273,  274,  283,  268,  269,  292,  268,  268,  273,
  274,  294,  284,  277,  278,  279,  280,  281,  282,  284,
  284,  258,  259,  260,  288,  258,  288,  291,  273,  274,
  259,  268,  269,  291,  288,   46,  273,  274,   18,  284,
  277,  278,  279,  280,  281,  282,   23,  284,  258,  259,
  260,  288,   61,   -1,  291,   -1,   -1,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  258,  259,  260,  288,   -1,
   -1,  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,  283,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  293,  294,   -1,  288,  273,  274,  291,   -1,
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
"else_statement : ELSE statement",
"$$4 :",
"$$5 :",
"while_statement : WHILE $$4 condition DO $$5 statement",
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
#line 255 "parser.y"


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
#line 394 "y.tab.c"

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
                if ((fp = fopen(filename, "w")) == NULL) {
                        fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                return EXIT_FAILURE;
                }
                display_llvm();
                fclose(fp);
        }
break;
case 2:
#line 60 "parser.y"
	{
                insert_decl("main", 0, NULL);
                Factor x = {CONSTANT, "1", 0};
                factor_push(x);
                insert_code(Alloca);
                insert_code(Store);
        }
break;
case 14:
#line 99 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        }
break;
case 15:
#line 104 "parser.y"
	{
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 16:
#line 112 "parser.y"
	{
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, 1);
        insert_decl(yystack.l_mark[0].ident, 0, NULL);
        }
break;
case 29:
#line 141 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 30:
#line 149 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 32:
#line 153 "parser.y"
	{insert_code(BrUncond);insert_code(Label);}
break;
case 33:
#line 154 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 34:
#line 158 "parser.y"
	{insert_code(BrUncond);insert_code(Label);}
break;
case 35:
#line 159 "parser.y"
	{insert_code(BrCond);insert_code(Label);}
break;
case 37:
#line 164 "parser.y"
	{lookup_symbol(yystack.l_mark[-6].ident);}
break;
case 39:
#line 172 "parser.y"
	{lookup_symbol(yystack.l_mark[0].ident);}
break;
case 41:
#line 180 "parser.y"
	{lookup_symbol(yystack.l_mark[-1].ident);}
break;
case 44:
#line 192 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 45:
#line 193 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 46:
#line 194 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 47:
#line 195 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 48:
#line 196 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 49:
#line 197 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 53:
#line 204 "parser.y"
	{insert_code(Add);}
break;
case 54:
#line 205 "parser.y"
	{insert_code(Sub);
        }
break;
case 56:
#line 211 "parser.y"
	{insert_code(Mult);}
break;
case 57:
#line 212 "parser.y"
	{insert_code(Div);}
break;
case 59:
#line 217 "parser.y"
	{Factor x = {CONSTANT, "", yystack.l_mark[0].num}; factor_push(x);}
break;
case 61:
#line 223 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 64:
#line 237 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
case 65:
#line 245 "parser.y"
	{
                insert_symbol(scope, yystack.l_mark[0].ident, count);
                if (scope == LOCAL_VAR) {
                        insert_code(Alloca);
                };
                count++;
        }
break;
#line 755 "y.tab.c"
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
