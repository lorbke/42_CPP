#include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(const Span & obj) { *this = obj; }

Span& Span::operator=(const Span& obj) {
	(void)obj;
	return *this;
}
