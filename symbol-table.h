#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "utils.h"

void insert_symbol(Scope type, char *name, int val);
Symbol *lookup_symbol(char *name);
Symbol *lookup_proc_or_func_symbol(char *name, int arity_num);

void delete_local_symbol();
void debug_symbol_table();

Symbol *get_symbol_head_ptr();

void insert_array_symbol(Scope type, char *name, int val, int start, int end);

#endif
