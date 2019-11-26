// Every line contains the name of the group and after a colon, the height of people in the group separated by commas
// Find the group where the median is the lowest.
// Note that the groups do not necessarily contain the same amount of people

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHTS_BUFFER 20

typedef struct group {
    char name[10];
    int heights[HEIGHTS_BUFFER];
    int number_of_people;
} group_t;

int count_lines(char* filename)
{
    FILE* fptr;
    if (!(fptr = fopen(filename, "r"))) return -1;
    int i = 0;
    char buffer[256];
    while(fgets(buffer, 256, fptr)){
        i++;
    }
    fclose(fptr);
    return i;
}

void init_heights_array(group_t *group, int length)
{
    for (int i = 0; i < length; ++i) {
        group->heights[i] = 0;
    }
}

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubble_sort(group_t *group)
{
    int swap_flag = 1;
    int i = 0;
    while (swap_flag) {
        swap_flag = 0;
        i = 0;

        while(i < group->number_of_people - 1) {
            if(group->heights[i] > group->heights[i + 1]) {
                swap(&group->heights[i], &group->heights[i + 1]);
                swap_flag = 1;
            }
            i++;
        }
    }
}

int find_median(group_t *group)
{
    // in case of even number of people it returns higher median:
    return group->heights[group->number_of_people / 2];
}

int main()
{
    char* file_path = "../median.txt";

    // Creating groups and resetting their arrays to 0:
    int number_of_groups = count_lines(file_path);

    group_t groups[number_of_groups];

    for (int i = 0; i < number_of_groups; ++i) {
        init_heights_array(&groups[i], HEIGHTS_BUFFER);
        groups[i].number_of_people = 0;
    }

    FILE* fptr;
    if (!(fptr = fopen(file_path, "r"))) return -1;

    int line_index = 0;
    int row_index = 0;
    char buffer[100];
    char *word;
    int temp_data;

    // reading lines:
    while (fgets(buffer, 100, fptr)){

        row_index = 0;

        // read first part into groupname:
        word = strtok(buffer, ":");
        strcpy(groups[line_index].name, word);

        //read rest of the line into the heights array:
        word = strtok(NULL, ",");

        while (word != NULL) {
            temp_data = atoi(word);
            groups[line_index].heights[row_index] = temp_data;

            if (temp_data != 0) {
                groups[line_index].number_of_people++;
            }

            word = strtok(NULL, ",");
            row_index++;
        }
        line_index++;
    }

    for (int j = 0; j < number_of_groups; ++j) {
        printf("%s : ", groups[j].name);
        bubble_sort(&groups[j]);
        for (int k = 0; k < groups[j].number_of_people; ++k) {
            printf("%d, ", groups[j].heights[k]);
        }
        printf("\n");
    }

    for (int j = 0; j < number_of_groups; ++j) {
        printf("%s median: %d\n", groups[j].name, find_median(&groups[j]));
    }

    return 0;
}