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
#include "composer.h"

extern LLVMcode *codehd; /* 命令列の先頭のアドレスを保持するポインタ */
extern LLVMcode *codetl; /* 命令列の末尾のアドレスを保持するポインタ */

extern Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
extern Fundecl *declhd;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
extern Fundecl *decltl;

extern Node *lookup(char *);
extern void insert();
extern void delete();


int scope = GLOBAL_VAR;

#line 32 "parser.y"
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
#line 60 "y.tab.c"

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
    1,    0,    2,    3,    3,    6,    6,    7,    4,    4,
    9,    9,   10,   14,   11,   12,   13,   15,   15,    5,
    5,    5,    5,    5,    5,    5,    5,    5,   16,   17,
   27,   27,   18,   19,   20,   28,   22,   23,   24,   21,
   26,   26,   26,   26,   26,   26,   25,   25,   25,   25,
   25,   29,   29,   29,   30,   30,   30,   31,   32,   32,
    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    0,    5,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    5,
    0,    2,    4,    8,    1,    1,    3,    4,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    2,    3,
    3,    1,    3,    3,    1,    1,    3,    1,    1,    3,
    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    7,
   61,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    3,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   35,
    0,    6,   62,   14,   19,    0,    0,    0,    0,    0,
   56,   58,    0,    0,    0,   52,   55,    0,    0,    0,
    0,   11,    0,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,   18,    0,   57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   53,   54,
   38,   33,   39,   17,    0,    0,   30,    0,   32,    0,
   34,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   15,   30,    9,   10,   12,   16,   17,
   18,   22,   86,   63,   46,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   53,   54,  107,   40,   55,   56,
   57,    0,
};
static const short yysindex[] = {                         0,
    0, -257, -279, -259, -248, -243, -237, -196, -202,    0,
    0, -194,    0, -198, -162, -187,    0,    0, -248, -190,
    0, -160, -162, -163,  -44, -135,  -44, -133, -153,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -196,    0,    0,    0,    0, -258, -134, -172, -172,  -44,
    0,    0,  -20, -109, -223,    0,    0, -128,  -86,  -44,
  -44,    0, -248,    0, -162,  -44, -223, -223,  -98, -172,
 -172,  -44,  -44,  -44,  -44,  -44,  -44, -162, -172, -172,
 -111, -162,  -71, -147, -162,    0,    0, -266,    0, -223,
 -223, -147, -147, -147, -147, -147, -147,  -82,    0,    0,
    0,    0,    0,    0,  -44, -162,    0, -166,    0, -162,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -226,    0,    0, -200,    0,    0,
    0, -108,    0,    0, -110,    0,    0,    0, -251,    0,
    0,    0, -211,    0,    0,    0,    0,    0, -255,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -191,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -144,    0,    0,    0,    0,    0,
    0,    0, -182,    0, -211,    0, -117,  -90,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -241,    0,    0,
    0, -241,    0, -142, -106,    0,    0,    0,    0,  -63,
  -36, -224, -210, -184, -180, -145, -113, -228,    0,    0,
    0,    0,    0,    0,    0, -241,    0,    0,    0, -241,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,  122,    0,  -23,    0,  174,    0,    0,  158,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -49,  173,    0,    0,   49,   74,
    0,    0,
};
#define YYTABLESIZE 262
static const short yytable[] = {                         45,
   69,   64,  105,   36,   36,    5,   70,   71,    3,    5,
   83,   84,    5,    5,    4,    5,   88,   40,   40,    5,
    5,    6,   92,   93,   94,   95,   96,   97,    5,   65,
    4,   31,   36,   41,    4,   36,    5,    4,    4,    5,
    4,   87,    5,   41,    4,    4,   40,   42,   40,   40,
   11,   79,   80,   13,   98,  108,    9,   42,  102,   31,
    9,  104,   31,    9,    4,   10,    9,    4,   14,   10,
    9,    9,   10,   44,    4,   10,   40,   43,    4,   10,
   10,    4,  109,   44,    4,   19,  111,   43,    4,    4,
    9,  110,   20,    9,   23,   21,   67,   68,   24,   10,
   41,   25,   10,   43,   26,    4,   70,   71,   27,   28,
   50,    4,   46,   47,   47,   47,   29,   29,   90,   91,
   51,   52,   46,   47,   47,   70,   71,   44,   47,   47,
   47,   29,   47,   47,   47,   47,   47,   47,   61,   47,
   48,   48,   48,   47,   45,   29,   47,   58,   29,   60,
   48,   48,   99,  100,   45,   48,   48,   66,   78,   48,
   48,   48,   48,   48,   48,   81,   48,   49,   49,   49,
   48,   82,  101,   48,   70,   71,  106,   49,   49,    8,
   40,   40,   49,   49,   85,   89,   49,   49,   49,   49,
   49,   49,   42,   49,   50,   50,   50,   49,   62,   59,
   49,   70,   71,    0,   50,   50,    0,    0,    0,   50,
   50,    0,  103,   50,   50,   50,   50,   50,   50,    0,
   50,   51,   51,   51,   50,    0,    0,   50,   48,   49,
    0,   51,   51,    0,    0,    0,   51,   51,   50,    0,
   51,   51,   51,   51,   51,   51,    0,   51,   51,   52,
    0,   51,   70,   71,   51,    0,   72,   73,   74,   75,
   76,   77,
};
static const short yycheck[] = {                         23,
   50,  260,  269,  259,  260,  257,  273,  274,  266,  261,
   60,   61,  264,  265,  294,  267,   66,  259,  260,  271,
  272,  270,   72,   73,   74,   75,   76,   77,  288,  288,
  257,  260,  288,  258,  261,  291,  288,  264,  265,  291,
  267,   65,  294,  268,  271,  272,  288,  258,  260,  291,
  294,  275,  276,  291,   78,  105,  257,  268,   82,  288,
  261,   85,  291,  264,  291,  257,  267,  294,  265,  261,
  271,  272,  264,  258,  257,  267,  288,  258,  261,  271,
  272,  264,  106,  268,  267,  288,  110,  268,  271,  272,
  291,  258,  287,  294,  257,  294,   48,   49,  261,  291,
  288,  264,  294,  294,  267,  288,  273,  274,  271,  272,
  283,  294,  258,  258,  259,  260,  259,  260,   70,   71,
  293,  294,  268,  268,  269,  273,  274,  288,  273,  274,
  294,  294,  277,  278,  279,  280,  281,  282,  292,  284,
  258,  259,  260,  288,  258,  288,  291,  283,  291,  283,
  268,  269,   79,   80,  268,  273,  274,  292,  268,  277,
  278,  279,  280,  281,  282,  294,  284,  258,  259,  260,
  288,  258,  284,  291,  273,  274,  259,  268,  269,  288,
  291,  288,  273,  274,   63,  284,  277,  278,  279,  280,
  281,  282,   19,  284,  258,  259,  260,  288,   41,   27,
  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,  284,  277,  278,  279,  280,  281,  282,   -1,
  284,  258,  259,  260,  288,   -1,   -1,  291,  273,  274,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,  283,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,  293,  294,
   -1,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
  281,  282,
};
#define YYFINAL 1
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
"$$1 :",
"program : $$1 PROGRAM IDENT SEMICOLON outblock PERIOD",
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
#line 235 "parser.y"
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
#line 396 "y.tab.c"

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
#line 56 "parser.y"
	{init_fstack();}
