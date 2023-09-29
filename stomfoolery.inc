#ifndef STOMFOOLERY_STOMFOOLERY_INC
#define STOMFOOLERY_STOMFOOLERY_INC

#include "stomfoolery.hpp"

namespace stomfoolery {

template <typename T, std::bidirectional_iterator I>
std::basic_string<T> repeat(I begin, I end, std::size_t repeats)
    requires(I i)
{
	{ *i } -> std::same_as<T>
}
{
	const std::size_t size = end - begin;
	std::basic_string<T> result;

	if (repeats == 0 || size == 0) {
		return result;
	}

	result.reserve(size * repeats);

	for (std::size_t i = 0; i < repeats; ++i) {
		result.append(begin, end);
	}

	return result;
}

}  // namespace stomfoolery

#endif  // STOMFOOLERY_STOMFOOLERY_INC
