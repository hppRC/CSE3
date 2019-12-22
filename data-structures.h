#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "utils.h"

typedef struct {
  int label[100];
  unsigned int top;
} LabelStack;

typedef struct {
  Factor *address[100];
  unsigned int top;
} BrAddressStack;

Factor factor_pop();
void factor_push(Factor x);
int label_pop();
void label_push(int label);
Factor *br_address_pop();
void br_addresss_push(Factor *address);

void insert_code(LLVMcommand command);
LLVMcode *generate_code(LLVMcommand command);
void insert_decl(char *fname, unsigned arity, Factor *args);

void back_patch();

Factor create_factor_by_name(char *name);
Fundecl *get_decl_head_ptr();

void set_cmp_type(Cmptype type);

void set_read_flag(Bool flag);
Bool get_read_flag();
void set_write_flag(Bool flag);
Bool get_write_flag();

#endif
