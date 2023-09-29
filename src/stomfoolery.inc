#ifndef STOMFOOLERY_STOMFOOLERY_INC
#define STOMFOOLERY_STOMFOOLERY_INC

#include "stomfoolery.hpp"

namespace stomfoolery {

template <typename T, char_iterator<T> I>
std::basic_string<T> repeat(I begin, I end, std::size_t repeats) {
	const std::size_t size = end - begin;
	std::basic_string<T> result;

	if (repeats == 0 || size == 0) {
		return result;
	}
	// No special case for repeats == 1, as we need to copy the string anyway.

	result.reserve(size * repeats);

	for (std::size_t i = 0; i < repeats; ++i) {
		result.append(begin, end);
	}

	return result;
}

template <typename T, typename C, char_iterator<T> I>
C split(I begin, I end, std::size_t divisions) {
	const std::size_t size = end - begin;
	C result;

	if (divisions == 0) {
		return result;
	}
	// No special case for divisions == 1, as we need to copy the string anyway.

	result.reserve(divisions);
	std::size_t length = size / divisions + 1;  // Extend length by 1 in case of uneven division
	std::size_t mod = size % divisions;  // Count how many iterations we need to do before decreasing length again
	I temp_begin = begin, temp_end;

	for (size_t i = 0; i < divisions; ++i) {
		// If we hit the iteration count, reduce the length again.
		if (mod == i) --length;

		temp_end = temp_begin + length;
		result.emplace_back(temp_begin, temp_end);
		temp_begin = temp_end;
	}

	return result;
}

}  // namespace stomfoolery

#endif  // STOMFOOLERY_STOMFOOLERY_INC
