//https://qiita.com/heislandmine/items/e09fe8a952a85de2273c
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

int exists_table(symbol_table *table) {
    if (table == NULL) {
        return FALSE;
    } else {
        return TRUE;
    }
}

symbol_table *alloc_table(void) {
    symbol_table *table;
    table = (symbol_table*)malloc(sizeof(symbol_table));

    if (table == NULL) {
        fprintf(stderr,"ERROR: can't alloc memory.\n");
        exit(1);
    }

    return table;
}

symbol_table *trail_table(symbol_table *start) {
    while (start->next != NULL) {
        start = start->next;
    }

    return start;
}

symbol_table *insert_data(symbol_table *header, char *name) {
    symbol_data *data;
    data->name = name;

    symbol_table *last_data = NULL;
    symbol_table *new_data = NULL;

    if (exists_table(header) == FALSE) {
        new_data = alloc_table();
        new_data->data = data;
        new_data->next = NULL;
        new_data->prev = NULL;

        return new_data;

    } else {
        new_data = alloc_table();
        new_data->data = data;
        new_data->next = NULL;

        last_data = trail_table(header);

        new_data->prev = last_data;
        last_data->next = new_data;

        return header;
    }
}

void delete_data(symbol_table *header) {

}

symbol_data *lookup_data(symbol_table *header, char *name) {

}