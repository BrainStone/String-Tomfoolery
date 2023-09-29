#include <string>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"
#include "stomfoolery.hpp"

using namespace std::string_literals;

constexpr std::size_t divisions = 5;

const std::string simple_str_even{"aaaaa"s};
const std::string simple_str_uneven{"aaaaaaa"s};
const std::vector<std::string> simple_str_split_even{{"a"s}, {"a"s}, {"a"s}, {"a"s}, {"a"s}};
const std::vector<std::string> simple_str_split_uneven{{"aa"s}, {"aa"s}, {"a"s}, {"a"s}, {"a"s}};
const std::string complex_str_even{"Test?Test?Test?Test?Test?"s};
const std::string complex_str_uneven{"Test?XTest?XTest?Test?Test?"s};
const std::vector<std::string> complex_str_split_even{{"Test?"s}, {"Test?"s}, {"Test?"s}, {"Test?"s}, {"Test?"s}};
const std::vector<std::string> complex_str_split_uneven{{"Test?X"s}, {"Test?X"s}, {"Test?"s}, {"Test?"s}, {"Test?"s}};
const std::wstring simple_wstr_even{L"aaaaa"s};
const std::wstring simple_wstr_uneven{L"aaaaaaa"s};
const std::vector<std::wstring> simple_wstr_split_even{{L"a"s}, {L"a"s}, {L"a"s}, {L"a"s}, {L"a"s}};
const std::vector<std::wstring> simple_wstr_split_uneven{{L"aa"s}, {L"aa"s}, {L"a"s}, {L"a"s}, {L"a"s}};
const std::wstring complex_wstr_even{L"Test?Test?Test?Test?Test?"s};
const std::wstring complex_wstr_uneven{L"Test?XTest?XTest?Test?Test?"s};
const std::vector<std::wstring> complex_wstr_split_even{
    {L"Test?"s}, {L"Test?"s}, {L"Test?"s}, {L"Test?"s}, {L"Test?"s}};
const std::vector<std::wstring> complex_wstr_split_uneven{
    {L"Test?X"s}, {L"Test?X"s}, {L"Test?"s}, {L"Test?"s}, {L"Test?"s}};

const std::string_view simple_str_view_even{simple_str_even};
const std::string_view simple_str_view_uneven{simple_str_uneven};
const std::string_view complex_str_view_even{complex_str_even};
const std::string_view complex_str_view_uneven{complex_str_uneven};
const std::wstring_view simple_wstr_view_even{simple_wstr_even};
const std::wstring_view simple_wstr_view_uneven{simple_wstr_uneven};
const std::wstring_view complex_wstr_view_even{complex_wstr_even};
const std::wstring_view complex_wstr_view_uneven{complex_wstr_uneven};

const std::vector<std::string> empty_container{};
const std::vector<std::string> one_element_container{{"aaaaa"s}};

// Normal cases
TEST(TestSplitByInt, SimpleStringEven) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, divisions), simple_str_split_even);
}

TEST(TestSplitByInt, SimpleStringUneven) {
	EXPECT_EQ(stomfoolery::split(simple_str_uneven, divisions), simple_str_split_uneven);
}

TEST(TestSplitByInt, SimpleStringEvenOperator) {
	EXPECT_EQ(simple_str_even / divisions, simple_str_split_even);
}

TEST(TestSplitByInt, SimpleStringUnevenOperator) {
	EXPECT_EQ(simple_str_uneven / divisions, simple_str_split_uneven);
}

TEST(TestSplitByInt, ComplexStringEven) {
	EXPECT_EQ(stomfoolery::split(complex_str_even, divisions), complex_str_split_even);
}

TEST(TestSplitByInt, ComplexStringUneven) {
	EXPECT_EQ(stomfoolery::split(complex_str_uneven, divisions), complex_str_split_uneven);
}

TEST(TestSplitByInt, ComplexStringEvenOperator) {
	EXPECT_EQ(complex_str_even / divisions, complex_str_split_even);
}

TEST(TestSplitByInt, ComplexStringUnevenOperator) {
	EXPECT_EQ(complex_str_uneven / divisions, complex_str_split_uneven);
}

TEST(TestSplitByInt, SimpleWstringEven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_even, divisions), simple_wstr_split_even);
}

