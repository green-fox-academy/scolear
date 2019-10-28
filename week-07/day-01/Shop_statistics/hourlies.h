#ifndef SHOP_STATISTICS_HOURLIES_H
#define SHOP_STATISTICS_HOURLIES_H

#include <stdbool.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hourly_stats {
    char hours[12];
    char* entry;
} hourly_stats_t;

int determine_num_of_entries(FILE* fptr, hourly_stats_t* stat) {
    int count = 0;

}

#endif //SHOP_STATISTICS_HOURLIES_H
