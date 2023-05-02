#include "BitcoinExchange.hpp"

static std::map<std::string, float>	creatData(std::ifstream &dataFile) {
	std::map<std::string, float>	dataMap;
	std::string line;
	getline(dataFile, line);
	while (getline(dataFile, line)) {
		std::string::size_type	sep = line.find(',');
		dataMap[line.substr(0, sep)] = atof(line.substr(sep + 1).c_str());
	}
	return dataMap;
}

static bool	isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool	isValidDate(std::string const &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') { return false; }
	
	for (size_t i = 0; i < date.size(); ++i)
		if (i != 4 && i != 7 && !isdigit(date[i])) { return false; }
	
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) { return false; }
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { return false; }
	
	if (month == 2) {
		if (isLeapYear(year) && day > 29) {
			return false;
		} else if (!isLeapYear(year) && day > 28) {
			return false;
		}
	}
	return true;
}

static int isValidValue(const std::string &str) {
    if (str.empty()) { return 1; }
    size_t i = 0;
	if (str[0] == '-') { i++; }
    bool hasDecimalPoint = false;
    if (str[0] == '.' && str.length() == 1)	{ return 1; }
    for (; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (hasDecimalPoint) { return 1; }
            hasDecimalPoint = true;
        } else if (!isdigit(str[i])) {
            return 1;
        }
    }

	float value = atof(str.c_str());

    if (value >= float(std::numeric_limits<int>::max()) || value <= float(std::numeric_limits<int>::min())) { return 2; }
    if (value < 0) { return 3; }
    return 0;
}

std::map<std::string, float>::iterator	earliestDate(std::map<std::string, float> &data, std::string const &date) {
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	std::map<std::string, float>::reverse_iterator it = data.rbegin();
	int yearData;
	for (; it != data.rend(); ++it) {
		yearData = atoi(it->first.substr(0, 4).c_str());
		if (yearData < year) { return --it.base(); }
		else if (yearData == year) { break; }
	}
	int monthData;
	for (; it != data.rend(); ++it) {
		monthData = atoi(it->first.substr(5, 2).c_str());
		if (yearData < atoi(it->first.substr(0, 4).c_str()) || monthData < month) { return --it.base(); }
		else if (monthData == month) { break; }
	}
	int dayData;
	for (; it != data.rend(); ++it) {
		dayData = atoi(it->first.substr(8, 2).c_str());
		if (yearData < atoi(it->first.substr(0, 4).c_str()) || monthData < atoi(it->first.substr(5, 2).c_str()) || dayData < day) { return --it.base(); }
		else if (dayData == day) { break; }
	}
	return (it == data.rend()) ? data.begin() : --it.base();
}

void	btc(std::ifstream &dataFile, std::ifstream &input) {
	std::map<std::string, float> data = creatData(dataFile);
	std::string line;
	while (getline(input, line)) {
		if (line.empty()) { continue; }
		std::string::size_type	index = line.find(" | ");
		if (index == std::string::npos || !isValidDate(line.substr(0, index)) || isValidValue(line.substr(index + 3)) == 1) {
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error: btc():" + ansi((short[]){DARK, ITALIC}, 2) + " bad input => " << line << std::endl;
		} else if (isValidValue(line.substr(index + 3)) == 2) {	
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error: btc():" + ansi((short[]){DARK, ITALIC}, 2) + " too large a number." << std::endl;
		} else if (isValidValue(line.substr(index + 3)) == 3) {
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Error: btc():" + ansi((short[]){DARK, ITALIC}, 2) + " not a positive number." << std::endl;
		} else {
			std::string	date = line.substr(0, index);
			float		value = atof(line.substr(index + 3).c_str());
			std::map<std::string, float>::iterator	it = earliestDate(data, date);
			std::cout << ansi(NULL, 0) << date << " => " << value << " = " << value * it->second << std::endl;
		}
	}
	return;
}