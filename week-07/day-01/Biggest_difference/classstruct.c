#include <stdio.h>
#include <stdlib.h>
#include "classstruct.h"
#include "utils.h"

void read_info(class_t *class, int number) {

    printf("Enter name of class %d: ", number);
    scanf("%s", class->name);

    printf("Enter number of students in class: ");
    scanf("%d", &class->students);
    class->results = (int *) malloc(class->students * sizeof(int));

    printf("Enter exam results in percentage:\n");
    for (int i = 0; i < class->students; ++i) {
        scanf("%d", &class->results[i]);
        if(class->results[i] > 100) {
            printf("Enter a number between 0-100\n");
            i--;
        }
    }
}

void print_info(class_t *class) {
    printf("Name: %s, Results:\n", class->name);
    for (int i = 0; i < class->students; ++i) {
        printf("%d ", class->results[i]);
    }
    printf("\n");
}

int min_max_difference(class_t *class) {
    int min = find_min(class->results, class->students);
    int max = find_max(class->results, class->students);
    return max - min;
}

void print_largest_diff(class_t *classes, int num_of_classes) {
    int max_diff = 0;
    int index_of_max_diff = 0;

    for (int j = 0; j < num_of_classes; ++j) {
        int diff = min_max_difference(&classes[j]);
        if (diff > max_diff) {
            max_diff = diff;
            index_of_max_diff = j;
        }
    }
    printf("Class with largest difference: %s, with a difference of %d\n", classes[index_of_max_diff].name, max_diff);
}

void print_best_result(class_t *classes, int num_of_classes) {
    int best = 0;
    int index_of_best = 0;
    for (int j = 0; j < num_of_classes; ++j) {
        int max = find_max(classes[j].results, classes[j].students);
        if (max > best) {
            best = max;
            index_of_best = j;
        }
    }
    printf("Best exam in class: %s, with a score of %d\n", classes[index_of_best].name, best);
}

int sum_results(const int *results, int num_of_students) {
    int sum = 0;
    for (int i = 0; i < num_of_students; ++i) {
        sum += results[i];
    }
    return sum;
}

int sum_students(class_t *classes, int num_of_classes) {
    int sum = 0;
    for (int i = 0; i < num_of_classes; ++i) {
        sum += classes[i].students;
    }
    return sum;
}

double find_average(class_t *classes, int num_of_classes) {

    int sum_total = 0;
    int students_total = sum_students(classes, num_of_classes);

    for (int i = 0; i < num_of_classes; ++i) {
        sum_total += sum_results(classes[i].results, classes[i].students);
    }
    return (double)sum_total / students_total;
}