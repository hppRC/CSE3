#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static LLVMcode *code_head_ptr = NULL;
static LLVMcode *code_tail_ptr = NULL;

static Fundecl *decl_head_ptr = NULL;
static Fundecl *decl_tail_ptr = NULL;

static FactorStack fstack = {{}, 0};
static LabelStack labelstack = {{}, 0};
static BrAddressStack addstack = {{}, 0};
static ArityStack aritystack = {{}, 0};

int reg_counter = 0;
Type ret_type = VOID;
static Bool read_flag = FALSE;
static Bool write_flag = FALSE;

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

int label_pop() { return labelstack.label[labelstack.top--]; }

void label_push(int label) { labelstack.label[++labelstack.top] = label; }

int *address_pop() { return addstack.address[addstack.top--]; }

void address_push(int *address) { addstack.address[++addstack.top] = address; }

Factor arity_pop() { return aritystack.element[aritystack.top--]; }

void arity_push(Factor x) { aritystack.element[++aritystack.top] = x; }

int get_aritystack_top() { return aritystack.top; }

void insert_code(LLVMcommand command) {
  LLVMcode *new_code_ptr = generate_code(command);

  if (decl_tail_ptr == NULL) {
    fprintf(stderr, "unexpected error\ndecl_tail_ptr is NULL\n");
    exit(1);
  }

  if (code_tail_ptr == NULL) {
    decl_tail_ptr->codes = new_code_ptr;
    code_head_ptr = code_tail_ptr = new_code_ptr;
  } else {
    code_tail_ptr->next = new_code_ptr;
    code_tail_ptr = new_code_ptr;
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
      strcpy(retval.name, "allo");
      retval.val = reg_counter++;
      (code_ptr->args).alloca.retval = retval;
      factor_push(retval);
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
      factor_push(retval);
      break;
    case BrUncond:
      //(code_ptr->args).bruncond.arg1 = reg_counter;
      (code_ptr->args).bruncond.arg1 = 0;
      address_push(&(code_ptr->args).bruncond.arg1);
      break;
    case BrCond:
      arg1 = factor_pop();
      (code_ptr->args).brcond.arg1 = arg1;
      (code_ptr->args).brcond.arg2 = reg_counter;
      (code_ptr->args).brcond.arg3 = 0;
      address_push(&(code_ptr->args).brcond.arg3);
      break;
    case Label:
      (code_ptr->args).label.l = reg_counter++;
      break;
    case Add:
      arg2 = factor_pop();
      arg1 = factor_pop();
      if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
        factor_push((Factor){CONSTANT, "opt", arg1.val + arg2.val});
        break;
      }
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).add.arg1 = arg1;
      (code_ptr->args).add.arg2 = arg2;
      (code_ptr->args).add.retval = retval;
      factor_push(retval);
      break;
    case Sub:
      arg2 = factor_pop();
      arg1 = factor_pop();
      if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
        factor_push((Factor){CONSTANT, "opt", arg1.val - arg2.val});
        break;
      }
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).sub.arg1 = arg1;
      (code_ptr->args).sub.arg2 = arg2;
      (code_ptr->args).sub.retval = retval;
      factor_push(retval);
      break;
    case Mult:
      arg2 = factor_pop();
      arg1 = factor_pop();
      if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
        factor_push((Factor){CONSTANT, "opt", arg1.val * arg2.val});
        break;
      }
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).mult.arg1 = arg1;
      (code_ptr->args).mult.arg2 = arg2;
      (code_ptr->args).mult.retval = retval;
      factor_push(retval);
      break;
    case Div:
      arg2 = factor_pop();
      arg1 = factor_pop();
      if (arg1.type == CONSTANT && arg2.type == CONSTANT) {
        factor_push((Factor){CONSTANT, "opt", arg1.val / arg2.val});
        break;
      }
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).div.arg1 = arg1;
      (code_ptr->args).div.arg2 = arg2;
      (code_ptr->args).div.retval = retval;
      factor_push(retval);
      break;
    case Icmp:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).icmp.arg1 = arg1;
      (code_ptr->args).icmp.arg2 = arg2;
      (code_ptr->args).icmp.retval = retval;
      (code_ptr->args).icmp.type = cmp_type;
      factor_push(retval);
      break;
    case Ret:
      (code_ptr->args).ret.ret_type = ret_type;
      if (ret_type == INT) {
        arg1 = factor_pop();
        (code_ptr->args).ret.arg1 = arg1;
      }
      break;
    case Proc:
      arg1 = factor_pop();
      (code_ptr->args).proc.arg1 = arg1;
      while (aritystack.top > 0) {
        Factor x = arity_pop();
        (code_ptr->args).proc.top++;
        (code_ptr->args).proc.element[(code_ptr->args).proc.top] = x;
      }
      break;
    case Func:
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).func.arg1 = arg1;
      (code_ptr->args).func.retval = retval;
      while (aritystack.top > 0) {
        Factor x = arity_pop();
        (code_ptr->args).func.top++;
        (code_ptr->args).func.element[(code_ptr->args).func.top] = x;
      }
      factor_push(retval);
      break;
    case Read:
      arg1 = factor_pop();
      (code_ptr->args).read.arg1 = arg1;
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).read.retval = retval;
      factor_push(retval);
      break;
    case Write:
      arg1 = factor_pop();
      (code_ptr->args).write.arg1 = arg1;
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).write.retval = retval;
      factor_push(retval);
      break;
    case GEP:
      arg2 = factor_pop();
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).gep.arg1 = arg1;
      (code_ptr->args).gep.arg2 = arg2;
      (code_ptr->args).gep.retval = retval;
      factor_push(retval);
      break;
    case Sext:
      arg1 = factor_pop();
      retval.type = LOCAL_VAR;
      retval.val = reg_counter++;
      (code_ptr->args).sext.arg1 = arg1;
      (code_ptr->args).sext.retval = retval;
      factor_push(retval);
      break;
  }

  return code_ptr;
}

void insert_decl(char *fname, int arity_num, Factor *args, Type ret_type) {
  Fundecl *decl_ptr = (Fundecl *)malloc(sizeof(Fundecl));
  if (strcmp(fname, "main") == 0) {
    sprintf(decl_ptr->fname, "main");
  } else {
    sprintf(decl_ptr->fname, "%s%d", fname, arity_num);
  }
  decl_ptr->arity = arity_num;
  decl_ptr->codes = code_tail_ptr = code_head_ptr = NULL;
  decl_ptr->ret_type = ret_type;
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

void back_patch() {
  while (labelstack.top > 0) {
    int *address = address_pop();
    int label = label_pop();
    *address = label;
  }
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

Factor create_proc_or_func_factor(char *name, int arity_num) {
  Symbol *symbol_ptr = lookup_proc_or_func_symbol(name, arity_num);
  Factor x;
  x.type = symbol_ptr->type;
  sprintf(x.name, "%s%d", name, arity_num);
  x.val = symbol_ptr->val;
  return x;
}

Fundecl *get_decl_head_ptr() { return decl_head_ptr; }

void set_cmp_type(Cmptype type) {
  cmp_type = type;
  return;
}

void set_read_flag(Bool flag) {
  read_flag = flag;
  return;
}

Bool get_read_flag() { return read_flag; }

void set_write_flag(Bool flag) {
  write_flag = flag;
  return;
}

Bool get_write_flag() { return write_flag; }
