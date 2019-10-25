// Every line contains the name of the group and after a colon, the height of people in the group separated by commas
// Find the group where the median is the lowest.
// Note that the groups do not necessarily contain the same amount of people

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct group {
    char name[10];
    int heights[50];
} group_t;

int count_lines (char* filename) {
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

void init_heights_array (group_t *group, int length) {
    for (int i = 0; i < length; ++i) {
        group->heights[i] = 0;
    }
}

int main()
{
    char* file_path = "../median.txt";

    // Creating groups and resetting their arrays to 0:
    int number_of_groups = count_lines(file_path);

    group_t groups[number_of_groups];

    for (int i = 0; i < number_of_groups; ++i) {
        init_heights_array(&groups[i], 50);
    }

    FILE* fptr;
    if (!(fptr = fopen(file_path, "r"))) return -1;

    int line_index = 0;
    int row_index = 0;
    char buffer[100];
    char *word;

    // reading lines:
    while (fgets(buffer, 100, fptr)){

        row_index = 0;

        // read first part into groupname:
        word = strtok(buffer, ":");
        strcpy(groups[line_index].name, word);

        //read rest of the line into the heights array:
        word = strtok(NULL, ",");

        while (word != NULL) {

            groups[line_index].heights[row_index] = atoi(word);

            word = strtok(NULL, ",");
            row_index++;
        }
        line_index++;
    }

    for (int j = 0; j < number_of_groups; ++j) {
        printf("%s\n", groups[j].name);
    }

    // todo: find medians of heights arrays. Consider data ends at zeroes. We have to sort them first.

    return 0;
}