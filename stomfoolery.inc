#ifndef STOMFOOLERY_STOMFOOLERY_INC
#define STOMFOOLERY_STOMFOOLERY_INC

#include "stomfoolery.hpp"

namespace stomfoolery {

template <typename T>
std::basic_string<T> repeat(const std::basic_string<T>& str, std::size_t repeats) {
	std::basic_string<T> result;

	if (repeats == 0 || str.empty()) {
		return result;
	}

	result.reserve(str.size() * repeats);

	for (std::size_t i = 0; i < repeats; ++i) {
		result.append(str);
	}

	return result;
}

}  // namespace stomfoolery

#endif  // STOMFOOLERY_STOMFOOLERY_INC
