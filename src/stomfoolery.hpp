#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <iterator>
#include <string>
#include <string_view>
#include <vector>

namespace stomfoolery {

/**
 * @brief The return_type_iterator concept checks if an iterator returns a specific type.
 * @tparam I Iterator type
 * @tparam T Expected return type
 */
template <typename I, typename T>
concept return_type_iterator =
    std::contiguous_iterator<I> && requires(I i) { std::same_as<std::decay_t<decltype(*i)>, std::decay_t<T>>; };

/**
 * @brief The contains_return_type_iterator concept checks if a container contains an iterable type whose iterator
 * returns a specific type.
 * @tparam C Container type
 * @tparam T Expected return type
 */
template <typename C, typename T>
concept contains_return_type_iterator = requires(C c) {
	std::same_as<std::decay_t<decltype(c.begin())>, std::decay_t<decltype(c.end())>>;
	{ c.begin() } -> return_type_iterator<T>;
};

/**
 * @brief The nested_return_type_iterator concept checks if the type returned by the iterator satisfies
 * contains_return_type_iterator.
 * @tparam C Container type
 * @tparam T Expected return type
 */
template <typename C, typename T>
concept nested_return_type_iterator = std::forward_iterator<C> && requires(C c) {
	{ *c } -> contains_return_type_iterator<T>;
};

// #### repeat ####
// Actual function

/**
 * @brief Repeats an iterator based string a specified number of times.
 * @tparam T Char type of the string
 * @tparam I Iterator type pointing to the start of the string
 * @param begin Iterator pointing to the start of the string
 * @param end Iterator pointing to the end of the string
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <typename T, return_type_iterator<T> I>
std::basic_string<T> repeat(I begin, I end, std::size_t repeats);

// Helpers

/**
 * @brief Repeats a string a specified number of times.
 * @tparam T Char type of the string
 * @param str The string to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <typename T>
inline std::basic_string<T> repeat(const std::basic_string<T>& str, std::size_t repeats) {
	return repeat<T>(str.begin(), str.end(), repeats);
}

/**
 * @brief Repeats a string a specified number of times using a string_view input.
 * @tparam T Char type of the string
 * @param str The string_view to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <typename T>
inline std::basic_string<T> repeat(std::basic_string_view<T> str, std::size_t repeats) {
	return repeat<T>(str.begin(), str.end(), repeats);
}

// #### split by int ####
// Actual function

/**
 * @brief Splits an iterator based string into multiple substrings based on a specified number of divisions.
 * @tparam T Char type of the string
 * @tparam C Container type to store the resulting substrings
 * @tparam I Iterator type pointing to the start of the string
 * @param begin Iterator pointing to the start of the string
 * @param end Iterator pointing to the end of the string
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <typename T, typename C = std::vector<std::basic_string<T>>, return_type_iterator<T> I>
C split(I begin, I end, std::size_t divisions);

// Helpers

/**
 * @brief Splits a string into multiple substrings based on a specified number of divisions using simpler string input.
 * @tparam T Char type of the string
 * @tparam C Container type to store the resulting substrings
 * @param str The string to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <typename T, typename C = std::vector<std::basic_string<T>>>
inline C split(const std::basic_string<T>& str, std::size_t divisions) {
	return split<T, C>(str.begin(), str.end(), divisions);
}

/**
 * @brief Splits a string into multiple substrings based on a specified number of divisions using a string_view input.
 * @tparam T Char type of the string
 * @tparam C Container type to store the resulting substrings
 * @param str The string_view to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <typename T, typename C = std::vector<std::basic_string<T>>>
inline C split(const std::basic_string_view<T>& str, std::size_t divisions) {
	return split<T, C>(str.begin(), str.end(), divisions);
}

// #### join ####
// Actual function

/**
 * @brief Joins a range of iterator based containers into a single string using a specified iterator based delimiter.
 * @tparam T Char type of the string
 * @tparam CI Iterator type for the container of containers
 * @tparam I Iterator type pointing to the start of the delimiter
 * @param container_begin Iterator pointing to the start of the container
 * @param container_end Iterator pointing to the end of the container
 * @param glue_begin Iterator pointing to the start of the delimiter
 * @param glue_end Iterator pointing to the end of the delimiter
 * @return The joined string
 */
template <typename T, nested_return_type_iterator<T> CI, return_type_iterator<T> I>
std::basic_string<T> join(CI container_begin, CI container_end, I glue_begin, I glue_end);

// Helpers

/**
 * @brief Joins a range of containers into a single string using a specified iterator based delimiter.
 * @tparam T Char type of the string
 * @tparam C Container type to join
 * @tparam I Iterator type pointing to the start of the delimiter
 * @param container The container of strings to join
 * @param glue_begin Iterator pointing to the start of the delimiter
 * @param glue_end Iterator pointing to the end of the delimiter
 * @return The joined string
 */
template <typename T, contains_return_type_iterator<T> C, return_type_iterator<T> I>
inline std::basic_string<T> join(const C& container, I glue_begin, I glue_end) {
	return join<T>(container.begin(), container.end(), glue_begin, glue_end);
}

/**
 * @brief Joins a range of containers into a single string using a specified delimiter.
 * @tparam T Char type of the string
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string to use as a delimiter
 * @return The joined string
 */
template <typename T, contains_return_type_iterator<T> C>
inline std::basic_string<T> join(const C& container, const std::basic_string<T>& glue) {
	return join<T>(container, glue.begin(), glue.end());
}

/**
 * @brief Joins a range of containers into a single string using a specified delimiter and a string_view input.
 * @tparam T Char type of the string
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string_view to use as a delimiter
 * @return The joined string
 */
template <typename T, contains_return_type_iterator<T> C>
inline std::basic_string<T> join(const C& container, std::basic_string_view<T> glue) {
	return join<T>(container, glue.begin(), glue.end());
}

}  // namespace stomfoolery

