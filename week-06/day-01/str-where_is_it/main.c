#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_index(char *str1, char ch);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char str1[20];
    char ch;

    printf("Please enter string:\n");
    scanf("%s", str1);

    // this next command is required to consume the newline character:
    getchar();

    printf("Please enter character:\n");
    scanf("%c", &ch);

    printf("Character %c in string %s can be found at index %d", ch, str1, find_index(str1, ch));

    return 0;
}

int find_index(char *str1, char ch) {
    for (int i = 0; i < strlen(str1); ++i) {
        if (str1[i] == ch) {
            return i;
        }
    }
    return -1;
}