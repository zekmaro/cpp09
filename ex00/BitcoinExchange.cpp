/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:02 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 18:33:31 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( char* fileName ) : _inputFile(fileName), _data("data.csv") {
	if (!this->_inputFile.is_open()) {
		// custom file exception
	}
	if (!this->_data.is_open()) {
		// custom file exception
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange( void ) {
	this->_inputFile.close();
	this->_data.close();
}

void	BitcoinExchange::initMap( void ) {
	float rate;
	std::string date;
	std::string rateStr;
	std::string tempStr;

	std::getline(this->_data, tempStr); // skip the header
	while (std::getline(this->_data, tempStr)) {
		std::istringstream ss(tempStr);
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			std::istringstream(rateStr) >> rate;
			this->_mapData[date + " "] = rate;
		}
	}
	// for (std::map<std::string, float>::iterator it = this->_mapData.begin(); it != this->_mapData.end(); it++) {
	// 	std::cout << "Date: " << it->first << ", Exchange Rate: " << it->second << std::endl;
	// }
}

bool	BitcoinExchange::isValidDate( std::string& date ) {
	int year;
	int month;
	int day;
	char dash1;
	char dash2;
	std::istringstream ss(date);

	if (date.length() != 11 || date[date.length() - 1] != ' ') {
		std::cout << "Error: bad input. Invalid date" << std::endl;
		return false;
	}
	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
		std::cout << "Error: bad input. Invalid date" << std::endl;
		return false;
	}
	if (year < 0) {
		std::cout << "Error: bad input. Invalid year" << std::endl;
		return false;
	}
	if (month < 1 || month > 12) {
		std::cout << "Error: bad input. Invalid month" << std::endl;
		return false;
	}
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int maxDays = 31;
	switch (month) {
		case 2:
			maxDays = isLeapYear ? 29 : 28;
			break;
		case 4: case 6: case 9: case 11:
			maxDays = 30;
			break;
		default:
			maxDays = 31;
	}
	if (day < 1 || day > maxDays) {
		std::cout << "Error: bad input. Invalid day for the given month" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidRate( float rate ) {
	if (rate < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	} else if (rate > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::parseInput( void ) {
	float rate;
	std::string date;
	std::string rateStr;
	std::string tempStr;

	std::getline(this->_inputFile, tempStr); // skip the header
	if (tempStr != "date | value") {
		std::cout << "incorrect file format!" << std::endl;
		return ;
	}
	while (std::getline(this->_inputFile, tempStr)) {
		std::istringstream ss(tempStr);
		if (!std::getline(ss, date, '|')
		|| !std::getline(ss, rateStr)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (this->isValidDate(date) == false) {
			continue ;
		}
		std::istringstream(rateStr) >> rate;
		if (!this->isValidRate(rate)) {
			continue ;
		}
		std::cout << date << "=>" << rateStr << " = " << this->_mapData[date] * rate << std::endl;
	}
}
