
//In the file you can find the daily log of a shop's traffic sensor. For every hour it logs the number of incoming and outgoing customers
//The first line tells you how much hours it was working. Let's say this number is N.
//Then N lines follows. Each of them contains the time frame and 0s and 1s. 0 means a customer left the store, 1 means a customer entered the store.
//Create a function that reads the data and returns a pointer to it and the size.
//Create functions to answer the following questions:

//How many customers the shop had that day?
//What was the time with the most traffic?(Sum of incoming and outgoing customers)
//When the shop needs the most cashiers?(When was the time the most customer was in the store)
//Does it worth to keep the shop open in the last 2 hours? It worths it if at least 5% of the total customers was in the store at the last 2 hours.

#include <stdio.h>
#include <stdlib.h>

#include "hourlies.h"

int main()
{
    FILE* input_file;
    if (!(input_file = fopen("../shop-statistics.txt", "r"))) return -1;

    // Reading first line into total_working_hours:
    char hour_buffer[10];
    fgets(hour_buffer, 10, input_file);
    int total_working_hours = atoi(hour_buffer);

    printf("Total hours open: %d\n", total_working_hours);

    hourly_stats_t* stats = (hourly_stats_t *) malloc(total_working_hours * sizeof(*stats));

    for (int i = 0; i < total_working_hours; ++i) {
        fgets(stats[i].hours, 12, input_file);

    }

    printf("%s", stats[0].hours);

    fclose(input_file);
    return 0;
}