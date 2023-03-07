#include "ShrubberyCreationForm.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("Shrubbery ", 145, 137), _target(copy._target) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + " nammed " + this->_name + "." << std::endl;
	return;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &) { return *this; }

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->_executeGrade < executor.getGrade()) throw GradeTooLowException();
	if (!this->_isSigned) throw FormNoSigned();

	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (!ofs.is_open()) throw("Failed to open file for writing"); 

	ofs << "                                                         . " << std::endl ;
	ofs << "                                              .         ; " << std::endl ;
	ofs << "                 .              .              ;%     ;; " << std::endl ;
	ofs << "                   ,           ,                :;%  %; " << std::endl ;
	ofs << "                    :         ;                   :;%;'     ., " << std::endl ;
	ofs << "           ,.        %;     %;            ;        %;'    ,; " << std::endl ;
	ofs << "             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl ;
	ofs << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl ;
	ofs << "               ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl ;
	ofs << "                `%;.     ;%;     %;'         `;%%;.%;' " << std::endl ;
	ofs << "                 `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl ;
	ofs << "                    `:%;.  :;bd%;          %;@%;' " << std::endl ;
	ofs << "                      `@%:.  :;%.         ;@@%;' " << std::endl ;
	ofs << "                        `@%.  `;@%.      ;@@%; " << std::endl ;
	ofs << "                          `@%%. `@%%    ;@@%; " << std::endl ;
	ofs << "                            ;@%. :@%%  %@@%; " << std::endl ;
	ofs << "                              %@bd%%%bd%%:; " << std::endl ;
	ofs << "                                #@%%%%%:;; " << std::endl ;
	ofs << "                                %@@%%%::; " << std::endl ;
	ofs << "                                %@@@%(o);  . ' " << std::endl ;
	ofs << "                                %@@@o%;:(.,' " << std::endl ;
	ofs << "                            `.. %@@@o%::; " << std::endl ;
	ofs << "                               `)@@@o%::; " << std::endl ;
	ofs << "                                %@@(o)::; " << std::endl ;
	ofs << "                               .%@@@@%::; " << std::endl ;
	ofs << "                               ;%@@@@%::;." << std::endl ;
	ofs << "                              ;%@@@@%%:;;;. " << std::endl ;
	ofs << "                          ...;%@@@@@%%:;;;;,.. " << std::endl ;

	ofs.close();
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

const std::string	ShrubberyCreationForm::getTarget(void) const { return this->_target; }

/********************************************************************************/
