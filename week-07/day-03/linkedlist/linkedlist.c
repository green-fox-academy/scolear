#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

node_t* init_head(int data)
{
    node_t* head = (node_t*) malloc(sizeof(node_t));
    head->data = data;
    head->next = NULL;
    return head;
}

void push_back(node_t* head, int data)
{
    node_t* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_t*) malloc(sizeof(node_t));
    current->next->next = NULL;
    current->next->data = data;
}

void push_front(node_t** head, int data)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->next = *head;
    new_node->data = data;

    *head = new_node;
}

void print_all(node_t* head)
{
    node_t* current = head;
    printf("All elements in list: { ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}