//https://qiita.com/heislandmine/items/e09fe8a952a85de2273c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

int exists_table(symbol_table *table) {
    printf("exists");
    if (table == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}

symbol_table *alloc_table(void) {
printf("alloc");
    symbol_table *table;
    table = (symbol_table*)malloc(sizeof(symbol_table));

    if (table == NULL) {
        fprintf(stderr,"ERROR: can't alloc memory.\n");
        exit(1);
    }

    return table;
}

symbol_table *trail_table(symbol_table *start) {
    printf("trail");
    while (start->next != NULL) {
        start = start->next;
    }

    return start;
}

symbol_table *insert_data(symbol_table *header, char *name) {
    printf("insert");
    // symbol_data *data;
    // data->name = name;

    // symbol_table *last_data = NULL;
    // symbol_table *new_data = NULL;

    // if (exists_table(header) == FALSE) {
    //     new_data = alloc_table();
    //     new_data->data = data;
    //     new_data->next = NULL;
    //     new_data->prev = NULL;

    //     return new_data;

    // } else {
    //     new_data = alloc_table();
    //     new_data->data = data;
    //     new_data->next = NULL;

    //     last_data = trail_table(header);

    //     new_data->prev = last_data;
    //     last_data->next = new_data;

    //     return header;
    // }
    return header;
}

void delete_data(symbol_table *header) {
    printf("delete");
}

symbol_data *lookup_data(symbol_table *header, char *name) {
    printf("lookup");
    return header->data;
}

void print_all_data(symbol_table *header) {
    printf("print_all");
    while (header != NULL) {
        printf("%s\n",header->data->name);
        header = header->next;
    }
}