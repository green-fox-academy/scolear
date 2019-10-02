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