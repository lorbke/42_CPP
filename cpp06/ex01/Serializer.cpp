#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer & obj) { *this = obj; }

Serializer& Serializer::operator=(const Serializer& obj) {
	(void)obj;
	return *this;
}
