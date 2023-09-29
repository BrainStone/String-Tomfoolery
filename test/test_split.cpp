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
TEST(TestSplit, SimpleStringEven) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, divisions), simple_str_split_even);
}

TEST(TestSplit, SimpleStringUneven) {
	EXPECT_EQ(stomfoolery::split(simple_str_uneven, divisions), simple_str_split_uneven);
}

TEST(TestSplit, SimpleStringEvenOperator) {
	EXPECT_EQ(simple_str_even / divisions, simple_str_split_even);
}

TEST(TestSplit, SimpleStringUnevenOperator) {
	EXPECT_EQ(simple_str_uneven / divisions, simple_str_split_uneven);
}

TEST(TestSplit, ComplexStringEven) {
	EXPECT_EQ(stomfoolery::split(complex_str_even, divisions), complex_str_split_even);
}

TEST(TestSplit, ComplexStringUneven) {
	EXPECT_EQ(stomfoolery::split(complex_str_uneven, divisions), complex_str_split_uneven);
}

TEST(TestSplit, ComplexStringEvenOperator) {
	EXPECT_EQ(complex_str_even / divisions, complex_str_split_even);
}

TEST(TestSplit, ComplexStringUnevenOperator) {
	EXPECT_EQ(complex_str_uneven / divisions, complex_str_split_uneven);
}

TEST(TestSplit, SimpleWstringEven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_even, divisions), simple_wstr_split_even);
}

TEST(TestSplit, SimpleWstringUneven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_uneven, divisions), simple_wstr_split_uneven);
}

TEST(TestSplit, SimpleWstringEvenOperator) {
	EXPECT_EQ(simple_wstr_even / divisions, simple_wstr_split_even);
}

TEST(TestSplit, SimpleWstringUnevenOperator) {
	EXPECT_EQ(simple_wstr_uneven / divisions, simple_wstr_split_uneven);
}

TEST(TestSplit, ComplexWstringEven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_even, divisions), complex_wstr_split_even);
}

TEST(TestSplit, ComplexWstringUneven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_uneven, divisions), complex_wstr_split_uneven);
}

TEST(TestSplit, ComplexWstringEvenOperator) {
	EXPECT_EQ(complex_wstr_even / divisions, complex_wstr_split_even);
}

TEST(TestSplit, ComplexWstringUnevenOperator) {
	EXPECT_EQ(complex_wstr_uneven / divisions, complex_wstr_split_uneven);
}

TEST(TestSplit, SimpleStringViewEven) {
	EXPECT_EQ(stomfoolery::split(simple_str_view_even, divisions), simple_str_split_even);
}

TEST(TestSplit, SimpleStringViewUneven) {
	EXPECT_EQ(stomfoolery::split(simple_str_view_uneven, divisions), simple_str_split_uneven);
}

TEST(TestSplit, SimpleStringViewEvenOperator) {
	EXPECT_EQ(simple_str_view_even / divisions, simple_str_split_even);
}

TEST(TestSplit, SimpleStringViewUnevenOperator) {
	EXPECT_EQ(simple_str_view_uneven / divisions, simple_str_split_uneven);
}

TEST(TestSplit, ComplexStringViewEven) {
	EXPECT_EQ(stomfoolery::split(complex_str_view_even, divisions), complex_str_split_even);
}

TEST(TestSplit, ComplexStringViewUneven) {
	EXPECT_EQ(stomfoolery::split(complex_str_view_uneven, divisions), complex_str_split_uneven);
}

TEST(TestSplit, ComplexStringViewEvenOperator) {
	EXPECT_EQ(complex_str_view_even / divisions, complex_str_split_even);
}

TEST(TestSplit, ComplexStringViewUnevenOperator) {
	EXPECT_EQ(complex_str_view_uneven / divisions, complex_str_split_uneven);
}

TEST(TestSplit, SimpleWstringViewEven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_view_even, divisions), simple_wstr_split_even);
}

TEST(TestSplit, SimpleWstringViewUneven) {
	EXPECT_EQ(stomfoolery::split(simple_wstr_view_uneven, divisions), simple_wstr_split_uneven);
}

TEST(TestSplit, SimpleWstringViewEvenOperator) {
	EXPECT_EQ(simple_wstr_view_even / divisions, simple_wstr_split_even);
}

TEST(TestSplit, SimpleWstringViewUnevenOperator) {
	EXPECT_EQ(simple_wstr_view_uneven / divisions, simple_wstr_split_uneven);
}

TEST(TestSplit, ComplexWstringViewEven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_view_even, divisions), complex_wstr_split_even);
}

TEST(TestSplit, ComplexWstringViewUneven) {
	EXPECT_EQ(stomfoolery::split(complex_wstr_view_uneven, divisions), complex_wstr_split_uneven);
}

TEST(TestSplit, ComplexWstringViewEvenOperator) {
	EXPECT_EQ(complex_wstr_view_even / divisions, complex_wstr_split_even);
}

TEST(TestSplit, ComplexWstringViewUnevenOperator) {
	EXPECT_EQ(complex_wstr_view_uneven / divisions, complex_wstr_split_uneven);
}

// Edge cases
TEST(TestRepeat, ZeroDivisions) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, 0), empty_container);
}

TEST(TestRepeat, ZeroDivisionsOperator) {
	EXPECT_EQ(simple_str_even / 0, empty_container);
}

TEST(TestRepeat, OneDivision) {
	EXPECT_EQ(stomfoolery::split(simple_str_even, 1), one_element_container);
}

TEST(TestRepeat, OneDivisionOperator) {
	EXPECT_EQ(simple_str_even / 1, one_element_container);
}
