#include <iostream>

template<typename T>
T	stoT(std::string const &str) {
    T t;
    
    std::istringstream iss(str);
    iss >> t;

	return t;
}
