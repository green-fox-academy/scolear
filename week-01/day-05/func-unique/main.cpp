#include <iostream>
#include <string>
#include <bits/stdc++.h>

int unique(int[], int result[], int);

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    //  should print: `[1, 11, 34, 52, 61]`

    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int result[size];

    int newsize = unique(numbers, result, size);

    for (int i = 0; i < newsize; ++i) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

int unique(int array[], int result[], int size) {
    // Unfortunately this only leaves elements who only appear once, and doesnt spare the others...

    int k = 0;
    bool flag;

    std::sort(array, array + size);

    for (int i = 0; i < size; ++i) {
        flag = false;
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                continue;
            } else {
                if (array[i] == array[j]) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            continue;
        } else {
            result[k] = array[i];
            k++;
        }
    }


    return k;
}


