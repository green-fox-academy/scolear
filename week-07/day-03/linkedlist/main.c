#include <stdio.h>
#include "linkedlist.h"


int main() {

    node_t* head = init_head(5);
    print_all(head);

    push_back(head, 10);
    print_all(head);

    push_front(&head, 12);
    print_all(head);


    return 0;
}