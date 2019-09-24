#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream inFile("../duplicated-chars.txt");
    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string word;

        while (std::getline(ss, word, ' ')) {

            for (int i = 0; i < word.length(); ++i) {
                if (word[i + 1] == word[i]) {
                    word.erase(i, 1);
                }
            }
            std::cout << word << ' ';
        }



    }



    return 0;
}