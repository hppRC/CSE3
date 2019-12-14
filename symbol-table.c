#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol-table.h"

Node *head = NULL;
Node *tail = NULL;

void insert(int type, char *name, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->type = type;
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (!tail)
    {
        head = tail = new_node;
        return;
    }

    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;

    return;
};

Node *lookup(char *name)
{
    Node *node_ptr = (Node *)malloc(sizeof(Node));
    node_ptr = tail;

    while (node_ptr)
    {
        if (strcmp(node_ptr->name, name) == 0)
        {
            return node_ptr;
        }

        node_ptr = node_ptr->prev;
    }

    return NULL;
};

void delete ()
{
    Node *last_node = (Node *)malloc(sizeof(Node));
    last_node = tail;

    while (last_node->type == LOCAL_VAR)
    {
        last_node = last_node->prev;
        free(last_node->next->name);
        free(last_node->next);
        last_node->next = NULL;
        tail = last_node;
    }

    return;
}
