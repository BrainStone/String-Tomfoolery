#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <iterator>
#include <string>
#include <string_view>

namespace stomfoolery {

// #### repeat ####
// Actual function
template <typename T, std::contiguous_iterator I>
    requires requires(I i) { std::same_as<std::decay_t<decltype(*i)>, std::decay_t<T>>; }
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

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header only library, because of templates.
// We still want the definitions (of the actual functions!) in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
