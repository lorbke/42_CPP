#include <exception>
#include <iostream>

// @note function definitions are in the header file, because otherwise linker issues can appear
template <class T>
class Array {
	public:
		Array() {
			_length = 0;
			_data = new T[_length];
			_setDefault();
		};
		Array(unsigned int n) {
			_length = n;
			_data = new T[_length];
			_setDefault();
		};
		Array(const Array& original) {
			_length = original.size();
			_data = new T[_length];
			for (unsigned int i = 0; i < _length; i++)
				_data[i] = original[i];
		};
		Array& operator=(const Array& rhs) {
			Array lhs = new Array(rhs);
			return lhs;
		};
		T& operator[](int index) const {
			try {
				return _data[index];
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return _data[index];
		};
		~Array() {};
		unsigned int size() const {
			return _length;
		};
	private:
		T*           _data;
		unsigned int _length;
		void         _setDefault() {
			for (unsigned int i = 0; i < _length; i++)
				_data[i] = T();
		}
};