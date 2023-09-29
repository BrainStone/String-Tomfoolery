#ifndef STOMFOOLERY_STOMFOOLERY_HPP
#define STOMFOOLERY_STOMFOOLERY_HPP

#include <string>

namespace stomfoolery {

template <typename T>
std::basic_string<T> repeat(const std::basic_string<T>& str, std::size_t repeats);

}  // namespace stomfoolery

// You can disable the operators if you really want to!
#ifndef STOMFOOLERY_DISABLE_OPERATORS

template <typename T>
inline std::basic_string<T> operator*(const std::basic_string<T>& str, std::size_t repeats) {
	return stomfoolery::repeat<T>(str, repeats);
}

#endif  // STOMFOOLERY_DISABLE_OPERATORS

// This is a header only library, because of templates.
// We still want the definitions in a separate file, but that must be included!
#include "stomfoolery.inc"

#endif  // STOMFOOLERY_STOMFOOLERY_HPP
