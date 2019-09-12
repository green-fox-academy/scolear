#include <iostream>
#include <string>

int main(int argc, char* args[]) {

/*
    // - Create an array variable named `q`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print the third element of `q`

    int q[] = {4, 5, 6, 7};

    std::cout << q[2];

    return 0;
*/


/*
    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print "p2 is longer" if `p2` has more elements than `p1`

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

    bool flag = (sizeof(p1) / sizeof(p1[0]) < sizeof(p2) / sizeof(p2[0])); // true if p1 has less elements

    if (flag) {
        std::cout << "p2 is longer." << std::endl;
    } else {
        std::cout << "p1 has more." << std::endl;
    }
    return 0;
*/


    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element

    int r[] = {54, 23, 66, 12};

    std::cout << r[1] + r[2] << std::endl;

    return 0;
}