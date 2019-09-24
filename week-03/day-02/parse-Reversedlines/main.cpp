#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.


    std::ifstream inFile("../reversed-lines.txt");
    std::string line;

    if(!inFile.is_open()) {
        std::cout << "Unable to open file.";
        return -1;

    } else {
        while(std::getline(inFile, line)) {
            for (int i = 0; i < (line.length() / 2); ++i) {

                char temp;
                temp = line[i];
                line[i] = line[line.length() - i - 1];
                line[line.length() - i - 1] = temp;

            }
            std::cout << line << std::endl;
        }
    }

    inFile.close();

    return 0;
}