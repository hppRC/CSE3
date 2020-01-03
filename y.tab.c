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
int arity_mode = FALSE;

int var_num = 0;
int arity_num = 0;

Factor tmp1_element[100];
int tmp1_top = 0;

Factor tmp2_element[100];
int tmp2_top = 0;

void debug_tmp1() {
        printf("\ntmp1 debug\n");
        printf("|-----------------------|\n");
        printf("| type\t| name\t| val\t|\n");
        printf("|-----------------------|\n");

        for (i = 0; i < tmp1_top; i++) {
        Factor x = tmp1_element[i];
        printf("| %d\t| %s\t| %d\t|\n", x.type, x.name,x.val);
        }
  printf("|-----------------------|\n");
}
void debug_tmp2() {
        printf("\ntmp2 debug\n");
        printf("|-----------------------|\n");
        printf("| type\t| name\t| val\t|\n");
        printf("|-----------------------|\n");

        for (i = 0; i < tmp2_top; i++) {
        Factor x = tmp2_element[i];
        printf("| %d\t| %s\t| %d\t|\n", x.type, x.name,x.val);
        }
  printf("|-----------------------|\n");
}


#line 69 "parser.y"
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
#line 97 "y.tab.c"

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
   19,   15,   20,   20,    6,    6,    6,    6,    6,    6,
    6,    6,    6,   21,   32,   34,   22,   33,   35,   33,
   36,   37,   23,   38,   39,   24,   25,   41,   25,    2,
   27,   28,   29,   26,   31,   31,   31,   31,   31,   31,
   30,   30,   30,   30,   30,   42,   42,   42,   43,   43,
   43,   44,   40,   40,   10,   10,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    0,    3,    0,
    2,    3,    1,    1,    0,    5,    0,    0,    9,    1,
    0,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    0,    0,    7,    0,    0,    3,
    0,    0,    6,    0,    0,   10,    1,    0,    5,    1,
    3,    4,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    8,    0,    0,    0,    7,    0,
    1,    0,    2,    0,   13,   14,    0,   75,    0,   20,
    0,    0,    0,    6,    0,   15,    0,    0,    0,    0,
    0,   41,    0,    0,    0,    3,   25,   26,   27,   28,
   29,   30,   31,   32,   33,   12,   76,    0,    0,   24,
    0,    0,    0,    0,    0,   70,   72,    0,    0,    0,
   66,   69,    0,    0,    0,    0,    0,   21,   16,    0,
   51,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,   71,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   67,   68,   52,
   42,   53,    0,    0,   22,   18,    0,   36,    0,    0,
   49,    0,    0,    0,   43,   19,    0,   39,   37,    0,
    0,    0,   40,   46,
};
static const short yydgoto[] = {                          2,
   21,   35,    6,   68,   13,   36,   22,    8,    9,   19,
   10,   14,   15,   16,   69,   48,   27,  122,   94,   51,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   58,
   59,  107,  129,  124,  131,   64,  119,  117,  130,   93,
  114,   60,   61,   62,
};
static const short yysindex[] = {                      -256,
 -270,    0, -240, -209,    0, -219, -189, -199,    0, -198,
    0, -176,    0, -149,    0,    0, -209,    0, -147,    0,
 -136, -150, -189,    0, -135,    0, -193, -150, -129, -119,
 -125,    0, -115, -114, -110,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -209, -198,    0,
 -254, -113, -276, -276, -119,    0,    0,   21,  -82, -273,
    0,    0, -106, -119, -119, -119, -119,    0,    0, -151,
    0, -150, -119, -273, -273, -154, -276, -276, -119, -119,
 -119, -119, -119, -119,    0, -276, -276,  -95,  -66, -139,
 -258, -258,  -94, -150,  -90,    0, -258,    0, -273, -273,
 -258, -258, -258, -258, -258, -258, -150,    0,    0,    0,
    0,    0, -119,  -85,    0,    0,  -69,    0, -150, -258,
    0, -209, -119,  -58,    0,    0, -258,    0,    0,  -56,
 -150, -150,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -214,    0,    0, -197,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -226,    0,  -84,    0,
  -80,  -83, -179,    0,    0,    0,    0, -246,    0,    0,
    0,    0,    0, -251, -255,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -162,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -131,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -246,    0,  -97,  -63,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -239, -118,  -77,  -79,    0,    0,  -57,    0,  -29,    5,
 -195, -187, -160, -152, -145, -127, -205,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -205, -117,
    0, -162,    0, -204,    0,    0,  -45,    0,    0,    0,
 -205, -205,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  216,    0,  -28,    0,    0,  205,  174,
    0,    0,  203,    0,  105,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -54,
  168,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   47,  -64,    0,
};
#define YYTABLESIZE 303
static const short yytable[] = {                         50,
   76,   86,   87,   47,   47,   71,   55,   50,   50,    1,
   90,   91,   92,   54,   77,   78,   56,   57,   97,   34,
   34,  108,  109,    3,  101,  102,  103,  104,  105,  106,
    5,   50,   47,   72,    5,   47,   50,    5,    5,   50,
    5,   54,    4,   96,    5,    5,    4,    4,   34,    4,
    4,   34,    4,   54,   54,   38,    4,    4,  120,   10,
    5,    5,   55,   10,    5,  115,   10,    5,  127,   10,
   56,   11,   55,   10,   10,   12,    4,   11,  118,    4,
   56,   11,   54,   38,   11,   54,   38,   11,   17,   49,
  125,   11,   11,   10,    4,   18,   10,   58,    4,   74,
   75,    4,  133,  134,    4,   57,   28,   58,    4,    4,
   29,   11,   60,   30,   11,   57,   31,   20,   77,   78,
   32,   33,   60,   99,  100,    4,   61,   61,   61,   98,
   59,    4,   95,   77,   78,   25,   61,   61,   23,   25,
   59,   61,   61,   34,  112,   61,   61,   61,   61,   61,
   61,   26,   61,   53,   54,   61,   61,   63,   47,   61,
   62,   62,   62,   55,   52,   73,   74,   65,   73,   74,
   62,   62,   67,   56,   57,   62,   62,   66,   73,   62,
   62,   62,   62,   62,   62,   85,   62,   88,  110,   62,
   62,  111,  113,   62,   63,   63,   63,  116,  121,  123,
  128,  132,   17,    9,   63,   63,   48,   54,   54,   63,
   63,   44,   45,   63,   63,   63,   63,   63,   63,    7,
   63,   24,   70,   63,   63,   46,  126,   63,   64,   64,
   64,   89,    0,    0,    0,    0,    0,    0,   64,   64,
    0,    0,    0,   64,   64,    0,    0,   64,   64,   64,
   64,   64,   64,    0,   64,    0,    0,   64,   64,    0,
    0,   64,   65,   65,   65,    0,    0,    0,    0,    0,
    0,    0,   65,   65,    0,    0,    0,   65,   65,    0,
    0,   65,   65,   65,   65,   65,   65,    0,   65,    0,
    0,   65,   65,   77,   78,   65,    0,   79,   80,   81,
   82,   83,   84,
};
static const short yycheck[] = {                         28,
   55,  275,  276,  259,  260,  260,  283,  259,  260,  266,
   65,   66,   67,  260,  273,  274,  293,  294,   73,  259,
  260,   86,   87,  294,   79,   80,   81,   82,   83,   84,
  257,  283,  288,  288,  261,  291,  288,  264,  265,  291,
  267,  288,  257,   72,  271,  272,  261,  288,  288,  264,
  265,  291,  267,  259,  260,  260,  271,  272,  113,  257,
  270,  288,  258,  261,  291,   94,  264,  294,  123,  267,
  258,  291,  268,  271,  272,  265,  291,  257,  107,  294,
  268,  261,  288,  288,  264,  291,  291,  267,  288,  283,
  119,  271,  272,  291,  257,  294,  294,  258,  261,   53,
   54,  264,  131,  132,  267,  258,  257,  268,  271,  272,
  261,  291,  258,  264,  294,  268,  267,  294,  273,  274,
  271,  272,  268,   77,   78,  288,  258,  259,  260,  284,
  258,  294,  284,  273,  274,  287,  268,  269,  288,  287,
  268,  273,  274,  294,  284,  277,  278,  279,  280,  281,
  282,  288,  284,  273,  274,  287,  288,  283,  294,  291,
  258,  259,  260,  283,  294,  284,  284,  283,  287,  287,
  268,  269,  283,  293,  294,  273,  274,  292,  292,  277,
  278,  279,  280,  281,  282,  268,  284,  294,  284,  287,
  288,  258,  287,  291,  258,  259,  260,  288,  284,  269,
  259,  258,  283,  288,  268,  269,  284,  291,  288,  273,
  274,  269,  258,  277,  278,  279,  280,  281,  282,    4,
  284,   17,   49,  287,  288,   23,  122,  291,  258,  259,
  260,   64,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
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
"$$6 :",
"inblock : var_decl_part $$6 statement",
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
"$$7 :",
"$$8 :",
"if_statement : IF condition THEN $$7 statement $$8 else_statement",
"else_statement :",
"$$9 :",
"else_statement : ELSE $$9 statement",
"$$10 :",
"$$11 :",
"while_statement : WHILE $$10 condition DO $$11 statement",
"$$12 :",
"$$13 :",
"for_statement : FOR IDENT ASSIGN expression $$12 TO expression $$13 DO statement",
"proc_call_statement : proc_call_name",
"$$14 :",
"proc_call_statement : proc_call_name LPAREN arg_list $$14 RPAREN",
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
#line 456 "parser.y"


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
#line 467 "y.tab.c"

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
#line 96 "parser.y"
	{
        if ((fp = fopen(filename, "w")) == NULL) return EXIT_FAILURE;
        display_llvm();
        fclose(fp);
        }
break;
case 2:
#line 104 "parser.y"
	{
        insert_decl("main", 0, NULL);
        Factor x = {CONSTANT, "1", 0};
        factor_push(x);
        /*mainが引数をとるようになるならここにoverwriteの処理を挟む*/
        reg_counter = 1;
        insert_code(Alloca);
        insert_code(Store);
        }
break;
case 3:
#line 113 "parser.y"
	{
        back_patch();
        /*insert_code(Load);*/
        /*insert_code(Ret);*/
        }
break;
case 8:
#line 131 "parser.y"
	{
        var_mode = TRUE;
        }
break;
case 9:
#line 133 "parser.y"
	{
        var_mode = FALSE;
        }
break;
case 15:
#line 153 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        var_num = 0;
        arity_num = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[-1].ident, 0);
        insert_decl(yystack.l_mark[-1].ident, 0, NULL);
        reg_counter = count + 1;
        count++;
        }
