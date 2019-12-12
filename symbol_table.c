//https://qiita.com/heislandmine/items/e09fe8a952a85de2273c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

int exists_table(symbol_table *table) {
    //printf("exists\n");
    if (table == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}

symbol_table *alloc_table(void) {
    //printf("alloc\n");
    symbol_table *table;
    table = (symbol_table*)malloc(sizeof(symbol_table));

    if (table == NULL) {
        fprintf(stderr,"ERROR: can't alloc memory.\n");
        exit(1);
    }

    return table;
}

symbol_table trail_table(symbol_table start) {
    printf("trail\n");
    while (start.next != NULL) {
        printf("%s\n", start.name);
        start = start.next;
    }

    return start;
}

symbol_table *insert_data(symbol_table *header, char *name) {
    //printf("insert\n");
    // symbol_data *data;
    // data->name = name;

    symbol_table *last_data = NULL;
    symbol_table *new_data = NULL;

    if (exists_table(header) == FALSE) {
        new_data = alloc_table();
        new_data->name = name;
        new_data->next = NULL;
        new_data->prev = NULL;

        return new_data;

    } else {
        new_data = alloc_table();
        last_data = trail_table(header);

        new_data->name = name;
        new_data->next = NULL;
        new_data->prev = last_data;

        last_data->next = new_data;

        return header;
    }
}

void delete_data(symbol_table *header) {
    //printf("delete\n");
}

symbol_table *lookup_data(symbol_table *header, char *name) {
    // printf("lookup\n");
    return header;
}

void print_all_data(symbol_table *header) {
    //printf("print_all\n");
    while (header != NULL) {
        printf("%s\n",header->name);
        header = header->next;
    }
}