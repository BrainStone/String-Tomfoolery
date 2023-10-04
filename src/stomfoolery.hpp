#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <iterator>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace stomfoolery {

// Template helper structs

/**
 * @brief Helper struct to define what this library considers a string.
 * @tparam T The type in question
 *
 * To define your own string type, specialize this struct for your type. For example, if you have a type `MyString`,
 * you would specialize `is_string_like` as follows:
 *
 *     template <>
 *     struct stomfoolery::is_string_like<MyString> : std::true_type {
 *         using char_type = char;
 *     };
 *
 * With this specialization, `MyString` is now considered a string by this library, if it also satisfies the concept
 * `std::ranges::range`.
 */
template <typename T>
struct is_string_like : std::false_type {
	using char_type = void;
};

/**
 * @brief Template specialization of `is_string_like` for `std::basic_string<CharT, Traits, Alloc>`.
 * @tparam CharT Character type
 * @tparam Traits Traits
 * @tparam Alloc Allocator
 */
template <typename CharT, typename Traits, typename Alloc>
struct is_string_like<std::basic_string<CharT, Traits, Alloc>> : std::true_type {
	using char_type = CharT;
};

/**
 * @brief Template specialization of `is_string_like` for `std::basic_string_view<CharT, Traits, Alloc>`.
 * @tparam CharT Character type
 * @tparam Traits Traits
 */
template <typename CharT, typename Traits>
struct is_string_like<std::basic_string_view<CharT, Traits>> : std::true_type {
	using char_type = CharT;
};

/**
 * @brief Helper to access `is_string_like` more easily.
 * @tparam S String type
 */
template <typename S>
inline constexpr bool is_string_like_v = is_string_like<S>::value;

/**
 * @brief Helper to extract the char type more easily. Uses `is_string_like` internally. This is also the reason why
 * `is_string_like` has the type `char_type`.
 * @tparam S String type
 */
template <typename S>
using string_like_char_t = is_string_like<S>::char_type;

/**
 * Helper to check if the char types of all strings are the same.
 * @tparam S String type
 * @tparam Ss String types
 */
template <typename S, typename... Ss>
inline constexpr bool same_char_type = (std::is_same_v<string_like_char_t<S>, string_like_char_t<Ss>> && ...);

// Concepts

/**
 * Concept that ensures we have a proper string type, that we know how to extract a char type from and that is known to
 * be iterable.
 * @tparam S String type
 */
template <typename S>
concept string_like = is_string_like_v<std::decay_t<S>> && std::ranges::range<S>;

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
 * @tparam S String like type
 * @param str The string to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <string_like S>
inline std::basic_string<string_like_char_t<S>> repeat(const S& str, std::size_t repeats) {
	return repeat<string_like_char_t<S>>(std::ranges::begin(str), std::ranges::end(str), repeats);
}

// #### split by int ####
// Actual function

/**
 * @brief Splits an iterator based string into multiple substrings based on a specified number of divisions.
 * @tparam T Char type of the string
 * @tparam C Container type to store the resulting substrings
 * @tparam I Iterator type representing the string
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
 * @tparam S String like type
 * @tparam C Container type to store the resulting substrings
 * @param str The string to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <string_like S, typename C = std::vector<std::basic_string<string_like_char_t<S>>>>
inline C split(const S& str, std::size_t divisions) {
	return split<string_like_char_t<S>, C>(std::ranges::begin(str), std::ranges::end(str), divisions);
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
 * @brief Joins a range of containers into a single string using a specified delimiter.
 * @tparam S String like type
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string to use as a delimiter
 * @return The joined string
 */
template <string_like S, contains_return_type_iterator<string_like_char_t<S>> C>
inline std::basic_string<string_like_char_t<S>> join(const C& container, const S& glue) {
	return join<string_like_char_t<S>>(std::ranges::begin(container), std::ranges::end(container),
	                                   std::ranges::begin(glue), std::ranges::end(glue));
}

// #### split by string ####
// Actual function

