#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "utils.h"

typedef struct _Symbol {
  Scope type;
  char *name;
  int val;
  struct _Symbol *next;
  struct _Symbol *prev;
} Symbol;

void insert_symbol(Scope type, char *name, int val);
Symbol *lookup_symbol(char *name);
void delete_local_symbol(void);

void print_all_symbols();
void print_symbol(Symbol *symbol_ptr);

#endif
