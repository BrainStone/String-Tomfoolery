#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

constexpr std::size_t repeat = 5;

const std::vector<std::string> simple_strs{{"a"s}, {"a"s}, {"a"s}, {"a"s}, {"a"s}};
const std::string simple_str_empty_glue{"aaaaa"s};
const std::string simple_str_underscore{"a_a_a_a_a"s};
const std::string complex_str{"Test?"s};
const std::string complex_str_repeated{"Test?Test?Test?Test?Test?"s};
const std::wstring simple_wstr{L"a"s};
const std::wstring simple_wstr_repeated{L"aaaaa"s};
const std::wstring complex_wstr{L"Test?"s};
const std::wstring complex_wstr_repeated{L"Test?Test?Test?Test?Test?"s};

// const std::string_view simple_str_view{simple_str};
const std::string_view complex_str_view{complex_str};
const std::wstring_view simple_wstr_view{simple_wstr};
const std::wstring_view complex_wstr_view{complex_wstr};

const std::string empty_str{""s};
const std::string underscore{"_"s};

// Normal cases
TEST(TestJoin, SimpleStringsEmptyGlue) {
	EXPECT_EQ(stomfoolery::join(simple_strs, empty_str), simple_str_empty_glue);
}

TEST(TestJoin, SimpleStringsUnderscore) {
	EXPECT_EQ(stomfoolery::join(simple_strs, underscore), simple_str_underscore);
}

// Edge cases
