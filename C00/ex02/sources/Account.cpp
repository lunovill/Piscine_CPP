#include <iostream>
#include <ctime>
#include <cwchar>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "\r";
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	return;
}

void Account::_displayTimestamp( void )
{
    std::time_t t;
    std::time(&t);
    wchar_t wstr[100];
    
    if(std::wcsftime(wstr, 100, L"\r[%Y%m%d_%H%M%S]", std::localtime(&t))) {
        std::wcout << wstr;
    }
	std::cout << " ";
	// std::cout << "[19920104_091532] ";
}

int  Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int  Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int  Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int  Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";

	if (this->_amount - withdrawal < 0) {
		std::cout << "refused" << std::endl;
		return false;
	} else {
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account( void ) {
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}
