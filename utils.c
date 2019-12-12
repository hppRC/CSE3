#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void insert(char *name, int flag) {
    printf("insert🔥 : %s\n", name);
}

void lookup(char *name) {
    printf("lookup✨ : %s\n", name);
}
void delete(char *name, int order) {
    printf("delete😭 ; %s, %d\n", name, order);
}
