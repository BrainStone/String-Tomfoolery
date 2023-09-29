#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

constexpr std::size_t repeat = 5;
const std::string simple_str{"a"s};
const std::string simple_str_repeated{"aaaaa"s};
const std::wstring simple_wstr{L"a"s};
const std::wstring simple_wstr_repeated{L"aaaaa"s};

TEST(TestRepeat, SimpleString) {
	EXPECT_EQ(stomfoolery::repeat(simple_str, repeat), simple_str_repeated);
}

TEST(TestRepeat, SimpleWstring) {
	EXPECT_EQ(stomfoolery::repeat(simple_wstr, repeat), simple_wstr_repeated);
}
