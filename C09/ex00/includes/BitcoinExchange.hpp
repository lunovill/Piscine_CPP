#pragma once

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <limits>
# include <map>

# include "ansi.hpp"

# define DATA_PATH "./utils/data.csv"

template<typename T>
T	stoT(std::string const &str) {
    T t;
    
    std::istringstream iss(str);
    iss >> t;

	return t;
}

void	btc(std::ifstream &dataFile, std::ifstream &input);