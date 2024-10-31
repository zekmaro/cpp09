/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:02 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 15:50:48 by anarama          ###   ########.fr       */
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
			this->_mapData[date] = rate;
		}
	}
	// for (std::map<std::string, float>::iterator it = this->_mapData.begin(); it != this->_mapData.end(); it++) {
	// 	std::cout << "Date: " << it->first << ", Exchange Rate: " << it->second << std::endl;
	// }
}

void	BitcoinExchange::isValidDate( std::string& date ) {
	int year;
	int month;
	int day;
	char dash1;
	char dash2;
	std::istringstream ss(date);

	if (date.length() != 11 || date[date.length() - 1] != ' ') {
		std::cout << "Error: bad input. Invalid date" << std::endl;
		return ;
	}
	if (!(ss >> year >> month >> day >> dash1 >> dash2) || dash1 != '-' || dash2 != '-') {
		std::cout << "Error: bad input. Invalid date" << std::endl;
		return ;
	}
	if (year < 0) {
		std::cout << "Error: bad input. Invalid year" << std::endl;
		return ;
	}
	if (month < 1 || month > 12) {
		std::cout << "Error: bad input. Invalid month" << std::endl;
		return ;
	}
	// need more pricise checks
	if (day < 1 || day > 31) {
		std::cout << "Error: bad input. Invalid day" << std::endl;
		return ;
	}
}

void	BitcoinExchange::isValidRate( float rate ) {
	if (rate < 0) {
		std::cout << "Error: not a positive number." << std::endl;
	} else if (rate > 1000) {
		std::cout << "Error: too large a number." << std::endl;
	}
}

void	BitcoinExchange::parseInput( void ) {
	float rate;
	std::string date;
	std::string rateStr;
	std::string tempStr;

	std::getline(this->_inputFile, tempStr); // skip the header
	while (std::getline(this->_inputFile, tempStr)) {
		std::istringstream ss(tempStr);
		if (!std::getline(ss, date, '|')
		|| !std::getline(ss, rateStr)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		this->isValidDate(date);
		std::istringstream(rateStr) >> rate;
		this->isValidRate(rate);
		std::cout << date << "|" << rateStr << std::endl;
	}
}
