#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "utils.h"

Factor factor_pop();
void factor_push(Factor x);
void insert_code(LLVMcommand command);
LLVMcode *llvm_code_by_command(LLVMcommand command);
void insert_decl(char *fname, unsigned arity, Factor *args);

Factor create_factor_by_name(char *name);

#endif