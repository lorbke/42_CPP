/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:31:59 by lorbke            #+#    #+#             */
/*   Updated: 2023/05/03 16:09:24 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp" // Account
#include <iostream> // std::cout
#include <ctime> // std::time, std::localtime

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";amount:"
	<< this->_amount
	<< ";created" << std::endl;	
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";amount:"
	<< this->_amount
	<< ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= this->_amount;

	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";amount:"
	<< this->_amount
	<< ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:"
	<< _nbAccounts
	<< ";total:"
	<< _totalAmount
	<< ";deposits:"
	<< _totalNbDeposits
	<< ";withdrawals:"
	<< _totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{	
	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";p_amount:"
	<< this->_amount
	<< ";deposit:"
	<< deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:"
	<< this->_amount
	<< ";nb_deposits:"
	<< this->_nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";p_amount:"
	<< this->_amount
	<< ";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:"
	<< this->_amount
	<< ";nb_withdrawals:"
	<< this->_nbWithdrawals
	<< std::endl;
	return (true);
}

int	Account::checkAmount(void)	const
{
	return (this->_amount);
}

void	Account::displayStatus(void)	const
{
	Account::_displayTimestamp();
	std::cout << " index:"
	<< this->_accountIndex
	<< ";amount:"
	<< this->_amount
	<< ";deposits:"
	<< this->_nbDeposits
	<< ";withdrawals:"
	<< this->_nbWithdrawals
	<< std::endl;	
}

void	Account::_displayTimestamp(void)
{
	time_t		time_raw;
	char		timestamp[20];

	std::time(&time_raw);
	tm*			time_info = std::localtime(&time_raw);
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", time_info);
	std::cout << timestamp;
}
