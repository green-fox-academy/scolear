#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream inFile("../reversed-order.txt");
    std::string line;

    if (inFile.is_open()) {




    } else {
        std::cout << "Unable to open file.";
    }
    return 0;
}