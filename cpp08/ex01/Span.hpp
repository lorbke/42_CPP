#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>

class Span {
	public:
		Span();
		Span(const unsigned int N);
		~Span();
		Span(const Span & obj);
		Span& operator=(const Span& obj);
		void addNumber(const int newest);
		void addSequence(std::vector<int> sequence);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int getCapacity() const;
		std::vector<int> getNumbers() const;
	private:
		unsigned int     _capacity;
		std::vector<int> _numbers;
};

class CapacityException : public std::exception {
	public:
		const char *what() const throw() {
			return "Span::CapacityException: capacity exceeded";
		}
};

class SpanException : public std::exception {
	public:
		const char *what() const throw() {
			return "Span::SpanException: capacity has to be greater than 1";
		}
};

#endif  // SPAN_HPP_
