#ifndef STOMFOOLERY_STOMFOOLERY_INC
#define STOMFOOLERY_STOMFOOLERY_INC

#include <algorithm>

#include "stomfoolery.hpp"

namespace stomfoolery {

template <typename T, return_type_iterator<T> I>
std::basic_string<T> repeat(I begin, I end, std::size_t repeats) {
	const std::size_t size = end - begin;
	std::basic_string<T> result;

	if ((repeats == 0) || (size == 0)) {
		return result;
	}
	// No special case for repeats == 1, as we need to copy the string anyway.

	result.reserve(size * repeats);

	for (std::size_t i = 0; i < repeats; ++i) {
		result.append(begin, end);
	}

	return result;
}

template <typename T, typename C, return_type_iterator<T> I>
C split(I begin, I end, std::size_t divisions) {
	C result;

	if (divisions == 0) {
		return result;
	}
	// No special case for divisions == 1, as we need to copy the string anyway.

	result.reserve(divisions);

	const std::size_t size = end - begin;
	std::size_t length = size / divisions + 1;  // Extend length by 1 in case of uneven division
	const std::size_t mod = size % divisions;  // Count how many iterations we need to do before decreasing length again
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

template <typename T, nested_return_type_iterator<T> CI, return_type_iterator<T> I>
std::basic_string<T> join(CI container_begin, CI container_end, I glue_begin, I glue_end) {
	const std::size_t container_size = container_end - container_begin;
	std::basic_string<T> result;

	if (container_size == 0) {
		return result;
	}
	// No special case for container_size == 1, as we need to copy the string anyway.

	std::size_t container_sum_size = 0;
	const std::size_t glue_size = glue_end - glue_begin;

	for (CI it = container_begin; it != container_end; ++it) {
		container_sum_size += it->end() - it->begin();
	}

	result.reserve(glue_size * (container_size - 1) + container_sum_size);

	for (CI it = container_begin; it != container_end; ++it) {
		// Skip first iteration or all iterations if glue is empty
		if ((glue_size != 0) && (it != container_begin)) {
			result.append(glue_begin, glue_end);
		}

		result.append(it->begin(), it->end());
	}

	return result;
}

template <typename T, typename C, return_type_iterator<T> I1, return_type_iterator<T> I2>
C split(I1 str_begin, I1 str_end, I2 separator_begin, I2 separator_end) {
	const std::size_t str_size = str_end - str_begin;
	const std::size_t separator_size = separator_end - separator_begin;
	C result;

	if (str_size == 0) {
		return result;
	} else if (separator_size == 0) {
		// The optimization of only allocating the memory once and not needing to do a pointless search is worth the
		// special handling
		result.reserve(str_size);

		// Create a container full of single char strings
		for (I1 it = str_begin; it != str_end; ++it) {
			result.emplace_back(1, *it);
		}

		return result;
	}

	I1 temp_str_begin = str_begin, temp_str_end;

	while (true) {
		// Search substring
		temp_str_end = std::search(temp_str_begin, str_end, separator_begin, separator_end);
		// Copy string
		result.emplace_back(temp_str_begin, temp_str_end);

		// We'd move temp_str_begin past the end of the string next, so we can't do a check like `while (temp_str_end !=
		// str_end)` or `while (temp_str_begin != str_end)`
		if (temp_str_end == str_end) break;

		// Move start of next search past the separator
		temp_str_begin = temp_str_end + separator_size;
	}

	result.shrink_to_fit();
	return result;
}

template <typename T, typename C, return_type_iterator<T> I>
C split(I begin, I end, const std::basic_regex<T>& separator) {
	const std::size_t size = end - begin;
	C result;

	if (size == 0) {
		return result;
	}

	// submatch = -1 means all unmatched parts
	for (std::regex_token_iterator<I> it{begin, end, separator, -1}, regex_end{}; it != regex_end; ++it) {
		result.emplace_back(it->first, it->second);
	}

	result.shrink_to_fit();
	return result;
}

}  // namespace stomfoolery

#endif  // STOMFOOLERY_STOMFOOLERY_INC
