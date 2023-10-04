#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

const std::vector<std::string> simple_strs{{"a"s}, {"b"s}, {"c"s}, {"d"s}, {"e"s}};
const std::string simple_str_empty_separator{"abcde"s};
const std::string simple_str_underscore{"a_b_c_d_e"s};

const std::string empty_str{""s};
const std::string underscore{"_"s};

// Normal cases
TEST(TestSplitByString, SimpleStringsEmptySeparator) {
	EXPECT_EQ(stomfoolery::split(simple_str_empty_separator, empty_str), simple_strs);
}

TEST(TestSplitByString, SimpleStringsEmptySeparatorOperator) {
	EXPECT_EQ(simple_str_empty_separator / empty_str, simple_strs);
}

TEST(TestSplitByString, SimpleStringsUnderscore) {
	EXPECT_EQ(stomfoolery::split(simple_str_underscore, underscore), simple_strs);
}

TEST(TestSplitByString, SimpleStringsUnderscoreOperator) {
	EXPECT_EQ(simple_str_underscore / underscore, simple_strs);
}

// Edge cases
