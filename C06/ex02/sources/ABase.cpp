#include "ABase.hpp"

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

ABase::~ABase(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	return;
}

/********************************************************************************/
