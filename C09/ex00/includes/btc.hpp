#pragma once

# include <cstdlib>
# include <fstream>
# include <map>
# include <limits>

# include "ansi.hpp"
# include "utils.hpp"

# define DATA_PATH "./utils/data.csv"

void	btc(std::ifstream &dataFile, std::ifstream &input);