#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes
// the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int copyFileContents(std::string fileToCopy, std::string fileToCopyTo)
{
    std::ifstream oldFile(fileToCopy);
    std::ofstream newFile;
    std::string line;

    if(!oldFile.is_open()) {

        throw "Couldn't open file to copy.";
        return 0;                               // it could return 0 as a flag too instead of the exception

    } else {
        newFile.open(fileToCopyTo);
        while(getline(oldFile, line)) {
            newFile << line << std::endl;
        }
        newFile.close();
        oldFile.close();
        return 1;
    }
    return 0;
}

int main() {

    std::string oldF = "../test.txt";
    std::string newF = "../test_copy.txt";

    try {
        copyFileContents(oldF, newF);
    } catch (char const *errorMessage) {
        std::cout << errorMessage;
    }

    return 0;
}