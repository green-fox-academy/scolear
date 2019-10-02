#include "extension.h"

#include <algorithm>
#include <sstream>

int add(int a, int b)
{
    return a + b;
}

int maxOfThree(int a, int b, int c)
{
    int max = a;
    if (b > a) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int median(std::vector<int> pool) {
    std::sort(pool.begin(), pool.end());
    return pool.at((pool.size()-1)/2);
}

bool isVowel(char c) {
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i', 'A', 'E', 'I', 'O', 'U'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::vector<std::string> split(const std::string& str, char delim)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> v;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string join(const std::string& separator, const std::vector<std::string>& array)
{
    std::stringstream ss;
    for(int i = 0; i < array.size(); ++i)
    {
        ss << array[i];
        if(i != array.size() - 1)
        {
            ss << separator;
        }
    }

    return ss.str();
}

std::string translate(const std::string& hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length; i++) {
        const char c = teve.at(i);
        if (isVowel(c)) {
            teve = join(std::string(1, c) + "v" + std::string(1, c), split(teve, c));
            i+=2;
            length+=2;
        }
    }
    return teve;
}

// Check out the folder. There's a work file and a test file.

//  -  Run the tests, all 10 should be green (passing).
//  -  The implementations though are not quite good.
//  -  Create tests that'll fail, and will show how the implementations are wrong(You can assume that the implementation of join and split are good)
//  -  After creating the tests, fix the implementations
//  -  Check again, if you can create failing tests
//  -  Implement if needed