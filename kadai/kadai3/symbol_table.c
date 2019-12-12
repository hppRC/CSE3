#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

Node *head = NULL;

void insert_data(int type, char *name, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->type = type;
    new_node->name = (char *)malloc(strlen(name)+1);
    strcpy(new_node->name, name);
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *node_ptr = (Node *)malloc(sizeof(Node));

    node_ptr = head;
    while (node_ptr->next) {
        node_ptr = node_ptr->next;
    }

    node_ptr->next = new_node;
    new_node->prev = node_ptr;
    return;
};

Node *lookup_data(char *name) {
    Node *node_ptr = (Node *)malloc(sizeof(Node));

    node_ptr = head;
    while (node_ptr) {
        if (strcmp(node_ptr->name, name) == 0) {
            //printf("%d, %s, %d\n", node_ptr->type, node_ptr->name, node_ptr->val);
            return node_ptr;
        }
        node_ptr = node_ptr->next;
    }
    return NULL;
};

void delete_data() {
    Node *last_node = (Node *)malloc(sizeof(Node));

    last_node = head;
    while (last_node->next) {
        last_node = last_node->next;
    }

    while (last_node->type == LOCAL_VAR) {
        last_node = last_node->prev;
        free(last_node->next->name);
        free(last_node->next);
        last_node->next = NULL;
    }
}

void print_all_node(Node *head) {
    Node *node_ptr = (Node *)malloc(sizeof(Node));

    node_ptr = head;
    if (!node_ptr) {
        return;
    }
    printf("%d, %s, %d\n", node_ptr->type, node_ptr->name, node_ptr->val);
    while (node_ptr->next) {
        node_ptr = node_ptr->next;
        printf("%d, %s, %d\n", node_ptr->type, node_ptr->name, node_ptr->val);
    }
    return;
}