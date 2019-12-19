#include "data-structures.h"
#include "symbol-table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LLVMcode *code_head_ptr = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *code_tail_ptr = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

Factorstack fstack = {{}, 0}; /* 整数もしくはレジスタ番号を保持するスタック */

Fundecl *decl_head_ptr = NULL;
Fundecl *decl_tail_ptr = NULL;

extern Node *head_ptr;

int cntr = 1;

Factor factor_pop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top--;
  return tmp;
}

void factor_push(Factor x) {
  fstack.top++;
  fstack.element[fstack.top] = x;
  return;
}

void llvm_generate_code_by_command(LLVMcommand command) {
  LLVMcode *new_code_ptr = llvm_code_by_command(command);

  if (decl_tail_ptr == NULL) {
    /* 関数宣言を処理する段階でリストが作られているので，ありえない */
    fprintf(stderr, "unexpected error\ndecl_tail_ptr is NULL\n");
    exit(1);
  }

  if (code_tail_ptr == NULL) {
    /* 関数定義の命令列の先頭の命令に設定 */
    decl_tail_ptr->codes = new_code_ptr;
    /* 生成中の命令列の末尾の命令として記憶 */
    code_head_ptr = code_tail_ptr = new_code_ptr;
  } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
    code_tail_ptr->next = new_code_ptr; /* 命令列の末尾に追加 */
    code_tail_ptr = new_code_ptr; /* 命令列の末尾の命令として記憶 */
  }
}

LLVMcode *llvm_code_by_command(LLVMcommand command) {
  LLVMcode *code_ptr;
  code_ptr = (LLVMcode *)malloc(sizeof(LLVMcode));
  code_ptr->next = NULL;
  code_ptr->command = command;

  Factor arg1, arg2, retval;

  switch (command) {
    case Alloca:
      retval.type = LOCAL_VAR;
      retval.val = cntr++;
      (code_ptr->args).alloca.retval = retval;
      break;
    case Store:
      arg2 = factor_pop();
      arg1 = factor_pop();
      (code_ptr->args).store.arg1 = arg1;
      (code_ptr->args).store.arg2 = arg2;
      break;
    case Load:
      arg1 = factor_pop();
      (code_ptr->args).load.arg1 = arg1;
      retval.type = LOCAL_VAR;
      retval.val = cntr++;
      (code_ptr->args).load.retval = retval;
      break;
    case Add:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = cntr++;
      (code_ptr->args).add.arg1 = arg1;
      (code_ptr->args).add.arg2 = arg2;
      (code_ptr->args).add.retval = retval;
      break;
    case Sub:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = cntr++;
      (code_ptr->args).sub.arg1 = arg1;
      (code_ptr->args).sub.arg2 = arg2;
      (code_ptr->args).sub.retval = retval;
      break;
    default:
      break;
  }

  factor_push(retval);

  return code_ptr;
}

void decl_insert(char *fname, unsigned arity, Factor *args) {
  Fundecl *decl_ptr = (Fundecl *)malloc(sizeof(Fundecl));
  strcpy(decl_ptr->fname, fname);
  decl_ptr->arity = arity;
  decl_ptr->codes = code_tail_ptr = code_head_ptr = NULL;
  decl_ptr->next = NULL;

  if (!decl_tail_ptr) {
    decl_head_ptr = decl_tail_ptr = decl_ptr;
    return;
  }

  decl_tail_ptr->next = decl_ptr;
  decl_tail_ptr = decl_ptr;

  cntr = 1;

  return;
};

void display_factor(Factor x) {
  switch (x.type) {
    case GLOBAL_VAR:
      printf("@%s", x.name);
      break;
    case LOCAL_VAR:
      printf("%%%d", x.val);
      break;
    case CONSTANT:
      printf("%d", x.val);
      break;
    default:
      break;
  }
  return;
}

void display_llvm_codes(LLVMcode *code_ptr) {
  if (code_ptr == NULL) return;
  printf(" ");
  switch (code_ptr->command) {
    case Alloca:
      display_factor((code_ptr->args).alloca.retval);
      printf(" = alloca i32, align 4\n");
      break;
    case Store:
      printf("store i32 ");
      display_factor((code_ptr->args).store.arg1);
      printf(", i32* ");
      display_factor((code_ptr->args).store.arg2);
      printf(", align 4\n");
      break;
    case Load:
      display_factor((code_ptr->args).load.retval);
      printf(" = load i32, i32* ");
      display_factor((code_ptr->args).load.arg1);
      printf(", align 4\n");
      break;
    case Add:
      display_factor((code_ptr->args).add.retval);
      printf(" = add nsw i32 ");
      display_factor((code_ptr->args).add.arg1);
      printf(", ");
      display_factor((code_ptr->args).add.arg2);
      printf("\n");
      break;
    case Sub:
      display_factor((code_ptr->args).sub.retval);
      printf(" = sub nsw i32 ");
      display_factor((code_ptr->args).sub.arg1);
      printf(", ");
      display_factor((code_ptr->args).sub.arg2);
      printf("\n");
      break;

    default:
      break;
  }
  display_llvm_codes(code_ptr->next);
}

void display_llvm_fun_decl(Fundecl *decl_ptr) {
  if (decl_ptr == NULL) return;
  if (strcmp(decl_ptr->fname, "main") == 0) {
    printf("define i32 @main() #0 {\n");
    display_llvm_codes(decl_ptr->codes);
    printf(" ret i32 0\n}\n");
  } else {
    printf("define void @%s() #0 {\n", decl_ptr->fname);
    display_llvm_codes(decl_ptr->codes);
    printf("}\n");
  };
  if (decl_ptr->next != NULL) {
    printf("\n");
    display_llvm_fun_decl(decl_ptr->next);
  }
  return;
}

void print_global_var() {
  Node *node_ptr = head_ptr;
  while (node_ptr) {
    if (node_ptr->type == GLOBAL_VAR) {
      printf("@%s = common global i32 0, align 4\n", node_ptr->name);
    } else {
      break;
    }
    node_ptr = node_ptr->next;
  }
  return;
}

void display_llvm() {
  print_global_var();
  printf("\n");
  display_llvm_fun_decl(decl_head_ptr);
  return;
}

Factor create_factor_by_name(char *name) {
  Node *node_ptr = lookup(name);
  Factor x;
  x.type = node_ptr->type;
  strcpy(x.name, node_ptr->name);
  x.val = node_ptr->val;
  return x;
}