
#include <stdio.h>
#include <stdlib.h>

char *to_string (int num) {

    int length = snprintf( NULL, 0, "%d", num );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", num );

    return str;
}

int sum_digits (char *string) {

    int i = 0;
    int sum = 0;

    while(string[i] != '\0') {
        sum += string[i] - '0';
        i++;
    }
    return sum;
}

int sum_digits_equal(int num1, int num2) {

    char * num1_as_string = to_string(num1);
    char * num2_as_string = to_string(num2);

    if (sum_digits(num1_as_string) == sum_digits(num2_as_string)) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of digits are equal and 0 otherwise

    int a;
    int b;

    puts("Please enter two numbers:");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("Are they equal: %s", sum_digits_equal(a,b) ? "Yes" : "No");

    return 0;
}