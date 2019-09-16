#include <iostream>
#include <map>

int main() {

    std::map<std::string, std::string> aMap =
    {
        {"978-1-60309-452-8", "A Letter to Jo" },
        {"978-1-60309-459-7", "Lupus" },
        {"978-1-60309-444-3", "Red Panda and Moon Bear"},
        {"978-1-60309-461-0", "The Lab"}
    };

    // Print all the key-value pairs in the following format
    for (std::map<std::string, std::string >::iterator it = aMap.begin(); it != aMap.end(); it++) {
        std::cout << it->second << " (ISBN: " << it->first << ")" << std::endl;
    }

    // Remove the key-value pair with key 978-1-60309-444-3
    aMap.erase("978-1-60309-444-3");

    // Remove the key-value pair with value The Lab
    for (std::map<std::string, std::string >::iterator it = aMap.begin(); it != aMap.end(); it++) {
        if (it->second == "The Lab") {
            aMap.erase(it);
        }
    }

    // Add the following key-value pairs to the map
    aMap.insert(std::make_pair("978-1-60309-450-4", "They Called Us Enemy"));
    aMap.insert(std::make_pair("978-1-60309-453-5", "Why Did We Trust Him?"));

    // Print whether there is an associated value with key 478-0-61159-424-8 or not
    aMap.count("478-0-61159-424-8") ? std::cout << "Yes." : std::cout << "Nope.\n";

    // Print the value associated with key 978-1-60309-453-5
    std::cout << aMap["978-1-60309-453-5"];

    return 0;
}