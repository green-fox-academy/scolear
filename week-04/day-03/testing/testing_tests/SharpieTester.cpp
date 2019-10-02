#include <gtest/gtest.h>
#include <Sharpie.h>
#include <string>

class SharpieTestClass : public ::testing::Test {
public:
    SharpieTestClass() : s("blue", 1) {};
    Sharpie s;
};

TEST_F(SharpieTestClass, useTest){
    s.use();
    ASSERT_EQ(s.getInkAmount(), 99);
}

TEST_F(SharpieTestClass, overUseTest){
    for (int i = 0; i < 10000; ++i) {
        s.use();
    }
    ASSERT_GE(s.getInkAmount(), 0);
}
