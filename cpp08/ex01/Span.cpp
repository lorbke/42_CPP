#include "Span.hpp"
#include <exception>
#include <vector>
#include <algorithm>

Span::Span() : _capacity(0) {}

Span::Span(const unsigned int N) : _capacity(N) {}

Span::~Span() {}

Span::Span(const Span & obj) {
	*this = obj;
}

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_capacity = obj.getCapacity();
		_numbers = obj.getNumbers();
	}
	return *this;
}

void Span::addNumber(const int newest) {
	if (_numbers.size() < _capacity)
		_numbers.push_back(newest);
	else
		throw CapacityException();
}

void Span::addSequence(std::vector<int> sequence) {
	if (_numbers.size() + sequence.size() <= _capacity)
		_numbers.insert(_numbers.end(), sequence.begin(), sequence.end());
	else
		throw CapacityException();
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() <= 1) {
		throw SpanException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int shortest = *(sorted.end() - 1);
	for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); ++it) {
		if (shortest == 0)
			return shortest;
		int current = *it - *(it - 1);
		if (current < shortest)
			shortest = current;
	}

	return shortest;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() <= 1) {
		throw SpanException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	return *(sorted.end() - 1) - *sorted.begin();
}

unsigned int Span::getCapacity() const {
	return _capacity;
}

std::vector<int> Span::getNumbers() const {
	return std::vector<int>(_numbers);
}