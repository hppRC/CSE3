#ifndef DISPLAY_LLVM_H
#define DISPLAY_LLVM_H

#include "utils.h"

void display_llvm_fun_decl(Fundecl *decl_ptr);
void display_factor(Factor x);
void display_llvm_codes(LLVMcode *code_ptr);
void display_llvm();

#endif