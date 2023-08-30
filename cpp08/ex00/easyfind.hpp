#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <exception>

template <typename T>
typename T::iterator easyfind(T& haystack, int needle) {
	for (typename T::iterator it = haystack.begin(); it != haystack.end(); ++it) {
		if (*it == needle)
			return it;
	}
	return haystack.end();
}

#endif  // EASYFIND_HPP_