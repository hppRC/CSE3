#include "display-llvm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-structures.h"
#include "symbol-table.h"

extern Fundecl *get_decl_head_ptr();
extern Symbol *get_symbol_head_ptr();
extern Bool get_read_flag();
extern Bool get_write_flag();

extern FILE *fp;

int i;

void display_factor(Factor x) {
  switch (x.type) {
    case GLOBAL_VAR:
    case GLOBAL_ARRAY:
    case FUNC_NAME:
    case PROC_NAME:
      fprintf(fp, "@%s", x.name);
      break;
    case LOCAL_VAR:
      fprintf(fp, "%%%d", x.val);
      break;
    case CONSTANT:
      fprintf(fp, "%d", x.val);
      break;
    case LOCAL_ARRAY:
      fprintf(fp, "@%s", x.name);
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
      fprintf(fp, "  br label %%%d\n", (code_ptr->args).bruncond.arg1);
      break;
    case BrCond:
      fprintf(fp, "  br i1 ");
      display_factor((code_ptr->args).brcond.arg1);
      fprintf(fp, ", label %%%d, label %%%d\n", (code_ptr->args).brcond.arg2,
              (code_ptr->args).brcond.arg3);
      break;
    case Label:
      fprintf(fp, "\n%d:\n", (code_ptr->args).label.l);
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
      fprintf(fp, "  ret ");
      switch ((code_ptr->args).ret.ret_type) {
        case INT:
          fprintf(fp, "i32 ");
          display_factor((code_ptr->args).ret.arg1);
          break;
        case VOID:
          fprintf(fp, "void");
          break;
      }
      break;
    case Proc:
      fprintf(fp, "  call void ");
      display_factor((code_ptr->args).proc.arg1);
      fprintf(fp, "(");
      while ((code_ptr->args).proc.top > 0) {
        Factor x = (code_ptr->args).proc.element[(code_ptr->args).proc.top];
        fprintf(fp, "i32 ");
        display_factor(x);
        (code_ptr->args).proc.top--;
        if ((code_ptr->args).proc.top > 0) fprintf(fp, ", ");
      }
      fprintf(fp, ")\n");
      break;
    case Func:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).func.retval);
      fprintf(fp, " = call i32 ");
      display_factor((code_ptr->args).func.arg1);
      fprintf(fp, "(");
      while ((code_ptr->args).func.top > 0) {
        Factor x = (code_ptr->args).func.element[(code_ptr->args).func.top];
        fprintf(fp, "i32 ");
        display_factor(x);
        (code_ptr->args).func.top--;
        if ((code_ptr->args).func.top > 0) fprintf(fp, ", ");
      }
      fprintf(fp, ")\n");
      break;
    case Read:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).read.retval);
      fprintf(fp,
              " = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr "
              "inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32* ");
      display_factor((code_ptr->args).read.arg1);
      fprintf(fp, ")\n");
      break;
    case Write:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).write.retval);
      fprintf(fp,
              " = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x "
              "i8], [4 x i8]* @.str, i64 0, i64 0), i32 ");
      display_factor((code_ptr->args).write.arg1);
      fprintf(fp, ")\n");
      break;
    case GEP:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).gep.retval);
      fprintf(fp, " = getelementptr inbounds [100 x i32], [100 x i32]* ");
      display_factor((code_ptr->args).gep.arg2);
      fprintf(fp, ", i64 0, i64 ");
      display_factor((code_ptr->args).gep.arg1);
      fprintf(fp, "\n");
      break;
    case Sext:
      fprintf(fp, "  ");
      display_factor((code_ptr->args).sext.retval);
      fprintf(fp, " = sext i32 ");
      display_factor((code_ptr->args).sext.arg1);
      fprintf(fp, " to i64\n");
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
    fprintf(fp, "define ");
    switch (decl_ptr->ret_type) {
      case INT:
        fprintf(fp, "i32 ");
        break;
      case VOID:
        fprintf(fp, "void ");
        break;
    }
    fprintf(fp, "@%s(", decl_ptr->fname);
    for (i = 1; i < decl_ptr->arity; i++) {
      fprintf(fp, "i32, ");
    }
    if (decl_ptr->arity > 0) {
      fprintf(fp, "i32");
    }
    fprintf(fp, ") #0 {\n");
    display_llvm_codes(decl_ptr->codes);
    fprintf(fp, "\n}\n");
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
    switch (symbol_ptr->type) {
      case GLOBAL_VAR:
        fprintf(fp, "@%s = common global i32 0, align 4\n", symbol_ptr->name);
        break;
      case GLOBAL_ARRAY:
        fprintf(fp,
                "@%s = common global [%d x i32] zeroinitializer, align 16\n",
                symbol_ptr->name, symbol_ptr->end - symbol_ptr->start + 1);
    }
    symbol_ptr = symbol_ptr->next;
  }
  return;
}

void display_str() {
  fprintf(fp,
          "@.str = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", "
          "align 1\n\n");
  if (get_read_flag())
    fprintf(fp, "declare dso_local i32 @__isoc99_scanf(i8*, ...) #1\n");
  if (get_write_flag())
    fprintf(fp, "declare dso_local i32 @printf(i8*, ...) #1\n");

  return;
}

void display_llvm() {
  Fundecl *decl_head_ptr = get_decl_head_ptr();
  display_global_var();
  if (get_read_flag() || get_write_flag()) display_str();
  fprintf(fp, "\n");
  display_llvm_fun_decl(decl_head_ptr);
  return;
}
