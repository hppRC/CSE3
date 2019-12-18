#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "utils.h"

typedef struct _Node {
  Scope type;
  char *name;
  int val;
  struct _Node *next;
  struct _Node *prev;
} Node;

void insert(int type, char *name, int val);
Node *lookup(char *name);
void delete_local_node(void);
void print_all_node(void);
void print_node(Node *node_ptr);

#endif
