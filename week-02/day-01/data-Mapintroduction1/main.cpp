/*
.Create an empty map where the keys are integers and the values are characters
.Print out whether the map is empty or not
.Add the following key-value pairs to the map
Key Value
97 	a
98 	b
99 	c
65 	A
66 	B
67 	C

.Print all the keys
.Print all the values
.Add value D with the key 68
.Print how many key-value pairs are in the map
.Print the value that is associated with key 99
.Remove the key-value pair where with key 97
.Print whether there is an associated value with key 100 or not
.Remove all the key-value pairs
*/

#include <iostream>
#include <map>

int main() {

    std::map<int, char> aMap;

    std::cout << "Empty? : " << (aMap.empty() ? "yes" : "no") << std::endl;

    aMap.insert(std::make_pair(97, 'a'));
    aMap.insert(std::make_pair(98, 'b'));
    aMap.insert(std::make_pair(99, 'c'));
    aMap.insert(std::make_pair(65, 'A'));
    aMap.insert(std::make_pair(66, 'B'));
    aMap.insert(std::make_pair(67, 'C'));
/*
    std::cout << aMap.find('a')->first << std::endl;
    std::cout << aMap.find('b')->first << std::endl;
    std::cout << aMap.find('c')->first << std::endl;
    std::cout << aMap.find('A')->first << std::endl;
    std::cout << aMap.find('B')->first << std::endl;
    std::cout << aMap.find('C')->first << std::endl;
*/
    // a more elegant solution:
    for (std::map<int, char>::iterator it = aMap.begin(); it != aMap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    aMap.insert(std::make_pair(68, 'D'));

    std::cout << aMap.size() << std::endl;

    std::cout << aMap[99] << std::endl;

    aMap.erase(97);

    std::cout << aMap.count(100) << std::endl;

    aMap.clear();

    return 0;
}