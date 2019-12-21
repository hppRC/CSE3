#include "data-structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol-table.h"

static LLVMcode *code_head_ptr = NULL;
static LLVMcode *code_tail_ptr = NULL;

static Factorstack fstack = {{}, 0};

static Fundecl *decl_head_ptr = NULL;
static Fundecl *decl_tail_ptr = NULL;

static int reg_counter = 1;

static Cmptype cmp_type;

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

void insert_code(LLVMcommand command) {
  LLVMcode *new_code_ptr = generate_code(command);

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

LLVMcode *generate_code(LLVMcommand command) {
  LLVMcode *code_ptr;
  code_ptr = (LLVMcode *)malloc(sizeof(LLVMcode));
  code_ptr->next = NULL;
  code_ptr->command = command;

  Factor arg1, arg2, retval;

  switch (command) {
    case Alloca:
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
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
      retval.val = reg_counter++;
      (code_ptr->args).load.retval = retval;
      break;
    case BrUncond:
      break;
    case BrCond:
      break;
    case Label:
      (code_ptr->args).label.l = reg_counter++;
      break;
    case Add:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).add.arg1 = arg1;
      (code_ptr->args).add.arg2 = arg2;
      (code_ptr->args).add.retval = retval;
      break;
    case Sub:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).sub.arg1 = arg1;
      (code_ptr->args).sub.arg2 = arg2;
      (code_ptr->args).sub.retval = retval;
      break;
    case Mult:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).mult.arg1 = arg1;
      (code_ptr->args).mult.arg2 = arg2;
      (code_ptr->args).mult.retval = retval;
      break;
    case Div:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).div.arg1 = arg1;
      (code_ptr->args).div.arg2 = arg2;
      (code_ptr->args).div.retval = retval;
      break;
    case Icmp:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).div.arg1 = arg1;
      (code_ptr->args).div.arg2 = arg2;
      (code_ptr->args).div.retval = retval;
      break;
    case Ret:
      break;
    default:
      break;
  }

  factor_push(retval);

  return code_ptr;
}

void insert_decl(char *fname, unsigned arity, Factor *args) {
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

  reg_counter = 1;

  return;
}

Factor create_factor_by_name(char *name) {
  Symbol *symbol_ptr = lookup_symbol(name);
  Factor x;
  x.type = symbol_ptr->type;
  strcpy(x.name, symbol_ptr->name);
  x.val = symbol_ptr->val;
  return x;
}

Fundecl *get_decl_head_ptr() { return decl_head_ptr; }

void set_cmp_type(Cmptype type) {
  cmp_type = type;
  return;
}