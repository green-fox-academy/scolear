
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP addresses.
// Write a function that returns the GET / POST request ratio.

void parseLogs(std::ifstream &filename, std::vector<std::string> &IPs, std::vector<std::string> &requests);
float findRatio(std::vector<std::string>);
std::vector<std::string> findUniqueIPs(std::vector<std::string>);

int main() {

    std::ifstream inFile("../log.txt");

    std::vector<std::string> IPs;
    std::vector<std::string> requests;
    std::vector<std::string> uniqueIPs;
    float postGetRatio;

    if (inFile.is_open()) {

        parseLogs(inFile, IPs, requests);
        
        uniqueIPs = findUniqueIPs(IPs);
        postGetRatio = findRatio(requests);

        for (int i = 0; i < uniqueIPs.size(); ++i) {
            std::cout << uniqueIPs[i] << std::endl;
        }

        std::cout << "Number of Unique IPs: " << uniqueIPs.size() << std::endl;
        std::cout << "POST/GET RATIO: " << postGetRatio;


    } else {
        std::cout << "Couldn't open file. Exiting.";
        return -1;
    }

    inFile.close();

    return 0;
}

std::vector<std::string> findUniqueIPs(std::vector<std::string> ipVector)
{
    std::vector<std::string> uniqueIPs;
    std::map<std::string, int> countMap;
    std::pair<std::map<std::string, int>::iterator, bool> result;

    // We find unique elements in vector by creating a map of ["IP", occurrence]:
    for (int i = 0; i < ipVector.size(); ++i) {
        result = countMap.insert(std::pair<std::string, int> (ipVector[i], 1));     // returns false if element already existed as a key
        if (result.second == false) {
            result.first->second++;
        }
    }

    // Iterating over the map, we push our keys into our return vector:
    for (std::map<std::string, int>::iterator it = countMap.begin(); it != countMap.end(); ++it) {
        uniqueIPs.push_back(it->first);
    }

    return uniqueIPs;
}

void parseLogs(std::ifstream &filename, std::vector<std::string> &IPs, std::vector<std::string> &requests)
{
    std::string logMessage;
    std::string block;

    while (std::getline(filename, logMessage)) {

        std::istringstream stringParser(logMessage);

        while (std::getline(stringParser, block, ' ')) {
            if (block.length() == 11) {
                IPs.push_back(block);
            } else if (block == "POST" || block == "GET") {
                requests.push_back(block);
            } else {
                continue;
            }
        }
    }
}

float findRatio(std::vector<std::string> requests)
{
    int GET = 0;
    int POST = 0;

    for (int i = 0; i < requests.size(); ++i) {
        if (requests[i] == "GET") {
            GET++;
        } else if (requests[i] == "POST") {
            POST++;
        }
    }
    return (float)POST / GET;
}