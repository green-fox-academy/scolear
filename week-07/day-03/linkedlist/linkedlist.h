#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* init_head(int data);
void push_back(node_t* head, int data);
void push_front(node_t** head, int data);

void print_all(node_t* head);

#endif //LINKEDLIST_LINKEDLIST_H