break;
case 14:
#line 94 "parser.y"
	{scope = LOCAL_VAR;}
break;
case 15:
#line 96 "parser.y"
	{delete();
        scope = GLOBAL_VAR;}
break;
case 16:
#line 102 "parser.y"
	{insert(scope, yystack.l_mark[0].ident, 1);}
break;
case 29:
#line 128 "parser.y"
	{lookup(yystack.l_mark[-2].ident);}
break;
case 34:
#line 146 "parser.y"
	{lookup(yystack.l_mark[-6].ident);}
break;
case 36:
#line 155 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 38:
#line 164 "parser.y"
	{lookup(yystack.l_mark[-1].ident);}
break;
case 50:
#line 189 "parser.y"
	{llvm_expression(Add);}
break;
case 51:
#line 191 "parser.y"
	{llvm_expression(Sub);}
break;
case 58:
#line 208 "parser.y"
	{
        Node *node = lookup(yystack.l_mark[0].ident);
        Factor x;
        x.type = node->type;
        strcpy(x.vname, node->name);
        x.val = node->val;
        factorpush(x);
        }
break;
case 61:
#line 225 "parser.y"
	{
        insert(scope, yystack.l_mark[0].ident, 1);
        }
break;
case 62:
#line 229 "parser.y"
	{
        insert(scope, yystack.l_mark[0].ident, 1);
        }
break;
#line 666 "y.tab.c"
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
