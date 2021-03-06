#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol-table.h"

Node *head = NULL;
Node *tail = NULL;

void insert(int type, char *name, int val)
{
    printf("----------------------------------------------\n");
    printf("insert\n");
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
        //begin(test用コード)
        print_all_node();
        //end(test用コード)
        return;
    }

    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;

    //begin(test用コード)
    print_all_node();
    //end(test用コード)

    printf("----------------------------------------------\n");
    return;
};

Node *lookup(char *name)
{
    printf("----------------------------------------------\n");
    printf("lookup\n");
    Node *node_ptr = (Node *)malloc(sizeof(Node));
    node_ptr = tail;
    while (node_ptr)
    {
        if (strcmp(node_ptr->name, name) == 0)
        {
            print_node(node_ptr);
            printf("----------------------------------------------\n");
            return node_ptr;
        }

        node_ptr = node_ptr->prev;
    }
    printf("No data!,   about:\t%s\n", name);
    printf("----------------------------------------------\n");
    return NULL;
};

void delete ()
{
    printf("----------------------------------------------\n");
    printf("delete\n");
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

    //begin(test用コード)
    print_all_node();
    //end(test用コード)

    printf("----------------------------------------------\n");
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