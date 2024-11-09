/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:27 by anarama           #+#    #+#             */
/*   Updated: 2024/11/09 12:54:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe& other ) {
	(void) other;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe( void ) {}

const char* PmergeMe::IncorrectInputException::what() const throw() {
	return "Error!\nIncorrect input!";
}

const char* PmergeMe::IsIntegerOverflowException::what() const throw() {
	return "Error!\nInterger overflow detected!";
}

const char* PmergeMe::EmptyInputException::what() const throw() {
	return "Error!\nEmpty input!";
}

bool PmergeMe::IsIntegerOverflow(std::string& number) {
    if (number[0] == '-') {
        if (number.size() > 11) return true;
        if (number.size() == 11 && number > "-2147483648") return true;
    } else {
        if (number.size() > 10) return true;
        if (number.size() == 10 && number > "2147483647") return true;
    }
    return false;
}

void PmergeMe::convertStringToVector( std::vector<std::string>& args ) {
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++) {
        if (this->IsIntegerOverflow(*it)) {
            throw IsIntegerOverflowException();
        }
        char* endPtr;
		if ((*it).empty()) {
			throw EmptyInputException();
		}
        double value = std::strtod((*it).c_str(), &endPtr);
        if (*endPtr != '\0') {
            throw IncorrectInputException();
        }
        int num = static_cast<int>(value);
        this->_vector.push_back(num);
    }
}

void PmergeMe::mergeInsertion( void ) {
	
}

void PmergeMe::printVector( void ) {
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
