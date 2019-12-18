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

#include "data-structures.h"
#include "symbol-table.h"


extern void init_fstack();
extern Factor factor_pop();
extern void factor_push(Factor x);
extern void llvm_expression(LLVMcommand command);

extern void insert(int type, char *name, int val);
extern Node *lookup(char *);
extern void delete_local_node(void);


int scope = GLOBAL_VAR;

#line 30 "parser.y"
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
#line 58 "y.tab.c"

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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   13,   10,   11,   12,   14,   14,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   15,   16,   26,
   26,   17,   18,   19,   27,   21,   22,   23,   20,   25,
   25,   25,   25,   25,   25,   24,   24,   24,   24,   24,
   28,   28,   28,   29,   29,   29,   30,   31,   31,    7,
    7,
};
static const short yylen[] = {                            2,
    5,    3,    0,    2,    3,    1,    2,    0,    2,    3,
    1,    1,    0,    5,    1,    2,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    5,    0,
    2,    4,    8,    1,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    1,    3,    1,
    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   60,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   15,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   34,    0,
    5,   61,   13,   18,    0,    0,    0,    0,    0,   55,
   57,    0,    0,    0,   51,   54,    0,    0,    0,    0,
   10,    0,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   14,   17,    0,   56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,   53,   37,
   32,   38,   16,    0,    0,   29,    0,   31,    0,   33,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   85,   62,   45,   30,   31,   32,   33,   34,   35,
   36,   37,   38,   52,   53,  106,   39,   54,   55,   56,
    0,
};
static const short yysindex[] = {                      -257,
 -279,    0, -259, -248, -243, -237, -196, -202,    0,    0,
 -194,    0, -198, -162, -187,    0,    0, -248, -190,    0,
 -160, -162, -163,  -44, -135,  -44, -133, -153,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -196,
    0,    0,    0,    0, -258, -134, -172, -172,  -44,    0,
    0,  -20, -109, -223,    0,    0, -128,  -86,  -44,  -44,
    0, -248,    0, -162,  -44, -223, -223,  -98, -172, -172,
  -44,  -44,  -44,  -44,  -44,  -44, -162, -172, -172, -111,
 -162,  -71, -147, -162,    0,    0, -266,    0, -223, -223,
 -147, -147, -147, -147, -147, -147,  -82,    0,    0,    0,
    0,    0,    0,  -44, -162,    0, -166,    0, -162,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -226,    0,    0, -200,    0,    0,    0,
 -108,    0,    0, -110,    0,    0,    0, -251,    0,    0,
    0, -211,    0,    0,    0,    0,    0, -255,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -191,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -144,    0,    0,    0,    0,    0,    0,
    0, -182,    0, -211,    0, -117,  -90,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -241,    0,    0,    0,
 -241,    0, -142, -106,    0,    0,    0,    0,  -63,  -36,
 -224, -210, -184, -180, -145, -113, -228,    0,    0,    0,
    0,    0,    0,    0, -241,    0,    0,    0, -241,    0,
};
static const short yygindex[] = {                         0,
    0,  123,    0,  -22,    0,  175,    0,    0,  159,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -48,  174,    0,    0,   50,   75,    0,
    0,
};
#define YYTABLESIZE 262
static const short yytable[] = {                         44,
   68,   63,  104,   35,   35,    4,   69,   70,    1,    4,
   82,   83,    4,    4,    3,    4,   87,   39,   39,    4,
    4,    5,   91,   92,   93,   94,   95,   96,    4,   64,
    3,   30,   35,   40,    3,   35,    4,    3,    3,    4,
    3,   86,    4,   40,    3,    3,   39,   41,   39,   39,
   10,   78,   79,   12,   97,  107,    8,   41,  101,   30,
    8,  103,   30,    8,    3,    9,    8,    3,   13,    9,
    8,    8,    9,   43,    3,    9,   39,   42,    3,    9,
    9,    3,  108,   43,    3,   18,  110,   42,    3,    3,
    8,  109,   19,    8,   22,   20,   66,   67,   23,    9,
   40,   24,    9,   42,   25,    3,   69,   70,   26,   27,
   49,    3,   45,   46,   46,   46,   28,   28,   89,   90,
   50,   51,   45,   46,   46,   69,   70,   43,   46,   46,
   46,   28,   46,   46,   46,   46,   46,   46,   60,   46,
   47,   47,   47,   46,   44,   28,   46,   57,   28,   59,
   47,   47,   98,   99,   44,   47,   47,   65,   77,   47,
   47,   47,   47,   47,   47,   80,   47,   48,   48,   48,
   47,   81,  100,   47,   69,   70,  105,   48,   48,    7,
   39,   39,   48,   48,   84,   88,   48,   48,   48,   48,
   48,   48,   41,   48,   49,   49,   49,   48,   61,   58,
   48,   69,   70,    0,   49,   49,    0,    0,    0,   49,
   49,    0,  102,   49,   49,   49,   49,   49,   49,    0,
   49,   50,   50,   50,   49,    0,    0,   49,   47,   48,
    0,   50,   50,    0,    0,    0,   50,   50,   49,    0,
   50,   50,   50,   50,   50,   50,    0,   50,   50,   51,
    0,   50,   69,   70,   50,    0,   71,   72,   73,   74,
   75,   76,
};
static const short yycheck[] = {                         22,
   49,  260,  269,  259,  260,  257,  273,  274,  266,  261,
   59,   60,  264,  265,  294,  267,   65,  259,  260,  271,
  272,  270,   71,   72,   73,   74,   75,   76,  288,  288,
  257,  260,  288,  258,  261,  291,  288,  264,  265,  291,
  267,   64,  294,  268,  271,  272,  288,  258,  260,  291,
  294,  275,  276,  291,   77,  104,  257,  268,   81,  288,
  261,   84,  291,  264,  291,  257,  267,  294,  265,  261,
  271,  272,  264,  258,  257,  267,  288,  258,  261,  271,
  272,  264,  105,  268,  267,  288,  109,  268,  271,  272,
  291,  258,  287,  294,  257,  294,   47,   48,  261,  291,
  288,  264,  294,  294,  267,  288,  273,  274,  271,  272,
  283,  294,  258,  258,  259,  260,  259,  260,   69,   70,
  293,  294,  268,  268,  269,  273,  274,  288,  273,  274,
  294,  294,  277,  278,  279,  280,  281,  282,  292,  284,
  258,  259,  260,  288,  258,  288,  291,  283,  291,  283,
  268,  269,   78,   79,  268,  273,  274,  292,  268,  277,
  278,  279,  280,  281,  282,  294,  284,  258,  259,  260,
  288,  258,  284,  291,  273,  274,  259,  268,  269,  288,
  291,  288,  273,  274,   62,  284,  277,  278,  279,  280,
  281,  282,   18,  284,  258,  259,  260,  288,   40,   26,
  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,  284,  277,  278,  279,  280,  281,  282,   -1,
  284,  258,  259,  260,  288,   -1,   -1,  291,  273,  274,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,  283,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,  293,  294,
   -1,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
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
"outblock : var_decl_part subprog_decl_part statement",
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
"$$1 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$1 inblock",
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
"if_statement : IF condition THEN statement else_statement",
"else_statement :",
"else_statement : ELSE statement",
"while_statement : WHILE condition DO statement",
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
#line 234 "parser.y"
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
#line 390 "y.tab.c"

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
case 13:
#line 91 "parser.y"
	{scope = LOCAL_VAR;}
break;
case 14:
#line 93 "parser.y"
	{delete_local_node();
        scope = GLOBAL_VAR;}
break;
case 15:
#line 99 "parser.y"
	{insert(scope, yystack.l_mark[0].ident, 1);}
break;
case 28:
#line 125 "parser.y"
	{lookup(yystack.l_mark[-2].ident);}
break;
case 33:
#line 143 "parser.y"
	{lookup(yystack.l_mark[-6].ident);}
break;
case 35:
#line 152 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 37:
#line 161 "parser.y"
	{lookup(yystack.l_mark[-1].ident);}
break;
case 49:
#line 186 "parser.y"
	{llvm_add();}
break;
case 57:
#line 204 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 60:
#line 214 "parser.y"
	{
        insert(scope, yystack.l_mark[0].ident, 1);
        Factor x;
        x.type = scope;
        strcpy(x.name, yystack.l_mark[0].ident);
        x.val = 1;
        factor_push(x);
        }
break;
case 61:
#line 223 "parser.y"
	{
        insert(scope, yystack.l_mark[0].ident, 1);
        Factor x;
        x.type = scope;
        strcpy(x.name, yystack.l_mark[0].ident);
        x.val = 1;
        factor_push(x);
        }
break;
#line 655 "y.tab.c"
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
