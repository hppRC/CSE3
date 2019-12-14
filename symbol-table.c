#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol-table.h"

Node *head = NULL;
Node *tail = NULL;

void insert(int type, char *name, int val)
{
    Node *new_node_ptr = (Node *)malloc(sizeof(Node));
    new_node_ptr->type = type;
    new_node_ptr->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node_ptr->name, name);
    new_node_ptr->val = val;
    new_node_ptr->next = NULL;
    new_node_ptr->prev = NULL;

    if (!tail)
    {
        head = tail = new_node_ptr;
        return;
    }

    tail->next = new_node_ptr;
    new_node_ptr->prev = tail;
    tail = new_node_ptr;

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

void print_all_node()
{
    Node *node_ptr = (Node *)malloc(sizeof(Node));
    node_ptr = head;
    while (node_ptr)
    {
        print_node(node_ptr);
        node_ptr = node_ptr->next;
    }
    return;
}

void print_node(Node *node_ptr)
{
    switch (node_ptr->type)
    {
    case GLOBAL_VAR:
        printf("type: GLOBAL,\t");
        break;
    case LOCAL_VAR:
        printf("type: LOCAL,\t");
        break;
    case PROC_NAME:
        printf("type: PROC,\t");
        break;
    case CONSTANT:
        printf("type: CONSTANT,\t");
        break;
    default:
        printf("error! unknown type\n");
        exit(1);
    }
    printf("name: %s,\tval: %d\n", node_ptr->name, node_ptr->val);
    return;
}