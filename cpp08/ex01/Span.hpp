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
	private:
		const unsigned int _capacity;
		std::vector<int>   _numbers;
};

#endif  // SPAN_HPP_