// You can disable the operators if you really want to!
#ifndef STOMFOOLERY_DISABLE_OPERATORS

// #### repeat ####
/**
 * @brief Repeats a string a specified number of times using the "*" operator.
 * @tparam T Char type of the string
 * @param str The string to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <typename T>
inline std::basic_string<T> operator*(const std::basic_string<T>& str, std::size_t repeats) {
	return stomfoolery::repeat<T>(str, repeats);
}

/**
 * @brief Repeats a string a specified number of times using the "*" operator with a string_view input.
 * @tparam T Char type of the string
 * @param str The string_view to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <typename T>
inline std::basic_string<T> operator*(std::basic_string_view<T> str, std::size_t repeats) {
	return stomfoolery::repeat<T>(str, repeats);
}

// #### split by int ####
/**
 * @brief Splits a string into multiple substrings based on a specified number of divisions using the "/" operator.
 * @tparam T Char type of the string
 * @param str The string to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <typename T>
inline std::vector<std::basic_string<T>> operator/(const std::basic_string<T>& str, std::size_t divisions) {
	return stomfoolery::split<T>(str, divisions);
}

/**
 * @brief Splits a string into multiple substrings based on a specified number of divisions using the "/" operator with
 * a string_view input.
 * @tparam T Char type of the string
 * @param str The string_view to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <typename T>
inline std::vector<std::basic_string<T>> operator/(std::basic_string_view<T> str, std::size_t divisions) {
	return stomfoolery::split<T>(str, divisions);
}

// #### join ####
/**
 * @brief Joins a range of containers into a single string using a specified delimiter and the "*" operator.
 * @tparam T Char type of the string
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string to use as a delimiter
 * @return The joined string
 */
template <typename T, stomfoolery::contains_return_type_iterator<T> C>
inline std::basic_string<T> operator*(const C& container, const std::basic_string<T>& glue) {
	return stomfoolery::join<T>(container, glue);
}

/**
 * @brief Joins a range of containers into a single string using a specified delimiter and the "*" operator with a
 * string_view input.
 * @tparam T Char type of the string
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string_view to use as a delimiter
 * @return The joined string
 */
template <typename T, stomfoolery::contains_return_type_iterator<T> C>
inline std::basic_string<T> operator*(const C& container, std::basic_string_view<T> glue) {
	return stomfoolery::join<T>(container, glue);
}

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header-only library, because of templates.
// We still want the definitions (of the actual functions!) in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
