#include "RPN.hpp"

int	RPN(std::string const &operation) {
	std::string			line;
	std::stack<int>		stk;
	std::istringstream	stream(operation);
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