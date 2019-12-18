#include "data-structures.h"
#include <stdio.h>
#include <stdlib.h>

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

Fundecl *decl_head_ptr = NULL;
Fundecl *decl_tail_ptr = NULL;

int cntr = 0;

void init_fstack() { /* fstackの初期化 */
  fstack.top = 0;
  return;
}

Factor factor_pop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top--;
  printf("this is pop test, name: %s, top:%d\n", tmp.vname, fstack.top);
  return tmp;
}

void factor_push(Factor x) {
  printf("this is push test, name: %s, top:%d\n", x.vname, fstack.top);
  fstack.top++;
  fstack.element[fstack.top] = x;
  return;
}

void llvm_expression(LLVMcommand command) {
  LLVMcode *tmp;
  Factor arg1, arg2, retval;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = command;
  arg2 = factor_pop();
  arg1 = factor_pop();
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;
  (tmp->args).add.arg1 = arg1;
  (tmp->args).add.arg2 = arg2;
  (tmp->args).add.retval = retval;
  if (codetl == NULL) {
    if (decl_tail_ptr == NULL) {
      fprintf(stderr, "unexpected error\n");
      exit(1);
    }
    decl_tail_ptr->codes = tmp; /* 関数定義の命令列の先頭の命令に設定 */
    codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
  } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
    codetl->next = tmp; /* 命令列の末尾に追加 */
    codetl = tmp;       /* 命令列の末尾の命令として記憶 */
  }
  factor_push(retval); /* 加算の結果をスタックにプッシュ */
  printf("%d\n", retval.val);
}