#include "PmergeVector.hpp"

// @todo implement correct canonical form
PmergeVector::PmergeVector() {}

PmergeVector::~PmergeVector() {}

PmergeVector::PmergeVector(const PmergeVector & obj) { *this = obj; }

PmergeVector& PmergeVector::operator=(const PmergeVector& obj) {
	(void)obj;
	return *this;
}
