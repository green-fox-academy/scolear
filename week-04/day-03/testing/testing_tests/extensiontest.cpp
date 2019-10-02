#include <gtest/gtest.h>
#include <extension.h>

TEST(add, _2and3is5) {
    ASSERT_EQ(5, add(2, 3));
}

TEST(add, _1and4is5) {
    ASSERT_EQ(5, add(1, 4));
}

TEST(add, _2and5is7) {
    ASSERT_EQ(7, add(2, 5));
}

TEST(max_of_three, first) {
    ASSERT_EQ(5, maxOfThree(5, 4, 3));
}

TEST(max_of_three, third) {
    ASSERT_EQ(5, maxOfThree(3, 4, 5));
}

TEST(max_of_three, second) {
    ASSERT_EQ(5, maxOfThree(3, 5, 4));
}

TEST(median, four) {
    ASSERT_EQ(5, median({7, 5, 3, 5}));
}

TEST(median, five) {
    ASSERT_EQ(3, median({1, 2, 3, 4, 5}));
}

TEST(median, fiveagain) {
    ASSERT_EQ(3, median({1, 3, 2, 4, 5}));
}

TEST(is_vowel, a) {
    ASSERT_TRUE(isVowel('a'));
}

TEST(is_vowel, U) {
    ASSERT_TRUE(isVowel('U'));
}

TEST(is_vowel, c) {
    ASSERT_FALSE(isVowel('c'));
}

TEST(translate, bemutatkozik) {
    ASSERT_EQ("bevemuvutavatkovozivik", translate("bemutatkozik"));
}

TEST(translate, lagopus) {
    ASSERT_EQ("lavagovopuvus", translate("lagopus"));
}

TEST(translate, robert) {
    ASSERT_EQ("rovobevert", translate("robert"));
}
TEST(translate, gaama) {
    ASSERT_EQ("gavaavamava", translate("gaama"));
}
