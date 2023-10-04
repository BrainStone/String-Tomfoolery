#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

const std::vector<std::string> simple_strs{{"a"s}, {"a"s}, {"a"s}, {"a"s}, {"a"s}};
const std::string simple_str_empty_separator{"aaaaa"s};
const std::string simple_str_underscore{"a_a_a_a_a"s};

const std::string empty_str{""s};
const std::string underscore{"_"s};

// Normal cases
TEST(TestJoin, SimpleStringsEmptyGlue) {
	EXPECT_EQ(stomfoolery::join(simple_strs, empty_str), simple_str_empty_separator);
}

TEST(TestJoin, SimpleStringsUnderscore) {
	EXPECT_EQ(stomfoolery::join(simple_strs, underscore), simple_str_underscore);
}

// Edge cases
