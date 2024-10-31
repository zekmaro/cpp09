/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:02 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 12:02:16 by anarama          ###   ########.fr       */
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
