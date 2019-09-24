#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void writeFile(std::string filePath, std::string word, int num)
{
    std::ofstream newFile(filePath);

    if(!newFile.is_open()) throw "Couldn't open file.";

    for (int i = 0; i < num; ++i) {
        newFile << word << std::endl;
    }
}

int main() {

    std::string path = "../newfile.txt";
    std::string word = "apple";
    int numba = 10;

    try {
        writeFile(path, word, numba);
    } catch (char const *errorMessage) {
        std::cout << errorMessage;
    }

    return 0;
}