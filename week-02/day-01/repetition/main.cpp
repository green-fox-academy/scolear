#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string reverse(const std::string& text)
{
    std::string result;

    for (int i = text.length() - 1; i >= 0; --i) {
        result.push_back(text.at(i));
    }
    return result;
}

char findMostCommonChar(const std::string& mondat)
{
    std::map<char, int> frequency;
    char mostCommon = '\0';

    for (char i : mondat) {
        if (i != ' ') {
            frequency[i]++;
        }
    }

    int max = 0;

    for (auto it : frequency) {
        if (it.second > max) {
            max = it.second;
            mostCommon = it.first;
        }
    }
    return mostCommon;
}

std::vector<std::string> parse(const std::string& sentence)
{
    std::vector<std::string> result;
    int wordCount = 0;
    std::string temp;

    for (int i = 0; i < sentence.length(); ++i) {
        temp.push_back(sentence[i]);
        if (sentence[i] == '.') {
            result.push_back(temp);
            wordCount = 0;
            temp.clear();
            i++;
            continue;
        }
        if (sentence[i] == ' ') {
            wordCount++;
            if (wordCount == 5) {
                result.push_back(temp);
                wordCount = 0;
                temp.clear();
            }
        }
    }
    return result;
}

bool firstLetterUpper(const std::string& text)
{
    if (std::islower(text[0])) return false;

    for (int i = 0; i < text.length() - 2; i++) {
        if (text[i] == '.') {
            if (std::islower(text[i + 2])) return false;
        }
    }
    return true;
}

bool weirdValidity(const std::vector<int>& arr)
{
    std::vector<int> sorted = arr;

    std::sort(sorted.begin(), sorted.end(), std::greater<>());
    int max = sorted[0];

    if (sorted.size() < max) return false;

    for (int i = 1; i < sorted.size(); ++i) {
        if (sorted[i] != max - i) return false;
    }

    return true;
}

std::vector<std::vector<int>> drawTable(int N)
{
    std::vector<std::vector<int>> table(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }
    return table;
}

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

    url.insert(url.find("//"), ":");
    url.replace(url.find("bots"), 4, "odds");
    std::cout << url << std::endl;

    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you" using the replace function

    quote.replace(quote.find("you") - 1, 1," always takes longer than ");
    std::cout << quote << std::endl;


    std::string todoText = " - Buy milk\n";
    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    todoText.insert(0, "My todo:\n");
    todoText.append(" - Download games:\n");
    todoText.append("\t - Diablo\n");

    std::cout << todoText << std::endl;


    std::string reversed = "\n.eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    std::map<std::string, std::string> phoneBook = {{"William A. Lathan", "405-709-1865"},
                                                    {"John K. Miller", "402-247-8568"},
                                                    {"Hortensia E. Foster", "606-481-6467"},
                                                    {"Amanda D. Newland", "319-243-5613"},
                                                    {"Brooke P. Askew", "307-687-2982"}};


    // What is John K. Miller's phone number?
    std::cout << phoneBook["John K. Miller"] << std::endl;
    // Whose phone number is 307-687-2982?
    for (auto & it : phoneBook) {
        if (it.second == "307-687-2982") std::cout << it.first << std::endl;
    }
    // Do we know Chris E. Myers' phone number?
    std::cout << (phoneBook.count("Chris E. Myers") ? "yes." : "no") << std::endl;

    std::map<std::string, int> products ={
                                            {"eggs", 200},
                                            {"milk", 200},
                                            {"fish", 400},
                                            {"apples", 150},
                                            {"bread", 50},
                                            {"chicken", 550},};

/*
    How much is the fish?
    What is the most expensive product?
    What is the average price?
    How many products' price is below 300?
    Is there anything we can buy for exactly 125?
    What is the cheapest product?
*/

    std::cout << products["fish"] << std::endl;
    
    int max = 0;
    int sum = 0;
    std::string mostExpensive;
    for (auto & it: products) {
        if (it.second > max) {
            max = it.second;
            mostExpensive = it.first;
        }
        sum += it.second;
    }
    std::cout << "Most expensive: " <<  mostExpensive << std::endl;
    std::cout << "Average price: " << sum / products.size() << std::endl;

    // beugro: array<int> parosak novekedve, paratlanok csokkenve

    std::vector<int> array = {12, 23, 5, 123, 3, 6423, 124, 645, 22, 65};

    std::vector<int> evens;
    std::vector<int> odds;

    for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 == 0) {
            evens.push_back(array[i]);
        } else {
            odds.push_back(array[i]);
        }
    }

    std::sort(evens.begin(), evens.end());
    std::sort(odds.begin(), odds.end(), std::greater<>());
    //std::reverse(odds.begin(), odds.end());
    evens.insert(evens.end(), odds.begin(), odds.end());
    for (auto & elem : evens) std::cout << elem << ' ';
    std::cout << std::endl;

    // beugro: array, sum minden Nedik elem, es szamoljuk ki az atlagat a novekedesnek

    std::vector<int> array2 = {12, 32, 53, 23, 65, 45, 26, 29, 83};
    int n = 2;
    sum = 0;
    std::vector<int> growthParameters;

    for (int i = n - 1; i < array2.size(); i += n) {
        sum += array2[i];
        growthParameters.push_back(array2[i]);
    }

    std::cout << sum / growthParameters.size() << std::endl;

    std::string mondat = "A Robi egy meleg allat, a Levi pedig szep.";

    char mostCommon = findMostCommonChar(mondat);

    printf("%c\n", mostCommon);

    std::string sentence = " Levi is meleg, es a Robi is szep.";

    mondat.insert(mondat.end(), sentence.begin(), sentence.end());

    std::vector<std::string> parsed = parse(mondat);

    for (const auto & j : parsed) {
        std::cout << j << std::endl;
    }

    std::cout << (firstLetterUpper(mondat) ? "cool" : "fix yo shit") << std::endl;

    std::vector<int> someArray = {1, 3, 5, 6, 4, 2};
    std::vector<int> someOtherArray = {1, 3, 5, 6, 10, 2};

    std::cout << (weirdValidity(someOtherArray) ? "yes" : "no") << std::endl;

    std::vector<std::vector<int>> multiplicationTable = drawTable(5);

    for (int k = 0; k < multiplicationTable[0].size(); ++k) {
        for (int i = 0; i < multiplicationTable[k].size(); ++i) {
            std::cout << multiplicationTable[k][i] << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}

