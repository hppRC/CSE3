#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "utils.h"

typedef struct {
  int address[100];
  unsigned int top;
} AddressStack;

Factor factor_pop();
void factor_push(Factor x);

void insert_code(LLVMcommand command);
LLVMcode *generate_code(LLVMcommand command);

void insert_decl(char *fname, unsigned arity, Factor *args);

Factor create_factor_by_name(char *name);
Fundecl *get_decl_head_ptr();

void set_cmp_type(Cmptype type);

void set_read_flag(bool flag);
bool get_read_flag();
void set_write_flag(bool flag);
bool get_write_flag();

#endif
