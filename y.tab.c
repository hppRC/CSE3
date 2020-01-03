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
int i = 0;
int var_mode = FALSE;


#line 34 "parser.y"
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
#line 62 "y.tab.c"

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
    5,   12,   12,   13,   16,   14,   17,   18,   14,    1,
   15,   19,   19,    6,    6,    6,    6,    6,    6,    6,
    6,    6,   20,   31,   33,   21,   32,   34,   32,   35,
   36,   22,   37,   38,   23,   24,   40,   24,    2,   26,
   27,   28,   25,   30,   30,   30,   30,   30,   30,   29,
   29,   29,   29,   29,   41,   41,   41,   42,   42,   42,
   43,   39,   39,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    0,    5,    0,    0,    9,    1,
    2,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    0,    0,    7,    0,    0,    3,    0,
    0,    6,    0,    0,   10,    1,    0,    5,    1,    3,
    4,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    2,    0,   13,   14,    0,   74,    0,   20,
    0,    0,    0,    6,    0,   15,    0,    0,    0,    0,
    0,   40,    0,    0,    0,    3,   24,   25,   26,   27,
   28,   29,   30,   31,   32,   12,   75,    0,    0,   23,
    0,    0,    0,    0,    0,   69,   71,    0,    0,    0,
   65,   68,    0,    0,    0,    0,    0,    0,   16,    0,
   50,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,    0,    0,    0,    0,    0,
    0,    0,    0,   21,    0,   22,    0,   70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,   67,   51,
   41,   52,    0,    0,   18,    0,   35,    0,    0,   48,
    0,    0,    0,   42,   19,    0,   38,   36,    0,    0,
    0,   39,   45,
};
static const short yydgoto[] = {                          2,
   21,   35,    6,   68,   13,   36,   22,    8,    9,   19,
   10,   14,   15,   16,   69,   48,   27,  121,   51,   37,
   38,   39,   40,   41,   42,   43,   44,   45,   58,   59,
  107,  128,  123,  130,   64,  118,  116,  129,   93,  114,
   60,   61,   62,
};
static const short yysindex[] = {                      -229,
 -272,    0, -240, -199,    0, -233, -187, -206,    0, -196,
    0, -181,    0, -173,    0,    0, -199,    0, -159,    0,
 -151, -153, -187,    0, -154,    0, -148, -153, -146, -119,
 -114,    0, -113, -121,  -99,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -199, -196,    0,
 -256, -110, -278, -278, -119,    0,    0,   17,  -83, -155,
    0,    0, -106, -119, -119, -119, -119, -153,    0, -266,
    0, -153, -119, -155, -155, -267, -278, -278, -119, -119,
 -119, -119, -119, -119,    0, -278, -278,  -95,  -63, -221,
 -123, -123,  -91,    0,  -90,    0, -123,    0, -155, -155,
 -123, -123, -123, -123, -123, -123, -153,    0,    0,    0,
    0,    0, -119,  -85,    0,  -69,    0, -153, -123,    0,
 -199, -119,  -56,    0,    0, -123,    0,    0,  -53, -153,
 -153,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -210,    0,    0, -197,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -222,    0,  -84,    0,
  -75,  -82, -184,    0,    0,    0,    0, -252,    0,    0,
    0,    0,    0, -250, -257,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -172,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -135,
    0,    0,    0,    0,    0,    0,    0,  -72,    0,    0,
    0, -252,    0, -101,  -67,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -128, -264,  -66,    0,    0,    0,  -50,    0,  -33,    1,
 -244, -212, -182, -167, -141, -132,  -94,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -94, -175,    0,
 -172,    0, -195,    0,    0,  -36,    0,    0,    0,  -94,
  -94,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  219,    0,  -28,    0,    0,  211,  180,
    0,    0,  207,    0,  110,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -54,  168,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   75,    0,
};
#define YYTABLESIZE 299
static const short yytable[] = {                         50,
   76,   46,   46,   71,   55,   77,   78,   53,   49,   49,
   90,   91,   92,   54,   56,   57,   98,   95,   97,   72,
   25,    3,   72,   54,  101,  102,  103,  104,  105,  106,
   46,   72,   49,   46,    5,   53,    1,   49,    5,   94,
   49,    5,    5,   96,    5,   55,    4,    4,    5,    5,
    4,   77,   78,    4,    4,   55,    4,   11,  119,   10,
    4,    4,  112,   10,   37,    5,   10,  126,    5,   10,
    5,    5,   11,   10,   10,   57,   11,   12,  117,   11,
    4,   17,   11,    4,    4,   57,   11,   11,    4,  124,
   56,    4,   37,   10,    4,   37,   10,   18,    4,    4,
   56,  132,  133,   28,   74,   75,   11,   29,   73,   11,
   30,   73,   20,   31,   23,    4,   59,   32,   33,   86,
   87,    4,   60,   60,   60,   58,   59,   25,   99,  100,
   33,   33,   60,   60,   49,   58,   26,   60,   60,   47,
   34,   60,   60,   60,   60,   60,   60,   52,   60,   77,
   78,   60,   60,   53,   54,   60,   61,   61,   61,   33,
  108,  109,   33,   55,   53,   53,   61,   61,   63,   65,
   66,   61,   61,   56,   57,   61,   61,   61,   61,   61,
   61,   73,   61,   67,   85,   61,   61,   88,  110,   61,
   62,   62,   62,   53,  111,  113,   53,  115,  120,  122,
   62,   62,  127,    9,  131,   62,   62,   17,   53,   62,
   62,   62,   62,   62,   62,   53,   62,   47,   43,   62,
   62,   44,    7,   62,   63,   63,   63,   24,   70,   46,
  125,   89,    0,    0,   63,   63,    0,    0,    0,   63,
   63,    0,    0,   63,   63,   63,   63,   63,   63,    0,
   63,    0,    0,   63,   63,    0,    0,   63,   64,   64,
   64,    0,    0,    0,    0,    0,    0,    0,   64,   64,
    0,    0,    0,   64,   64,    0,    0,   64,   64,   64,
   64,   64,   64,    0,   64,    0,    0,   64,   64,   77,
   78,   64,    0,   79,   80,   81,   82,   83,   84,
};
static const short yycheck[] = {                         28,
   55,  259,  260,  260,  283,  273,  274,  260,  259,  260,
   65,   66,   67,  258,  293,  294,  284,  284,   73,  284,
  287,  294,  287,  268,   79,   80,   81,   82,   83,   84,
  288,  288,  283,  291,  257,  288,  266,  288,  261,   68,
  291,  264,  265,   72,  267,  258,  257,  288,  271,  272,
  261,  273,  274,  264,  265,  268,  267,  291,  113,  257,
  271,  272,  284,  261,  260,  288,  264,  122,  291,  267,
  270,  294,  257,  271,  272,  258,  261,  265,  107,  264,
  291,  288,  267,  294,  257,  268,  271,  272,  261,  118,
  258,  264,  288,  291,  267,  291,  294,  294,  271,  272,
  268,  130,  131,  257,   53,   54,  291,  261,  284,  294,
  264,  287,  294,  267,  288,  288,  258,  271,  272,  275,
  276,  294,  258,  259,  260,  258,  268,  287,   77,   78,
  259,  260,  268,  269,  283,  268,  288,  273,  274,  294,
  294,  277,  278,  279,  280,  281,  282,  294,  284,  273,
  274,  287,  288,  273,  274,  291,  258,  259,  260,  288,
   86,   87,  291,  283,  259,  260,  268,  269,  283,  283,
  292,  273,  274,  293,  294,  277,  278,  279,  280,  281,
  282,  292,  284,  283,  268,  287,  288,  294,  284,  291,
  258,  259,  260,  288,  258,  287,  291,  288,  284,  269,
  268,  269,  259,  288,  258,  273,  274,  283,  291,  277,
  278,  279,  280,  281,  282,  288,  284,  284,  269,  287,
  288,  258,    4,  291,  258,  259,  260,   17,   49,   23,
  121,   64,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,   -1,  287,  288,   -1,   -1,  291,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"$$3 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$3 inblock",
"$$4 :",
"$$5 :",
"proc_decl : PROCEDURE proc_name $$4 LPAREN id_list RPAREN SEMICOLON $$5 inblock",
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
"$$6 :",
"$$7 :",
"if_statement : IF condition THEN $$6 statement $$7 else_statement",
"else_statement :",
"$$8 :",
"else_statement : ELSE $$8 statement",
"$$9 :",
"$$10 :",
"while_statement : WHILE $$9 condition DO $$10 statement",
"$$11 :",
"$$12 :",
"for_statement : FOR IDENT ASSIGN expression $$11 TO expression $$12 DO statement",
"proc_call_statement : proc_call_name",
"$$13 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$13 RPAREN",
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
#line 380 "parser.y"


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
#line 429 "y.tab.c"

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
#line 61 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        debug_symbol_table();
        }
