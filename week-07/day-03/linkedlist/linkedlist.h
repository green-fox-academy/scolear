#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* init_head(int data);
void push_back(node_t* head, int data);
void push_front(node_t** head, int data);

void pop_front(node_t** head);
void pop_at(node_t** head, int index);
int pop_by_value(node_t** head, int value);

node_t* find_value(node_t* head, int value);
void bubble_sort(node_t* head);
void print_all(node_t* head);

int list_length(node_t* head);
bool is_empty(node_t* head);
void swap_data(node_t* a, node_t* b);

#endif //LINKEDLIST_LINKEDLIST_H