/**
 * @brief Splits an iterator based string into multiple substrings based on a specified iterator based string separator.
 * @tparam T Char type of the string
 * @tparam C Container type to store the resulting substrings
 * @tparam I1 Iterator type representing the string
 * @tparam I2 Iterator type representing the separator
 * @param str_begin Iterator pointing to the start of the string
 * @param str_end Iterator pointing to the end of the string
 * @param separator_begin Iterator pointing to the start of the separator
 * @param separator_end Iterator pointing to the end of the separator
 * @return A container of substrings
 */
template <typename T, typename C = std::vector<std::basic_string<T>>, return_type_iterator<T> I1,
          return_type_iterator<T> I2>
C split(I1 str_begin, I1 str_end, I2 separator_begin, I2 separator_end);

// Helpers

/**
 * @brief Splits a string into multiple substrings based on a specified string separator.
 * @tparam S1 String like type
 * @tparam S2 String like type
 * @tparam C Container type to store the resulting substrings
 * @param str The string to split
 * @param separator The separator to split the string by
 * @return A container of substrings
 */
template <string_like S1, string_like S2, typename C = std::vector<std::basic_string<string_like_char_t<S1>>>>
    requires same_char_type<S1, S2>
inline C split(const S1& str, const S2& separator) {
	return split<string_like_char_t<S1>, C>(std::ranges::begin(str), std::ranges::end(str),
	                                        std::ranges::begin(separator), std::ranges::end(separator));
}

}  // namespace stomfoolery

// You can disable the operators if you really want to!
#ifndef STOMFOOLERY_DISABLE_OPERATORS

// #### repeat ####
/**
 * @brief Repeats a string a specified number of times using the `*` operator.
 * @tparam S String like type
 * @param str The string to repeat
 * @param repeats Number of times the string should be repeated
 * @return The repeated string
 */
template <stomfoolery::string_like S>
inline std::basic_string<stomfoolery::string_like_char_t<S>> operator*(const S& str, std::size_t repeats) {
	return stomfoolery::repeat<S>(str, repeats);
}

// #### split by int ####
/**
 * @brief Splits a string into multiple substrings based on a specified number of divisions using the `/` operator.
 * @tparam S String like type
 * @tparam C Container type to store the resulting substrings
 * @param str The string to split
 * @param divisions Number of times the string should be divided
 * @return A container of substrings
 */
template <stomfoolery::string_like S>
inline std::vector<std::basic_string<stomfoolery::string_like_char_t<S>>> operator/(const S& str,
                                                                                    std::size_t divisions) {
	return stomfoolery::split<S>(str, divisions);
}

// #### join ####
/**
 * @brief Joins a range of containers into a single string using a specified delimiter and the `*` operator.
 * @tparam S String like type
 * @tparam C Container type to join
 * @param container The container of strings to join
 * @param glue The string to use as a delimiter
 * @return The joined string
 */
template <stomfoolery::string_like S, stomfoolery::contains_return_type_iterator<stomfoolery::string_like_char_t<S>> C>
inline std::basic_string<stomfoolery::string_like_char_t<S>> operator*(const C& container, const S& glue) {
	return stomfoolery::join<S, C>(container, glue);
}

// #### split by string ####
/**
 * @brief Splits a string into multiple substrings based on a specified string separator using the `/` operator.
 * @tparam S1 String like type
 * @tparam S2 String like type
 * @tparam C Container type to store the resulting substrings
 * @param str The string to split
 * @param separator The separator to split the string by
 * @return A container of substrings
 */
template <stomfoolery::string_like S1, stomfoolery::string_like S2,
          typename C = std::vector<std::basic_string<stomfoolery::string_like_char_t<S1>>>>
    requires stomfoolery::same_char_type<S1, S2>
inline C operator*(const S1& str, const S2& separator) {
	return split<stomfoolery::string_like_char_t<S1>, C>(std::ranges::begin(str), std::ranges::end(str),
	                                                     std::ranges::begin(separator), std::ranges::end(separator));
}

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header-only library, because of templates.
// We still want the definitions (of the actual functions!) in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
