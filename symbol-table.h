#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "utils.h"

void insert_symbol(Scope type, char *name, int val);
Symbol *lookup_symbol(char *name);
void delete_local_symbol(void);

void print_all_symbols();
void print_symbol(Symbol *symbol_ptr);

Symbol *get_symbol_head_ptr();

#endif
