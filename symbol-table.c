#include "symbol-table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static Symbol *symbol_head_ptr = NULL;
static Symbol *symbol_tail_ptr = NULL;

void insert_symbol(Scope type, char *name, int val) {
  Symbol *new_symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  new_symbol_ptr->type = type;
  new_symbol_ptr->name = (char *)malloc(strlen(name) + 1);
  strcpy(new_symbol_ptr->name, name);
  new_symbol_ptr->val = val;
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

void delete_local_symbol() {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  while (symbol_ptr->type == LOCAL_VAR) {
    printf("delete: %s %d\n", symbol_ptr->name, symbol_ptr->val);
    symbol_ptr = symbol_ptr->prev;
    free(symbol_ptr->next->name);
    free(symbol_ptr->next);
    symbol_ptr->next = NULL;
    symbol_tail_ptr = symbol_ptr;
  }

  return;
}

void print_all_symbols() {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_head_ptr;
  while (symbol_ptr) {
    print_symbol(symbol_ptr);
    symbol_ptr = symbol_ptr->next;
  }
  return;
}

void print_symbol(Symbol *symbol_ptr) {
  switch (symbol_ptr->type) {
    case GLOBAL_VAR:
      printf("type: GLOBAL,\t");
      break;
    case LOCAL_VAR:
      printf("type: LOCAL,\t");
      break;
    case PROC_NAME:
      printf("type: PROC,\t");
      break;
    case CONSTANT:
      printf("type: CONSTANT,\t");
      break;
    default:
      printf("error! unknown type\n");
      exit(1);
  }
  printf("name: %s,\tval: %d\n", symbol_ptr->name, symbol_ptr->val);
  return;
}

Symbol *get_symbol_head_ptr() { return symbol_head_ptr; }

void debug_symbol_table() {
  Symbol *symbol_ptr = (Symbol *)malloc(sizeof(Symbol));
  symbol_ptr = symbol_tail_ptr;

  printf("|-----------------------|\n");
  printf("| type\t| name\t| val\t|\n");
  printf("|-----------------------|\n");

  while (symbol_ptr) {
    printf("| %d\t| %s\t| %d\t|\n", symbol_ptr->type, symbol_ptr->name,
           symbol_ptr->val);
    symbol_ptr = symbol_ptr->prev;
  }

  printf("|-----------------------|\n");

  return;
};
