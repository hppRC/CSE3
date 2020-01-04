#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include "utils.h"

typedef struct {
  int label[100];
  unsigned int top;
} LabelStack;

typedef struct {
  int *address[100];
  unsigned int top;
} BrAddressStack;

typedef struct {
  Factor element[100];
  unsigned int top;
} ArityStack;

Factor factor_pop();
void factor_push(Factor x);
int label_pop();
void label_push(int label);
int *address_pop();
void address_push(int *address);
void arity_push(Factor x);
Factor arity_pop();

void insert_code(LLVMcommand command);
LLVMcode *generate_code(LLVMcommand command);
void insert_decl(char *fname, unsigned arity, Factor *args, Type ret_type);

void back_patch();

Factor create_factor_by_name(char *name);

Fundecl *get_decl_head_ptr();
void set_cmp_type(Cmptype type);
void set_read_flag(Bool flag);
Bool get_read_flag();
void set_write_flag(Bool flag);
Bool get_write_flag();

#endif
