#include "data-structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LLVMcode *code_head_ptr = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *code_tail_ptr = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

Factorstack fstack = {{}, 0}; /* 整数もしくはレジスタ番号を保持するスタック */

Fundecl *decl_head_ptr = NULL;
Fundecl *decl_tail_ptr = NULL;

int cntr = 0;

Factor factor_pop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top--;
  printf("pop\t| type: %d name: %s,\ttop: %d\n", tmp.type, tmp.name,
         fstack.top);
  return tmp;
}

void factor_push(Factor x) {
  printf("push\t| type: %d name: %s,\ttop:%d\n", x.type, x.name, fstack.top);
  fstack.top++;
  fstack.element[fstack.top] = x;
  return;
}

void llvm_add() {
  LLVMcode *tmp;
  tmp = (LLVMcode *)malloc(sizeof(LLVMcode));
  tmp->next = NULL;
  tmp->command = Add;

  Factor arg1, arg2, retval;
  arg2 = factor_pop();
  arg1 = factor_pop();
  retval.type = LOCAL_VAR;
  retval.val = cntr;
  cntr++;

  (tmp->args).add.arg1 = arg1;
  (tmp->args).add.arg2 = arg2;
  (tmp->args).add.retval = retval;

  if (decl_tail_ptr == NULL) {
    /* 関数宣言を処理する段階でリストが作られているので，ありえない */
    fprintf(stderr, "unexpected error\n");
    exit(1);
  }

  if (code_tail_ptr == NULL) {
    decl_tail_ptr->codes = tmp; /* 関数定義の命令列の先頭の命令に設定 */
    /* 生成中の命令列の末尾の命令として記憶 */
    code_head_ptr = code_tail_ptr = tmp;
  } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
    code_tail_ptr->next = tmp; /* 命令列の末尾に追加 */
    code_tail_ptr = tmp;       /* 命令列の末尾の命令として記憶 */
  }

  factor_push(retval); /* 加算の結果をスタックにプッシュ */
  printf("%d\n", retval.val);
}

void decl_insert(char *fname, unsigned arity, Factor *args, LLVMcode *codes) {
  printf("decl_insert | name: %s, arity:%d\n", fname, arity);
  Fundecl *decl_ptr = (Fundecl *)malloc(sizeof(Fundecl));
  strcpy(decl_ptr->fname, fname);
  decl_ptr->arity = arity;
  decl_ptr->codes = codes;
  decl_ptr->next = NULL;

  if (!decl_tail_ptr) {
    decl_head_ptr = decl_tail_ptr = decl_ptr;
    return;
  }

  decl_tail_ptr->next = decl_ptr;
  decl_tail_ptr = decl_ptr;

  return;
};
