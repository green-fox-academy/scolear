#include <stdio.h>
#include "linkedlist.h"

int main() {

    node_t* list = init_head(5);
    print_all(list);

    push_back(list, 10);
    print_all(list);

    push_front(&list, 12);
    print_all(list);
    printf("Length of list: %d\n", list_length(list));

    for (int i = 0; i < 10; ++i) {
        push_back(list, i + 10);
        push_back(list, i);
    }
    print_all(list);
    printf("Length of list: %d\n", list_length(list));

    printf("\nPop front tests:\n");
    pop_front(&list);
    pop_front(&list);
    print_all(list);
    printf("Length of list: %d\n", list_length(list));

    printf("\nPop at tests:\n");
    print_all(list);
    pop_at(&list, 2);
    print_all(list);

    pop_at(&list, 12);
    print_all(list);

    pop_at(&list, 0);
    print_all(list);

    printf("\nDelete by value tests:\n");
    print_all(list);
    printf("Delete value 4: deleted %d elements\n", pop_by_value(&list, 4));
    print_all(list);
    printf("Delete value 9: deleted %d elements\n", pop_by_value(&list, 9));
    print_all(list);
    printf("Delete value 0: deleted %d elements\n", pop_by_value(&list, 0));
    print_all(list);
    printf("Length of list: %d\n", list_length(list));

    printf("\nFind value tests:\n");
    int num = 5;
    node_t* value = find_value(list, num);
    if (value) {
        printf("This should print %d: %d\n", num, value->data);
    } else {
        printf("Number %d not in list.\n", num);
    }

    printf("\nBubble sorting:\n");
    bubble_sort(list);
    print_all(list);

    return 0;
}