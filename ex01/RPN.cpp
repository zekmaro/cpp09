/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:51:47 by anarama           #+#    #+#             */
/*   Updated: 2024/11/05 14:57:15 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <exception>
#include <iostream>
#include <sstream>

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN( const RPN& other ) {
	(void)other;
}

RPN& RPN::operator=( const RPN& other ) {
	(void)other;
	return *this;
}

RPN::~RPN( void ) {}

const char* RPN::DivisionByZeroException::what() const throw() {
	return "Error! Trying to divide by zero!";
}

bool RPN::validateFormat( const std::string& input ) {
	std::istringstream ss(input);
	std::string token;
	int temp;
	int operand1;
	int operand2;

	while (ss >> token) {
		if (token.length() != 1)
			return false;
		if (std::isdigit(token[0])) {
			std::cout << "Next digit to add: " << token[0] << std::endl;
			this->stack.push(token[0] - '0');
		} else if (token[0] == '*' || token[0] ==  '+' || token[0] ==  '-' || token[0] ==  '/') {
			operand2 = this->stack.top();
			std::cout << "Operand 2: " << operand2;
			this->stack.pop();
			operand1 = this->stack.top();
			std::cout << " Operand 1: " << operand1;
			this->stack.pop();
			std::cout << " Operation: " << token[0] << std::endl;
			if (token[0] == '*') {
				temp = operand1 * operand2;
			} else if (token[0] == '+') {
				temp = operand1 + operand2;
			} else if (token[0] == '-') {
				temp = operand1 - operand2;
			} else if (token[0] == '/') {
				if (operand2 == 0) {
					throw DivisionByZeroException();
				}
				temp = operand1 / operand2;
			}
			this->stack.push(temp);
		} else {
			std::cout << "Incorrect arguments!" << std::endl;
		}
	}
	return true;
}

void RPN::fillStack( const std::string& input ) {
	try {
		if (!validateFormat(input)) {
			std::cout << "Error!" << std::endl;
		} else {
			std::cout << this->stack.top() << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "Exception caught!" << e.what() << std::endl;
	}
}
