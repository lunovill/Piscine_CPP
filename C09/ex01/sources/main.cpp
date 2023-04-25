# include <stack>
# include <iostream>

# include "ansi.hpp"

template<typename T>
T	stoT(std::string const &str) {
    T uflt;
    
    std::istringstream iss(str);
    iss >> uflt;

	return uflt;
}

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) + "Usage:" << ansi((short[]){DARK}, 1) + " " + argv[0] << " <operation>" << std::endl;
		return 1;
	}

	std::string	operation(argv[1]);
	std::size_t	found = operation.find_first_not_of("0123456789 +-*/");
	if (found != std::string::npos) {
		std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid character `" << operation[found] << "'" << std::endl;
		return 1;
	}

	std::string line;
	std::stack<int> stk;
	std::istringstream stream(operation);
	bool				neg = false;
	while (std::getline(stream, line, ' ')) {
		if (line.empty()) { continue; }
		if (line.size() != 1) {
			std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid string \"" << line << "\"" << std::endl;
			return 1;
		}
		int n;
		switch (line[0]) {
			case '+':
				if (stk.size() < 2) { std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid operation " << operation << std::endl;	return 1; }
				n = stk.top();
				stk.pop();
				n += stk.top();
				stk.pop();
				stk.push(n);
				break;
			case '-':
				if (stk.size() < 2) {
					neg = (neg) ? false : true;
				} else {
					n = stk.top();
					stk.pop();
					n = stk.top() - n; 
					stk.pop();
					stk.push(n);
				}
				break;
			case '*':
				if (stk.size() < 2) { std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid operation " << operation << std::endl;	return 1; }
				n = stk.top();
				stk.pop();
				n *= stk.top();
				stk.pop();
				stk.push(n);
				break;
			case '/':
				if (stk.size() < 2) { std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid operation " << operation << std::endl;	return 1; }
				n = stk.top();
				stk.pop();
				if (!n) { std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid operation " << operation << std::endl;		return 1; }
				n = stk.top() / n;
				stk.pop();
				stk.push(n);
				break;
			default:
				std::istringstream iss(line);
				iss >> n;
				if (neg) { n = -n;	neg = false; }
				stk.push(n);
				break;
		}
	}
	if (stk.size() != 1 || neg) { std::cerr << ansi((short[]){UNDERLINE, DARK}, 2) << "Error:" << ansi((short[]){DARK, ITALIC}, 2) << " invalid operation " << operation << std::endl;	return 1; }
	std::cout << stk.top() << std::endl;
	return 0;
}