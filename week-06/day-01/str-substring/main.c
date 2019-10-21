#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_substring(char *str1, char *str2) {

    unsigned long str1len = strlen(str1);
    unsigned long str2len = strlen(str2);

    if (str1len == str2len) {
        return -1;
    } else {
        if (str1len > str2len) {
            if (strstr(str1, str2) != NULL) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (strstr(str2, str1) != NULL) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}


int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char str1[20];
    char str2[20];

    printf("Please enter first string:\n");
    scanf("%s", str1);

    printf("Please enter second string:\n");
    scanf("%s", str2);

    printf("One string is the substring of the other: %s", is_substring(str1, str2) == 1 ? "True" : "False");

    return 0;
}