TEST(TestSplitByInt, SimpleWstringUneven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_uneven, divisions), simple_wstr_split_uneven);
}

TEST(TestSplitByInt, SimpleWstringEvenOperator) {
	EXPECT_EQ(simple_wstr_even / divisions, simple_wstr_split_even);
}

TEST(TestSplitByInt, SimpleWstringUnevenOperator) {
	EXPECT_EQ(simple_wstr_uneven / divisions, simple_wstr_split_uneven);
}

TEST(TestSplitByInt, ComplexWstringEven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_even, divisions), complex_wstr_split_even);
}

TEST(TestSplitByInt, ComplexWstringUneven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_uneven, divisions), complex_wstr_split_uneven);
}

TEST(TestSplitByInt, ComplexWstringEvenOperator) {
	EXPECT_EQ(complex_wstr_even / divisions, complex_wstr_split_even);
}

TEST(TestSplitByInt, ComplexWstringUnevenOperator) {
	EXPECT_EQ(complex_wstr_uneven / divisions, complex_wstr_split_uneven);
}

TEST(TestSplitByInt, SimpleStringViewEven) {
	EXPECT_EQ(stomfoolery::split(simple_str_view_even, divisions), simple_str_split_even);
}

TEST(TestSplitByInt, SimpleStringViewUneven) {
	EXPECT_EQ(stomfoolery::split(simple_str_view_uneven, divisions), simple_str_split_uneven);
}

TEST(TestSplitByInt, SimpleStringViewEvenOperator) {
	EXPECT_EQ(simple_str_view_even / divisions, simple_str_split_even);
}

TEST(TestSplitByInt, SimpleStringViewUnevenOperator) {
	EXPECT_EQ(simple_str_view_uneven / divisions, simple_str_split_uneven);
}

TEST(TestSplitByInt, ComplexStringViewEven) {
	EXPECT_EQ(stomfoolery::split(complex_str_view_even, divisions), complex_str_split_even);
}

TEST(TestSplitByInt, ComplexStringViewUneven) {
	EXPECT_EQ(stomfoolery::split(complex_str_view_uneven, divisions), complex_str_split_uneven);
}

TEST(TestSplitByInt, ComplexStringViewEvenOperator) {
	EXPECT_EQ(complex_str_view_even / divisions, complex_str_split_even);
}

TEST(TestSplitByInt, ComplexStringViewUnevenOperator) {
	EXPECT_EQ(complex_str_view_uneven / divisions, complex_str_split_uneven);
}

TEST(TestSplitByInt, SimpleWstringViewEven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_view_even, divisions), simple_wstr_split_even);
}

TEST(TestSplitByInt, SimpleWstringViewUneven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_view_uneven, divisions), simple_wstr_split_uneven);
}

TEST(TestSplitByInt, SimpleWstringViewEvenOperator) {
	EXPECT_EQ(simple_wstr_view_even / divisions, simple_wstr_split_even);
}

TEST(TestSplitByInt, SimpleWstringViewUnevenOperator) {
	EXPECT_EQ(simple_wstr_view_uneven / divisions, simple_wstr_split_uneven);
}

TEST(TestSplitByInt, ComplexWstringViewEven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_view_even, divisions), complex_wstr_split_even);
}

TEST(TestSplitByInt, ComplexWstringViewUneven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_view_uneven, divisions), complex_wstr_split_uneven);
}

TEST(TestSplitByInt, ComplexWstringViewEvenOperator) {
	EXPECT_EQ(complex_wstr_view_even / divisions, complex_wstr_split_even);
}

TEST(TestSplitByInt, ComplexWstringViewUnevenOperator) {
	EXPECT_EQ(complex_wstr_view_uneven / divisions, complex_wstr_split_uneven);
}

// Edge cases
TEST(TestSplitByInt, ZeroDivisions) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, 0), empty_container);
}

TEST(TestSplitByInt, ZeroDivisionsOperator) {
	EXPECT_EQ(simple_str_even / 0, empty_container);
}

TEST(TestSplitByInt, OneDivision) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, 1), one_element_container);
}

TEST(TestSplitByInt, OneDivisionOperator) {
	EXPECT_EQ(simple_str_even / 1, one_element_container);
}
