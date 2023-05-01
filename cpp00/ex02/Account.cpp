
#include "Account.hpp" // Account
#include <iostream> // std::cout
#include <ctime> // std::time, std::localtime

// @todo revise code, understand everything better
// @todo especially understand the tests.cpp file

// @note why is this necessary?
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* ___________________________________________________ CONSTRUCTOR/DESTRUCTOR */

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << Account::_accountIndex
	<< ";amount:" << Account::_amount
	<< ";closed"
	<< std::endl;
}

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << Account::_nbAccounts
	<< ";amount:" << initial_deposit
	<< ";created"
	<< std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_accountIndex = Account::_nbAccounts;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

Account::Account(void)
{
	Account::_nbAccounts++;
	Account::_accountIndex = Account::_nbAccounts;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

/* ____________________________________________________________ PUBLIC STATIC */

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

/* ___________________________________________________________________ PUBLIC */

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << Account::_accountIndex
	<< ";p_amount:" << Account::_amount
	<< ";deposit:" << deposit
	<< ";amount:" << Account::_amount + deposit
	<< ";nb_deposits:" << Account::_nbDeposits + 1
	<< std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_nbDeposits++;
	Account::_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << Account::_accountIndex
	<< ";p_amount:" << Account::_amount
	<< ";withdrawal:";
	if (Account::_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout
	<< withdrawal
	<< ";amount:" << Account::_amount - withdrawal
	<< ";nb_withdrawals:" << Account::_nbWithdrawals + 1
	<< std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_nbWithdrawals++;
	Account::_amount -= withdrawal;
	return true;
}

int	Account::checkAmount(void) const
{
	return Account::_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
	<< "index:" << Account::_accountIndex
	<< ";amount:" << Account::_amount
	<< ";deposits:" << Account::_nbDeposits
	<< ";withdrawals:" << Account::_nbWithdrawals
	<< std::endl;
}

/* ___________________________________________________________ STATIC PRIVATE */

void	Account::_displayTimestamp(void)
{
	time_t		time_raw;
	char		timestamp[20];

	std::time(&time_raw);
	tm*			time_info = std::localtime(&time_raw);
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", time_info);
	std::cout << timestamp;
}
