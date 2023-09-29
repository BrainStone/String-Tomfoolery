#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <iterator>
#include <string>
#include <string_view>
#include <vector>

namespace stomfoolery {

// Concept that defines an iterator that allows subtracting of iterators and ensures it returns the char type we're
// using. The iterators of std::basic_string and std::basic_string_view fulfil that for sure.
template <typename I, typename T>
concept char_iterator =
    std::contiguous_iterator<I> && requires(I i) { std::same_as<std::decay_t<decltype(*i)>, std::decay_t<T>>; };

// #### repeat ####
// Actual function
template <typename T, char_iterator<T> I>
std::basic_string<T> repeat(I begin, I end, std::size_t repeats);

// Helpers
template <typename T>
inline std::basic_string<T> repeat(const std::basic_string<T>& str, std::size_t repeats) {
	return repeat<T>(str.begin(), str.end(), repeats);
}
template <typename T>
inline std::basic_string<T> repeat(std::basic_string_view<T> str, std::size_t repeats) {
	return repeat<T>(str.begin(), str.end(), repeats);
}

// #### split ####
// Actual function
template <typename T, typename C = std::vector<std::basic_string<T>>, char_iterator<T> I>
C split(I begin, I end, std::size_t divisions);

// Helpers
template <typename T, typename C = std::vector<std::basic_string<T>>>
inline C split(const std::basic_string<T>& str, std::size_t repeats) {
	return split<T, C>(str.begin(), str.end(), repeats);
}
template <typename T, typename C = std::vector<std::basic_string<T>>>
inline C split(const std::basic_string_view<T>& str, std::size_t repeats) {
	return split<T, C>(str.begin(), str.end(), repeats);
}

}  // namespace stomfoolery

// You can disable the operators if you really want to!
#ifndef STOMFOOLERY_DISABLE_OPERATORS

// #### repeat ####
template <typename T>
inline std::basic_string<T> operator*(const std::basic_string<T>& str, std::size_t repeats) {
	return stomfoolery::repeat<T>(str, repeats);
}
template <typename T>
inline std::basic_string<T> operator*(std::basic_string_view<T> str, std::size_t repeats) {
	return stomfoolery::repeat<T>(str, repeats);
}

// #### split ####
template <typename T>
inline std::vector<std::basic_string<T>> operator/(const std::basic_string<T>& str, std::size_t repeats) {
	return stomfoolery::split<T>(str, repeats);
}
template <typename T>
inline std::vector<std::basic_string<T>> operator/(std::basic_string_view<T> str, std::size_t repeats) {
	return stomfoolery::split<T>(str, repeats);
}

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header only library, because of templates.
// We still want the definitions (of the actual functions!) in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
