#include <gtest/gtest.h>
#include <string>

std::string getApple(){
    return "apple";
}

int sum(std::vector<int> integers) {
    int sum = 0;
    for(int i : integers) {
        sum += i;
    }
    return sum;
}

TEST(TestCase, Subtest1) {
    ASSERT_EQ(getApple(), "apple");
}

TEST(TestCase, Subtest2) {
    std::vector<int> intList = {12, 13, 5, 10};
    ASSERT_EQ(sum(intList), 40);
}
TEST(TestCase, Subtest3) {
    std::vector<int> intList = {};
    ASSERT_EQ(sum(intList), 0);
}
TEST(TestCase, Subtest4) {
    std::vector<int> intList = {12};
    ASSERT_EQ(sum(intList), 12);
}
TEST(TestCase, Subtest5) {
    std::vector<int> intList = {12, -12, 5, 10};
    ASSERT_EQ(sum(intList), 15);
}

// Anagram checker testing:

bool isAnagram(std::string first, std::string second) {

    int firstLength = first.length();
    int secondLength = second.length();

    if (firstLength != secondLength) {
        return false;
    } else {
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        for (int i = 0; i < firstLength; ++i) {
            if (first[i] != second[i]) {
                return false;
            }
        }
        return true;
    }
}

TEST(TestCase, Subtest6) {
    std::string str1 = "anagram";
    std::string str2 = "managra";

    std::string str3 = "valami";
    std::string str4 = "masvalami";

    ASSERT_FALSE(isAnagram(str3, str4));
    ASSERT_TRUE(isAnagram(str1, str2));
}

// Letter counting function tester

std::map<char, int> countLetters(std::string input) {

    std::map<char, int> m;
    for (int i = 0; i < input.length(); i++){
        m[input[i]]++;
    }
    return m;
}

TEST(TestCase, countLettersTest) {
    std::string testInput = "Anagramma";
    ASSERT_EQ(countLetters(testInput)['A'], 1);
    ASSERT_EQ(countLetters(testInput)['a'], 3);
    ASSERT_EQ(countLetters(testInput)['b'], 0);
}