break;
case 16:
#line 163 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 17:
#line 169 "parser.y"
	{
        scope = LOCAL_VAR;
        count = 0;
        insert_symbol(PROC_NAME, yystack.l_mark[0].ident, count);
        arity_mode = TRUE;
        }
break;
case 18:
#line 174 "parser.y"
	{
                arity_mode = FALSE;
                /*レジスタの値は返り値分一つ増やしておく*/
                /*reg_counter: 引数(n個),返り値(1個),局所変数(m個), 中身(k個)の順に番号づけされる*/
                insert_decl(yystack.l_mark[-5].ident, count, NULL);
                reg_counter = count + 1;
                count++;
        }
break;
case 19:
#line 182 "parser.y"
	{
        back_patch();
        delete_local_symbol();
        scope = GLOBAL_VAR;
        }
break;
case 21:
#line 197 "parser.y"
	{
                for (i = 0; i < var_num + arity_num; i++) {
                        tmp1_element[i] = factor_pop();
                        tmp1_top++;
                }
                for (i = 0; i < var_num + arity_num; i++) {
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
                overwrite_symbol_val(var_num, arity_num);
        }
break;
case 34:
#line 239 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Store);
        }
break;
case 35:
#line 247 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 36:
#line 251 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        }
break;
case 38:
#line 259 "parser.y"
	{
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 39:
#line 263 "parser.y"
	{
        insert_code(Label);
        }
break;
case 40:
#line 266 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(reg_counter);
        insert_code(Label);
        }
