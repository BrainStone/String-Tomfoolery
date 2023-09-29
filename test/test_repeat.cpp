#include <string>
#include <string_view>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

constexpr std::size_t repeat = 5;

const std::string simple_str{"a"s};
const std::string simple_str_repeated{"aaaaa"s};
const std::string complex_str{"Test?"s};
const std::string complex_str_repeated{"Test?Test?Test?Test?Test?"s};
const std::wstring simple_wstr{L"a"s};
const std::wstring simple_wstr_repeated{L"aaaaa"s};
const std::wstring complex_wstr{L"Test?"s};
const std::wstring complex_wstr_repeated{L"Test?Test?Test?Test?Test?"s};

const std::string_view simple_str_view{simple_str};
const std::string_view complex_str_view{complex_str};
const std::wstring_view simple_wstr_view{simple_wstr};
const std::wstring_view complex_wstr_view{complex_wstr};

const std::string empty_str{""s};

// Normal cases
TEST(TestRepeat, SimpleString) {
	EXPECT_EQ(stomfoolery::repeat(simple_str, repeat), simple_str_repeated);
}

TEST(TestRepeat, SimpleStringOperator) {
	EXPECT_EQ(simple_str * repeat, simple_str_repeated);
}

TEST(TestRepeat, ComplexString) {
	EXPECT_EQ(stomfoolery::repeat(complex_str, repeat), complex_str_repeated);
}

TEST(TestRepeat, ComplexStringOperator) {
	EXPECT_EQ(complex_str * repeat, complex_str_repeated);
}

TEST(TestRepeat, SimpleWstring) {
	EXPECT_EQ(stomfoolery::repeat(simple_wstr, repeat), simple_wstr_repeated);
}

TEST(TestRepeat, SimpleWstringOperator) {
	EXPECT_EQ(simple_wstr * repeat, simple_wstr_repeated);
}

TEST(TestRepeat, ComplexWstring) {
	EXPECT_EQ(stomfoolery::repeat(complex_wstr, repeat), complex_wstr_repeated);
}

TEST(TestRepeat, ComplexWstringOperator) {
	EXPECT_EQ(complex_wstr * repeat, complex_wstr_repeated);
}

TEST(TestRepeat, SimpleStringView) {
	EXPECT_EQ(stomfoolery::repeat(simple_str_view, repeat), simple_str_repeated);
}

TEST(TestRepeat, SimpleStringViewOperator) {
	EXPECT_EQ(simple_str_view * repeat, simple_str_repeated);
}

TEST(TestRepeat, ComplexStringViewOperator) {
	EXPECT_EQ(complex_str_view * repeat, complex_str_repeated);
}

TEST(TestRepeat, ComplexStringView) {
	EXPECT_EQ(stomfoolery::repeat(complex_str_view, repeat), complex_str_repeated);
}

TEST(TestRepeat, SimpleWstringView) {
	EXPECT_EQ(stomfoolery::repeat(simple_wstr_view, repeat), simple_wstr_repeated);
}

TEST(TestRepeat, SimpleWstringViewOperator) {
	EXPECT_EQ(simple_wstr_view * repeat, simple_wstr_repeated);
}

TEST(TestRepeat, ComplexWstringViewOperator) {
	EXPECT_EQ(complex_wstr_view * repeat, complex_wstr_repeated);
}

TEST(TestRepeat, ComplexWstringView) {
	EXPECT_EQ(stomfoolery::repeat(complex_wstr_view, repeat), complex_wstr_repeated);
}

// Edge cases
TEST(TestRepeat, ZeroRepeats) {
	EXPECT_EQ(stomfoolery::repeat(simple_str, 0), empty_str);
}

TEST(TestRepeat, ZeroRepeatsOperator) {
	EXPECT_EQ(simple_str * 0, empty_str);
}

TEST(TestRepeat, OneRepeat) {
	EXPECT_EQ(stomfoolery::repeat(simple_str, 1), simple_str);
}

TEST(TestRepeat, OneRepeatOperator) {
	EXPECT_EQ(simple_str * 1, simple_str);
}

TEST(TestRepeat, EmtpyString) {
	EXPECT_EQ(stomfoolery::repeat(empty_str, repeat), empty_str);
}

TEST(TestRepeat, EmtpyStringOperator) {
	EXPECT_EQ(empty_str * repeat, empty_str);
}
