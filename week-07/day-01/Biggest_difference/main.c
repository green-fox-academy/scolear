// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, then the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?

#include <stdio.h>
#include <stdlib.h>

#include "classstruct.h"

int main()
{
    int num_of_classes;

    printf("How many classes took the exam? : ");
    scanf("%d", &num_of_classes);

    class_t *classes = (class_t *) malloc(num_of_classes * sizeof( *classes));

    for (int i = 0; i < num_of_classes; ++i) {
        read_info(&classes[i], i + 1);
    }

    for (int i = 0; i < num_of_classes; ++i) {
        print_info(&classes[i]);
    }

    print_largest_diff(classes, num_of_classes);

    print_best_result(classes, num_of_classes);

    printf("Average score of all exams: %.2lf\n", find_average(classes, num_of_classes));

    return 0;
}