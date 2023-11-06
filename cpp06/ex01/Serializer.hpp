#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <string>

struct Data {
	std::string data;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr) {
			return reinterpret_cast<uintptr_t>(ptr);
		}
		static Data* deserialize(uintptr_t raw) {
			return reinterpret_cast<Data*>(raw);
		}
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer & obj);
		Serializer& operator=(const Serializer& obj);
};

#endif  // SERIALIZER_HPP_
