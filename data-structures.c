#include <stdio.h>
#include <stdlib.h>
#include "data-structures.h"

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;

int cntr = 0;

void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}

Factor factorpop() {
  printf("this is test\n");
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void factorpush(Factor x) {
  printf("push, %s\n", x.vname);
  fstack.top ++;
  fstack.element[fstack.top] = x;
  return;
}

void llvm_expression(LLVMcommand command) {
  LLVMcode *tmp;             /* 生成した命令へのポインタ */
  Factor arg1, arg2, retval; /* 加算の引数・結果 */
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
  tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
  tmp->command = command;  
  /* 命令の種類を加算に設定 */
  arg2 = factorpop();        /* スタックから第2引数をポップ */
  arg1 = factorpop();        /* スタックから第1引数をポップ */
  retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
  retval.val = cntr;         /* 新規のレジスタ番号を取得 */
  cntr ++;                   /* カウンタをインクリメント */
  (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
  (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
  (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
  if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
    if( decltl == NULL ){   /* 解析中の関数がない場合 */
      /* 関数宣言を処理する段階でリストが作られているので，ありえない */
      fprintf(stderr,"unexpected error\n");
    }
    decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
    codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
  } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
    codetl->next = tmp; /* 命令列の末尾に追加 */
    codetl = tmp;       /* 命令列の末尾の命令として記憶 */
  }
  factorpush( retval ); /* 加算の結果をスタックにプッシュ */
  printf("%d\n", retval.val);
}