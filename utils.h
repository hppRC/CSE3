#ifndef UTILS_H
#define UTILS_H

typedef enum { FALSE, TRUE } Bool;

/* 記号表の管理 + 変数・定数の区別用 */
typedef enum {
  GLOBAL_VAR, /* 大域変数 */
  LOCAL_VAR,  /* 局所変数 */
  PROC_NAME,  /* 手続き   */
  FUNC_NAME,  /* 関数     */
  CONSTANT    /* 定数     */
} Scope;

/* 変数もしくは定数の型 */
typedef struct {
  Scope type;     /* 変数（のレジスタ）か整数の区別 */
  char name[256]; /* 変数の場合の変数名 */
  int val; /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

typedef struct {
  Factor element[100];
  unsigned int top;
} FactorStack;

/* LLVM命令名の定義 */
typedef enum {
  Alloca,   /* alloca */
  Store,    /* store  */
  Load,     /* load   */
  BrUncond, /* br     */
  BrCond,   /* brc    */
  Label,    /* label  */
  Add,      /* add    */
  Sub,      /* sub    */
  Mult,     /* mult   */
  Div,      /* div    */
  Icmp,     /* icmp   */
  Ret,      /* ret    */
  Proc,     /* proc   */
  Func,     /* func   */
  Read,     /* read   */
  Write     /* write  */
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum {
  EQUAL, /* eq （==）*/
  NE,    /* ne （!=）*/
  SLT,   /* slt （<，符号付き） */
  SLE,   /* sle （<=，符号付き）*/
  SGT,   /* sgt （>，符号付き） */
  SGE    /* sge （>=，符号付き）*/
} Cmptype;

typedef struct llvmcode {
  LLVMcommand command; /* 命令名 */
  union {              /* 命令の引数 */
    struct {           /* alloca */
      Factor retval;
    } alloca;
    struct { /* store  */
      Factor arg1;
      Factor arg2;
    } store;
    struct { /* load   */
      Factor arg1;
      Factor retval;
    } load;
    struct { /* br     */
      int arg1;
    } bruncond;
    struct { /* brc    */
      Factor arg1;
      int arg2;
      int arg3;
    } brcond;
    struct { /* label  */
      int l;
    } label;
    struct { /* add    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } add;
    struct { /* sub    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } sub;
    struct { /* mult   */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } mult;
    struct { /* div    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } div;
    struct { /* icmp   */
      Cmptype type;
      Factor arg1;
      Factor arg2;
      Factor retval;
    } icmp;
    struct { /* ret    */
      Factor arg1;
    } ret;
    struct { /* proc   */
      Factor arg1;
      Factor element[100];
      unsigned int top;
    } proc;
    struct { /* func   */
      Factor arg1;
      Factor retval;
      Factor element[100];
      unsigned int top;
    } func;
    struct { /* ret    */
      Factor arg1;
      Factor retval;
    } read;
    struct { /* ret    */
      Factor arg1;
      Factor retval;
    } write;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

typedef struct fundecl {
  char fname[256];      /* 関数名                      */
  unsigned arity;       /* 引数個数                    */
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
  Scope type;
} Fundecl;

typedef struct _Symbol {
  Scope type;
  int val;
  char *name;
  struct _Symbol *next;
  struct _Symbol *prev;
} Symbol;

#endif