break;
case 2:
#line 70 "parser.y"
	{
        insert_decl("main", 0, NULL);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        insert_code(Alloca);
        insert_code(Store);
        }
break;
case 3:
#line 77 "parser.y"
	{
        back_patch();
        /*insert_code(Load);*/
        /*insert_code(Ret);*/
        }
break;
case 8:
#line 95 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 97 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 15:
#line 117 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 1);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL);
        insert_code(Alloca);
        }
break;
case 16:
#line 124 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 17:
#line 130 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 1;
        }
break;
case 18:
#line 133 "parser.y"
	{
        insert_symbol(PROC_NAME, yystack.l_mark[-5].ident, count);
        insert_decl(yystack.l_mark[-5].ident, count-1, NULL);
        for (i = 0; i < count-1; i++) {
                insert_code(Alloca);
        }
        for (i = 0; i < count-1; i++) {
                insert_code(Store);
        }
        }
break;
case 19:
#line 143 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 33:
#line 176 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 34:
#line 184 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 35:
#line 188 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        }
break;
case 37:
#line 196 "parser.y"
	{
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 38:
#line 200 "parser.y"
	{
        insert_code(Label);
        }
break;
case 39:
#line 203 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 40:
#line 212 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
break;
case 41:
#line 218 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 42:
#line 222 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
break;
case 43:
#line 231 "parser.y"
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
case 44:
#line 242 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 45:
#line 248 "parser.y"
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
case 46:
#line 270 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 47:
#line 275 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Proc);
        printf("called\n");
        }
break;
case 51:
#line 292 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 52:
#line 301 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 54:
#line 312 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 55:
#line 313 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 56:
#line 314 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 57:
#line 315 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 58:
#line 316 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 59:
#line 317 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 63:
#line 324 "parser.y"
	{insert_code(Add);}
break;
case 64:
#line 325 "parser.y"
	{insert_code(Sub);}
break;
case 66:
#line 330 "parser.y"
	{insert_code(Mult);}
break;
case 67:
#line 331 "parser.y"
	{insert_code(Div);}
break;
case 69:
#line 336 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 71:
#line 344 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 72:
#line 352 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 73:
#line 357 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 74:
#line 365 "parser.y"
	{
        if (var_mode) insert_symbol(scope, yystack.l_mark[0].ident, count);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        count++;
        }
break;
case 75:
#line 371 "parser.y"
	{
        if (var_mode) insert_symbol(scope, yystack.l_mark[0].ident, count);
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        count++;
        }
break;
#line 956 "y.tab.c"
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
