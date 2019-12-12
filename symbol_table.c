#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

void insert_data(Node *head, int type, char *name, int val) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->type = type;
    strcpy(new_node->name, name);
    new_node->val = val;
    new_node->next = NULL;

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
    return;
};

void lookup_data() {};
void delete_data() {};

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