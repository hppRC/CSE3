#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "utils.h"

/* 変数もしくは定数の型 */
typedef struct
{
  Scope type;      /* 変数（のレジスタ）か整数の区別 */
  char vname[256]; /* 変数の場合の変数名 */
  int val;         /* 整数の場合はその値，変数の場合は割り当てたレジスタ番号 */
} Factor;

/* 変数もしくは定数のためのスタック */
typedef struct
{
  Factor element[100]; /* スタック（最大要素数は100まで） */
  unsigned int top;    /* スタックのトップの位置         */
} Factorstack;

/* LLVM命令名の定義 */
typedef enum
{
  Alloca,   /* alloca */
  Store,    /* store  */
  Load,     /* load   */
  BrUncond, /* br     */
  BrCond,   /* brc    */
  Label,    /* label  */
  Add,      /* add    */
  Sub,      /* sub    */
  Icmp,     /* icmp   */
  Ret       /* ret    */
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum
{
  EQUAL, /* eq （==）*/
  NE,    /* ne （!=）*/
  SGT,   /* sgt （>，符号付き） */
  SGE,   /* sge （>=，符号付き）*/
  SLT,   /* slt （<，符号付き） */
  SLE    /* sle （<=，符号付き）*/
} Cmptype;

typedef struct llvmcode
{
  LLVMcommand command; /* 命令名 */
  union {              /* 命令の引数 */
    struct
    { /* alloca */
      Factor retval;
    } alloca;
    struct
    { /* store  */
      Factor arg1;
      Factor arg2;
    } store;
    struct
    { /* load   */
      Factor arg1;
      Factor retval;
    } load;
    struct
    { /* br     */
      int arg1;
    } bruncond;
    struct
    { /* brc    */
      Factor arg1;
      int arg2;
      int arg3;
    } brcond;
    struct
    { /* label  */
      int l;
    } label;
    struct
    { /* add    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } add;
    struct
    { /* sub    */
      Factor arg1;
      Factor arg2;
      Factor retval;
    } sub;
    struct
    { /* icmp   */
      Cmptype type;
      Factor arg1;
      Factor arg2;
      Factor retval;
    } icmp;
    struct
    { /* ret    */
      Factor arg1;
    } ret;
  } args;
  /* 次の命令へのポインタ */
  struct llvmcode *next;
} LLVMcode;

typedef struct fundecl
{
  char fname[256];      /* 関数名                      */
  unsigned arity;       /* 引数個数                    */
  Factor args[10];      /* 引数名                      */
  LLVMcode *codes;      /* 命令列の線形リストへのポインタ */
  struct fundecl *next; /* 次の関数定義へのポインタ      */
} Fundecl;

#endif