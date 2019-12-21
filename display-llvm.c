#include "display-llvm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data-structures.h"
#include "symbol-table.h"

extern Fundecl *get_decl_head_ptr();
extern Symbol *get_symbol_head_ptr();

extern FILE *fp;

void display_factor(Factor x) {
  switch (x.type) {
    case GLOBAL_VAR:
      fprintf(fp, "@%s", x.name);
      break;
    case LOCAL_VAR:
      fprintf(fp, "%%%d", x.val);
      break;
    case PROC_NAME:
      printf("what is thi.\n");
      break;
    case CONSTANT:
      fprintf(fp, "%d", x.val);
      break;
    default:
      fprintf(fp, "unexpected type!\n");
      break;
  }
  return;
}

void display_llvm_codes(LLVMcode *code_ptr) {
  if (code_ptr == NULL) return;
  switch (code_ptr->command) {
    case Alloca:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).alloca.retval);
      fprintf(fp, " = alloca i32, align 4\n");
      break;
    case Store:
      fprintf(fp, "  store i32 ");
      display_factor((code_ptr->args).store.arg1);
      fprintf(fp, ", i32* ");
      display_factor((code_ptr->args).store.arg2);
      fprintf(fp, ", align 4\n");
      break;
    case Load:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).load.retval);
      fprintf(fp, " = load i32, i32* ");
      display_factor((code_ptr->args).load.arg1);
      fprintf(fp, ", align 4\n");
      break;
    case BrUncond:
      break;
    case BrCond:
      break;
    case Label:
      fprintf(fp, "  br label %%%d\n\n%d:\n", (code_ptr->args).label.l,
              (code_ptr->args).label.l);
      break;
    case Add:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).add.retval);
      fprintf(fp, " = add nsw i32 ");
      display_factor((code_ptr->args).add.arg1);
      fprintf(fp, ", ");
      display_factor((code_ptr->args).add.arg2);
      fprintf(fp, "\n");
      break;
    case Sub:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).sub.retval);
      fprintf(fp, " = sub nsw i32 ");
      display_factor((code_ptr->args).sub.arg1);
      fprintf(fp, ", ");
      display_factor((code_ptr->args).sub.arg2);
      fprintf(fp, "\n");
      break;
    case Mult:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).mult.retval);
      fprintf(fp, " = mul nsw i32 ");
      display_factor((code_ptr->args).mult.arg1);
      fprintf(fp, ", ");
      display_factor((code_ptr->args).mult.arg2);
      fprintf(fp, "\n");
      break;
    case Div:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).div.retval);
      fprintf(fp, " = sdiv i32 ");
      display_factor((code_ptr->args).div.arg1);
      fprintf(fp, ", ");
      display_factor((code_ptr->args).div.arg2);
      fprintf(fp, "\n");
      break;
    case Icmp:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).icmp.retval);
      fprintf(fp, " = icmp ");
      switch ((code_ptr->args).icmp.type) {
        case EQUAL:
          fprintf(fp, "eq");
          break;
        case NE:
          fprintf(fp, "ne");
          break;
        case SLT:
          fprintf(fp, "slt");
          break;
        case SLE:
          fprintf(fp, "sle");
          break;
        case SGT:
          fprintf(fp, "sgt");
          break;
        case SGE:
          fprintf(fp, "sge");
          break;
        default:
          printf("unexpected cmp type\n");
          exit(1);
      }
      fprintf(fp, " i32 ");
      display_factor((code_ptr->args).icmp.arg1);
      fprintf(fp, ", ");
      display_factor((code_ptr->args).icmp.arg2);
      fprintf(fp, "\n");
      break;
    case Ret:
      break;
    default:
      break;
  }
  display_llvm_codes(code_ptr->next);
}

void display_llvm_fun_decl(Fundecl *decl_ptr) {
  if (decl_ptr == NULL) return;
  if (strcmp(decl_ptr->fname, "main") == 0) {
    fprintf(fp, "define i32 @main() #0 {\n");
    display_llvm_codes(decl_ptr->codes);
    fprintf(fp, "  ret i32 0\n}\n");
  } else {
    fprintf(fp, "define void @%s() #0 {\n", decl_ptr->fname);
    display_llvm_codes(decl_ptr->codes);
    fprintf(fp, "  ret void\n}\n");
  }
  if (decl_ptr->next != NULL) {
    fprintf(fp, "\n");
    display_llvm_fun_decl(decl_ptr->next);
  }
  return;
}

void display_global_var() {
  Symbol *symbol_ptr = get_symbol_head_ptr();
  while (symbol_ptr) {
    if (symbol_ptr->type != GLOBAL_VAR) {
      break;
    }
    fprintf(fp, "@%s = common global i32 0, align 4\n", symbol_ptr->name);
    symbol_ptr = symbol_ptr->next;
  }
  return;
}

void display_llvm() {
  Fundecl *decl_head_ptr = get_decl_head_ptr();
  display_global_var();
  fprintf(fp, "\n");
  display_llvm_fun_decl(decl_head_ptr);
  return;
}
