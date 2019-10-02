#include <gtest/gtest.h>
#include <myClass.h>

TEST(myClassTest, Subtest1){
    myClass klasszi;
    ASSERT_TRUE(klasszi.printName() == -1);
}