break;
case 41:
#line 275 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        tmp = reg_counter;
        insert_code(Label);
        }
break;
case 42:
#line 281 "parser.y"
	{
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 43:
#line 285 "parser.y"
	{
        insert_code(BrUncond);
        label_push(reg_counter);
        label_push(tmp);
        insert_code(Label);
        }
break;
case 44:
#line 294 "parser.y"
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
case 45:
#line 305 "parser.y"
	{
        set_cmp_type(SLE);
        insert_code(Icmp);
        insert_code(BrCond);
        insert_code(Label);
        }
break;
case 46:
#line 311 "parser.y"
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
case 47:
#line 333 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 48:
#line 338 "parser.y"
	{
        Factor x = create_factor_by_name(yystack.l_mark[-2].ident);
        factor_push(x);
        insert_code(Proc);
        }
break;
case 52:
#line 354 "parser.y"
	{
        set_read_flag(TRUE);
        Factor x = create_factor_by_name(yystack.l_mark[-1].ident);
        factor_push(x);
        insert_code(Read);
        }
break;
case 53:
#line 363 "parser.y"
	{
        set_write_flag(TRUE);
        insert_code(Write);
        }
break;
case 55:
#line 374 "parser.y"
	{set_cmp_type(EQUAL); insert_code(Icmp);}
break;
case 56:
#line 375 "parser.y"
	{set_cmp_type(NE); insert_code(Icmp);}
break;
case 57:
#line 376 "parser.y"
	{set_cmp_type(SLT); insert_code(Icmp);}
break;
case 58:
#line 377 "parser.y"
	{set_cmp_type(SLE); insert_code(Icmp);}
break;
case 59:
#line 378 "parser.y"
	{set_cmp_type(SGT); insert_code(Icmp);}
break;
case 60:
#line 379 "parser.y"
	{set_cmp_type(SGE); insert_code(Icmp);}
break;
case 64:
#line 386 "parser.y"
	{insert_code(Add);}
break;
case 65:
#line 387 "parser.y"
	{insert_code(Sub);}
break;
case 67:
#line 392 "parser.y"
	{insert_code(Mult);}
break;
case 68:
#line 393 "parser.y"
	{insert_code(Div);}
break;
case 70:
#line 398 "parser.y"
	{
        Factor x = {CONSTANT, "", yystack.l_mark[0].num};
        factor_push(x);
        }
break;
case 72:
#line 406 "parser.y"
	{
        /*ここの記号表に各処理をいじらないとだめそう*/
        /*記号表のvalの値を書き換えていく*/
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        insert_code(Load);
        }
break;
case 73:
#line 416 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 74:
#line 421 "parser.y"
	{
        Factor x = factor_pop();
        arity_push(x);
        factor_push(x);
        }
break;
case 75:
#line 429 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
case 76:
#line 441 "parser.y"
	{
        if (var_mode) {
                if (scope == LOCAL_VAR) var_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        if (arity_mode) {
                arity_num++;
                insert_symbol(scope, yystack.l_mark[0].ident, count++);
        }
        Factor x = create_factor_by_name(yystack.l_mark[0].ident);
        factor_push(x);
        }
break;
#line 1036 "y.tab.c"
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
