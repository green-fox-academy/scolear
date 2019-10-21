#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *word, char ch) {

    int flag = 0;
    int counter = 0;

    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == ch) {
            if (flag == 0) {
                flag = 1;
            } else {
                return counter - 1;
            }
        }
        if (flag == 1) {
            counter++;
        }
    }
    return -1;
}

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";
    char repeating_char = 'g';

    // the output should be: 6 (in this case the repeating char was 'g')
    printf("%d", count_between_chars(word, repeating_char));

    return 0;
}