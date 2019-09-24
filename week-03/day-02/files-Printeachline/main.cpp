#include <iostream>
#include <fstream>
#include <exception>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file first.

    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {

        myFile.open("../my-file.txt");
        std::string text;

        try {
            while(!myFile.eof()) {
                getline(myFile, text);
                std::cout << text << std::endl;
            }
        } catch (std::ifstream::failure& e) {
            if (myFile.eof()) {
                myFile.close();
            } else {
                throw e;
            }
        }

    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}