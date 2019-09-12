#include <iostream>

int main(int argc, char* args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 || i % 2 == 0) {
                std::cout << "%";
                std::cout << " ";
            } else {
                std::cout << " ";
                std::cout << "%";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}