#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <iterator>
#include <string>
#include <string_view>
#include <vector>

namespace stomfoolery {

// Concept that defines an iterator that allows subtracting of iterators and ensures it returns the type we're
// expecting. The iterators of std::basic_string and std::basic_string_view fulfil that for sure.
template <typename I, typename T>
concept return_type_iterator =
    std::contiguous_iterator<I> && requires(I i) { std::same_as<std::decay_t<decltype(*i)>, std::decay_t<T>>; };

// Concept that defines an container that contains a data type that can be iterated on and that ultimately returns the
// type we're expecting. For example std::vector<std::string> would fulfill it for the type char.
template <typename C, typename T>
concept contains_return_type_iterator = requires(C c) {
	std::same_as<std::decay_t<decltype(c.begin())>, std::decay_t<decltype(c.end())>>;
	{ c.begin() } -> return_type_iterator<T>;
};

// Concept that defines an iterator that contains a data type that can be iterated on and that ultimately returns the
// type we're expecting. For example std::vector<std::string> would fulfill it for the type char.
template <typename C, typename T>
concept nested_return_type_iterator = std::forward_iterator<C> && requires(C c) {
	{ *c } -> contains_return_type_iterator<T>;
};

// #### repeat ####
// Actual function
template <typename T, return_type_iterator<T> I>
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
template <typename T, typename C = std::vector<std::basic_string<T>>, return_type_iterator<T> I>
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

// #### join ####
// Actual function
template <typename T, nested_return_type_iterator<T> CI, return_type_iterator<T> I>
std::basic_string<T> join(CI container_begin, CI container_end, I glue_begin, I glue_end);

// Helpers
template <typename T, contains_return_type_iterator<T> C, return_type_iterator<T> I>
inline std::basic_string<T> join(const C& container, I glue_begin, I glue_end) {
	return join<T>(container.begin(), container.end(), glue_begin, glue_end);
}
template <typename T, contains_return_type_iterator<T> C>
inline std::basic_string<T> join(const C& container, const std::basic_string<T>& glue) {
	return join<T>(container, glue.begin(), glue.end());
}
template <typename T, contains_return_type_iterator<T> C>
inline std::basic_string<T> join(const C& container, std::basic_string_view<T> glue) {
	return join<T>(container, glue.begin(), glue.end());
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

// #### join ####
template <typename T, stomfoolery::contains_return_type_iterator<T> C>
inline std::basic_string<T> operator*(const C& container, const std::basic_string<T>& glue) {
	return stomfoolery::join<T>(container, glue);
}
template <typename T, stomfoolery::contains_return_type_iterator<T> C>
inline std::basic_string<T> operator*(const C& container, std::basic_string_view<T> glue) {
	return stomfoolery::join<T>(container, glue);
}

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header only library, because of templates.
// We still want the definitions (of the actual functions!) in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
