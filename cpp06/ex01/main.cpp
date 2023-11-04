#include "Serializer.hpp"
#include <iostream>

void test_one() {
    std::cout << "test one:" << std::endl;

    Data d;
    uintptr_t ptr;

    d.data = "Hello, world!";
    std::cout << "original:     " << d.data << std::endl;
    std::cout << "original ptr address: " << &d << std::endl;
    ptr = Serializer::serialize(&d);
    std::cout << "serialized:   " << ptr << std::endl;
    Data *temp = Serializer::deserialize(ptr);
    std::cout << "deserialized: " << temp->data << std::endl;
    std::cout << "deserialized ptr address: " << temp << std::endl;

}

int main() {
    test_one();
    return 0;
}