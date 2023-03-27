#include "ansi.hpp"
#include "easyfind.hpp"

template<typename T>
static void	display(const std::string &name, const T &container) {
	std::cout << ansi((short[]){BOLD, CYAN}, 2) << name << " = [";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "\033[2D]" << std::endl;
	return;
}

int	main(void) {
	{
	std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"vector\"" << std::endl;
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	display("vector", vec);

	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un 1: ";
	std::vector<int>::iterator iter = easyfind(vec, 1);
	if (iter != vec.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;
	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un 0: ";
	iter = easyfind(vec, 0);
	if (iter != vec.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;
	}
	std::cout << std::endl;
	{
	std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"list\"" << std::endl;
	std::list<int>		lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	display("list", lst);

	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un 2: ";
	std::list<int>::iterator iter = easyfind(lst, 2);
	if (iter != lst.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;
	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un 4: ";
	iter = easyfind(lst, 4);
	if (iter != lst.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;
	}
	std::cout << std::endl;
	{
	std::cout << ansi((short[]){BOLD, YELLOW}, 2) + "=> TEST : \"deque\"" << std::endl;
	std::deque<int>		deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	display("deque", deq);

	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un 3: ";
	std::deque<int>::iterator iter = easyfind(deq, 3);
	if (iter != deq.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;

	*iter = -1;
	display("deque", deq);

	std::cout << ansi((short[]){CYAN}, 1) << "Je cherche un -1: ";
	iter = easyfind(deq, -1);
	if (iter != deq.end()) std::cout << ansi((short[]){ITALIC}, 1) << *iter << std::endl;
	else std::cout << ansi((short[]){ITALIC, DARK}, 2) << "Not found" << std::endl;
	}
}