/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:02 by anarama           #+#    #+#             */
/*   Updated: 2024/10/27 20:04:26 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) {}

BitcoinExchange::BitcoinExchange( std::string& fileName ) : _inputFile(fileName), _data("data.csv") {
	if (!this->_inputFile.is_open()) {
		// custom file exception
	}
	if (!this->_data.is_open()) {
		// custom file exception
	}
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
	
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ) {
	
}

BitcoinExchange::~BitcoinExchange( void ) {
	this->_inputFile.close();
}