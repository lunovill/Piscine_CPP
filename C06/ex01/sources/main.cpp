#include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main(void) {
	Data org;
	Data *ptr = &org;

	org.value = 42;
	std::cout << ansi(NULL, 0) << " value : " << ptr->value << std::endl;
	std::cout << "adress : " << &ptr << std::endl;
	std::cout << std::endl;
	uintptr_t	slzPtr = serialize(ptr);
	std::cout << "serialize of Data : " << slzPtr << std::endl;
	std::cout << std::endl;
	Data *dslzPtr = deserialize(slzPtr);
	std::cout << "deserialize of serialize of Data : " << dslzPtr << std::endl;
	std::cout << " value : " << dslzPtr->value << std::endl;
	std::cout << "adress : " << &dslzPtr << std::endl;
	return 0;
}