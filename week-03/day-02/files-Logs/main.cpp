
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP addresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> findUniqueIPs(std::ifstream &filename);

int main() {

    std::ifstream inFile("../log.txt");

    std::vector<std::string> uniqueIPs;

    if (inFile.is_open()) {

        uniqueIPs = findUniqueIPs(inFile);

    } else {
        std::cout << "Couldn't open file. Exiting.";
        return -1;
    }

    inFile.close();

    return 0;
}

std::vector<std::string> findUniqueIPs(std::ifstream &filename)
{
    std::string logMessage;
    std::string block;
    std::vector<std::string> IPs;

    while (std::getline(filename, logMessage)) {

        std::istringstream stringParser(logMessage);

        while (std::getline(stringParser, block, ' ')) {
            if (block.length() == 11) {
                IPs.push_back(block);
            } else {
                continue;
            }
        }
    }

    return IPs;
}