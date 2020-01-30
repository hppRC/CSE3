#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static Symbol *symbol_head_ptr = NULL;
static Symbol *symbol_tail_ptr = NULL;

void insert_symbol(Scope scope, char *name, int val) {
  Symbol *new_symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  new_symbol_ptr->type = scope;
  new_symbol_ptr->name = (char *)malloc(strlen(name) + 1);
  strcpy(new_symbol_ptr->name, name);
  new_symbol_ptr->val = val;
  new_symbol_ptr->arity_num = 0;
  new_symbol_ptr->next = NULL;
  new_symbol_ptr->prev = NULL;

  if (!symbol_tail_ptr) {
    symbol_head_ptr = symbol_tail_ptr = new_symbol_ptr;
    return;
  }

  symbol_tail_ptr->next = new_symbol_ptr;
  new_symbol_ptr->prev = symbol_tail_ptr;
  symbol_tail_ptr = new_symbol_ptr;

  return;
};

Symbol *lookup_symbol(char *name) {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr) {
    if (strcmp(symbol_ptr->name, name) == 0) {
      return symbol_ptr;
    }
    symbol_ptr = symbol_ptr->prev;
  }
  return NULL;
};

Symbol *lookup_proc_or_func_symbol(char *name, int arity_num) {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr) {
    if (strcmp(symbol_ptr->name, name) == 0 &&
        symbol_ptr->arity_num == arity_num) {
      return symbol_ptr;
    }
    symbol_ptr = symbol_ptr->prev;
  }
  return NULL;
};

void delete_local_symbol() {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr->type == LOCAL_VAR) {
    symbol_ptr = symbol_ptr->prev;
    free(symbol_ptr->next->name);
    free(symbol_ptr->next);
    symbol_ptr->next = NULL;
    symbol_tail_ptr = symbol_ptr;
  }

  return;
}

Symbol *get_symbol_head_ptr() { return symbol_head_ptr; }

void debug_symbol_table() {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;
  printf("\nsymbol_table debug\n");
  printf("|-------------------------------|\n");
  printf("|type\t|name\t|val\t|arity\t|\n");
  printf("|-------------------------------|\n");

  while (symbol_ptr) {
    printf("|%d\t|%s\t|%d\t|%d\t|\n", symbol_ptr->type, symbol_ptr->name,
           symbol_ptr->val, symbol_ptr->arity_num);
    symbol_ptr = symbol_ptr->prev;
  }

  printf("|-------------------------------|\n");

  return;
};

void overwrite_symbol_val(int var_num, int arity_num) {
  int tmp = arity_num * 2 + var_num;
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr && tmp > arity_num) {
    if (symbol_ptr->type == LOCAL_VAR) symbol_ptr->val = tmp--;
    symbol_ptr = symbol_ptr->prev;
  }

  return;
}

void overwrite_symbol_arity(char *name, int arity_num) {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr) {
    if (strcmp(symbol_ptr->name, name) == 0 &&
        (symbol_ptr->type == PROC_NAME || symbol_ptr->type == FUNC_NAME)) {
      break;
    }
    symbol_ptr = symbol_ptr->prev;
  }
  symbol_ptr->arity_num = arity_num;
}

void insert_array_symbol(Scope scope, char *name, int val, int start, int end) {
  Symbol *new_symbol_ptr = (Symbol *)malloc(sizeof(Symbol));

  new_symbol_ptr->type = (scope == GLOBAL_VAR) ? GLOBAL_ARRAY : LOCAL_ARRAY;
  new_symbol_ptr->name = (char *)malloc(strlen(name) + 1);
  strcpy(new_symbol_ptr->name, name);
  new_symbol_ptr->val = val;
  new_symbol_ptr->start = start;
  new_symbol_ptr->end = end;
  new_symbol_ptr->arity_num = 0;
  new_symbol_ptr->next = NULL;
  new_symbol_ptr->prev = NULL;

  if (!symbol_tail_ptr) {
    symbol_head_ptr = symbol_tail_ptr = new_symbol_ptr;
    return;
  }

  symbol_tail_ptr->next = new_symbol_ptr;
  new_symbol_ptr->prev = symbol_tail_ptr;
  symbol_tail_ptr = new_symbol_ptr;

  return;
};