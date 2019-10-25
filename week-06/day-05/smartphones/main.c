/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CURRENT_YEAR 2019

typedef enum screen_size {
    BIG,
    MEDIUM,
    SMALL
} screen_size_t;

typedef struct phone {
    char name[256];
    int year;
    screen_size_t screen_size;
} smartphone_t;

screen_size_t get_screen_size (int size) {
    if (size < 12) {
        return SMALL;
    } else if (size < 15) {
        return MEDIUM;
    } else {
        return BIG;
    }
}

char* get_oldest_phone (smartphone_t phones[], int size) {

    int oldest_index = 0;
    int oldest_year = phones[0].year;

    for (int i = 0; i < size; ++i) {
        if (phones[i].year < oldest_year) {
            oldest_year = phones[i].year;
            oldest_index = i;
        }
    }
    return phones[oldest_index].name;
}

int get_screen_size_count(smartphone_t phones[], int array_size, screen_size_t screen_size) {

    int count = 0;
    for (int i = 0; i < array_size; ++i) {
        if (phones[i].screen_size == screen_size) {
            count++;
        }
    }
    return count;
}

int calculate_price (smartphone_t *phone) {

    int price = 300;
    int age = CURRENT_YEAR - phone->year;

    switch (phone->screen_size) {
        case SMALL : break;
        case MEDIUM: price += 100; break;
        case BIG: price *= 2; break;
    }

    if (age >= 5) {
        price -= 250;
    } else {
        price -= age * 50;
    }
    return price;
}

int main()
{
    // without dynamic memory allocation, this is annoyingly rigid:
    smartphone_t phones[15];
    FILE* fptr;

    if (!(fptr = fopen("../phones.txt", "r"))) return -1;

    int line_index = 0;
    int row_index = 0;
    char buffer[100];
    char *p;

    // reading lines:
    while(fgets(buffer, 100, fptr)){

        p = strtok(buffer, " ");
        row_index = 0;

        while (p != NULL) {
            if (row_index == 0) strcpy(phones[line_index].name, p);

            if (row_index == 1) phones[line_index].year = atoi(p);

            if (row_index == 2) phones[line_index].screen_size = get_screen_size(atoi(p));

            p = strtok(NULL, " ");
            row_index++;
        }

        line_index++;
    }

    printf("%s %d %d \n", phones[0].name, phones[0].year, phones[0].screen_size);

    printf("The %s is the oldest device in the database\n", get_oldest_phone(phones, 15));

    printf("There are %d phones with BIG screen size.\n", get_screen_size_count(phones, 15, BIG));
    printf("There are %d phones with SMALL screen size.\n", get_screen_size_count(phones, 15, SMALL));

    FILE* outfile;
    if (!(outfile = fopen("../prices.txt", "w"))) return -1;

    for (int i = 0; i < 15; ++i) {
        fprintf(outfile, "%s %d\n", phones[i].name, calculate_price(&phones[i]));
    }
    fclose(outfile);

    return 0;
}