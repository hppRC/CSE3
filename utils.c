#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void insert_data(char *name, int flag) {
    printf("insert🔥 : %s\n", name);
}

void lookup_data(char *name) {
    printf("lookup✨ : %s\n", name);
}
void delete_data(char *name, int order) {
    printf("delete😭 ; %s, %d\n", name, order);
}
