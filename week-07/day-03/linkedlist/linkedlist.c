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

void pop_front(node_t** head)
{
    node_t* new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

void pop_at(node_t** head, int index)
{
    node_t* current = *head;
    node_t* temp = NULL;

    if (index == 0) {
        pop_front(head);
    } else if (index > list_length(*head) || index < 0) {
        printf("Out of bounds pop request.\n");
        return;
    } else {
        int counter = 0;
        while (counter != index - 1) {
            current = current->next;
            counter++;
        }

        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int pop_by_value(node_t** head, int value)
{
    int delete_counter = 0;
    if (is_empty(*head)) {
        return 0;
    } else {
        int index_counter = 0;
        node_t* current = *head;
        while (current != NULL) {
            if(current->data == value) {
                pop_at(head, index_counter);
                delete_counter++;
                index_counter--;
            }
            index_counter++;
            current = current->next;
        }
    }
    return delete_counter;
}

node_t* find_value(node_t* head, int value)
{
    node_t* current = head;
    while(current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int list_length(node_t* head)
{
    if (is_empty(head)) {
        return 0;
    } else {
        int counter = 1;
        node_t* current = head;
        while (current->next != NULL) {
            counter++;
            current = current->next;
        }
        return counter;
    }
}

bool is_empty(node_t* head)
{
    return head == NULL;
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

void swap_data(node_t* a, node_t* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort(node_t* head)
{
    bool swapped;
    node_t* ptr1;
    node_t* lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;
    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap_data(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}