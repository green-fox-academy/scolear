#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream newFile("../my-file.txt");

    newFile << "Robert Tera\n";

    newFile.close();

    return 0;
}