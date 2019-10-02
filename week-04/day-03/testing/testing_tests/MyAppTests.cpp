#include <gtest/gtest.h>
#include <myClass.h>
#include <netdb.h>

class myClassTest : public ::testing::Test {
public:
    myClass klasszi;


};

TEST_F(myClassTest, Subtest1){

    ASSERT_TRUE(klasszi.printName() == -1);
    std::cout << "After ASSERT" << std::endl;
}

TEST_F(myClassTest, Subtest2){

    EXPECT_TRUE(klasszi.printName() == -1);
    std::cout << "After EXPECT" << std::endl;
}