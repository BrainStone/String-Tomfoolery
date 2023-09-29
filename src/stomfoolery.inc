#ifndef STOMFOOLERY_STOMFOOLERY_INC
#define STOMFOOLERY_STOMFOOLERY_INC

#include "stomfoolery.hpp"

namespace stomfoolery {

template <typename T, std::contiguous_iterator I>
    requires requires(I i) { std::same_as<std::decay_t<decltype(*i)>, std::decay_t<T>>; }
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

}  // namespace stomfoolery

#endif  // STOMFOOLERY_STOMFOOLERY_INC
