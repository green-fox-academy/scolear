#include <gtest/gtest.h>
#include <string>

std::string getApple(){
    return "apple";
}

TEST(TestCase, Subtest1) {
    ASSERT_EQ(getApple(), "apple");
}