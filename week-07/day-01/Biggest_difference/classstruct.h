#ifndef BIGGEST_DIFFERENCE_CLASSSTRUCT_H
#define BIGGEST_DIFFERENCE_CLASSSTRUCT_H

typedef struct class {
    char name[30];
    int students;
    int *results;
} class_t;

void read_info(class_t *class, int number);
void print_info(class_t *class);

int min_max_difference(class_t *class);
int sum_results(const int *results, int num_of_students);
int sum_students(class_t *classes, int num_of_classes);

void print_largest_diff(class_t *classes, int num_of_classes);
void print_best_result(class_t *classes, int num_of_classes);
double find_average(class_t *classes, int num_of_classes);

void free_all(class_t *classes, int num_of_classes);

#endif //BIGGEST_DIFFERENCE_CLASSSTRUCT_H