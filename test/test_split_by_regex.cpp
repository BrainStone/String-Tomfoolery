#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

const std::vector<std::string> simple_strs_empty_start{{""s}, {"a"s}, {"b"s}, {"c"s}, {"d"s}, {"e"s}};
const std::vector<std::string> simple_strs{{"a"s}, {"b"s}, {"c"s}, {"d"s}, {"e"s}};
const std::string simple_str_empty_separator{"abcde"s};
const std::string simple_str_underscore{"a b  c\td\n  \t\n\re"s};

const std::regex empty_regex{""};
const std::regex whitespaces{R"(\s+)"};

// Normal cases
TEST(TestSplitByRegex, SimpleStringsEmptySeparator) {
	EXPECT_EQ(stomfoolery::split(simple_str_empty_separator, empty_regex), simple_strs_empty_start);
}

TEST(TestSplitByRegex, SimpleStringsEmptySeparatorOperator) {
	EXPECT_EQ(simple_str_empty_separator / empty_regex, simple_strs_empty_start);
}

TEST(TestSplitByRegex, SimpleStringsWhitespaces) {
	EXPECT_EQ(stomfoolery::split(simple_str_underscore, whitespaces), simple_strs);
}

TEST(TestSplitByRegex, SimpleStringsWhitespacesOperator) {
	EXPECT_EQ(simple_str_underscore / whitespaces, simple_strs);
}

// Edge cases
