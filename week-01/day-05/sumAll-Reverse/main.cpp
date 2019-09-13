#include <iostream>
#include <string>

int main(int argc, char* args[]) {

/*
    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    int ai[] = {3, 4, 5, 6, 7};
    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        sum += ai[i];
        std::cout << sum << std::endl;
    }

    return 0;
*/


    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[] = {3, 4, 5, 6, 7};
    int temp;
    int j = 4;

    for (int i = 0; i < j; ++i) {
        temp = aj[i];
        aj[i] = aj[j];
        aj[j] = temp;
        j--;
    }

    for (int k = 0; k < 5; ++k) {
        std::cout << aj[k];

    }

    return 0;
}