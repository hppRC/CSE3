#include <stdio.h>
#include <stdlib.h>

#define LOCAL 0
#define GLOBAL 1

#define FALSE 0
#define TRUE 1

typedef struct _symbol_data {
    char *name;
    int order;
    int scope;
    int address;
} symbol_data;

typedef struct _symbol_table {
    int index;
    symbol_data *data;
    struct _symbol_table *prev;
    struct _symbol_table *next;
} symbol_table;

int isTableExists(symbol_table *table) {
    if (table == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}