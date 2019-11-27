#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_in_sentence(char** word, char** sentence)
{
    char *upper_temp_word = (char*) malloc(strlen(*word) * sizeof(char));
    char *upper_temp_sentence = (char*) malloc(strlen(*sentence) * sizeof(char));

    for (int i = 0; i < strlen(*word); ++i) {
        upper_temp_word[i] = toupper((*word)[i]);
    }
    for (int i = 0; i < strlen(*sentence); ++i) {
        upper_temp_sentence[i] = toupper((*sentence)[i]);
    }
    return (strstr(upper_temp_sentence, upper_temp_word) ? 1 : 0);
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "apple";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 1
    printf("%d" , is_in_sentence(&word, &sentence));

    return 0;
}