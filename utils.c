#include <stdio.h>


typedef struct _symbol_record {
    char *name;
    int order;
    int scope;
    int address;
} symbol_record;

typedef struct _symbol_table {
    int index;
    symbol_record *record;
    struct _symbol_table *prev;
    struct _symbol_table *next;
} symbol_table;


void insert(char *name, int flag) {
    printf("insert🔥 : %s\n", name);
}
void lookup(char *name) {
    printf("lookup✨ : %s\n", name);
}
void delete(char *name, int order) {
    printf("delete😭 ; %s, %d\n", name, order);
}