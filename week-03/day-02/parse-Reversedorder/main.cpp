#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream inFile("../reversed-order.txt");
    std::string line;
    std::vector<std::string> stringVector;

    if (inFile.is_open()) {

        while (getline(inFile, line)) {
            stringVector.push_back(line);
        }

    } else {
        std::cout << "Unable to open file.";
    }

    inFile.close();

    for (int i = stringVector.size() - 1; i >= 0; --i) {
        std::cout << stringVector[i] << std::endl;
    }

    return 0;
}