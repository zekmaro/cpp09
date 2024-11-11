/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:27 by anarama           #+#    #+#             */
/*   Updated: 2024/11/11 19:06:07 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _comparesentCounter(DEFAULT_COMPARESENT_COUNTER) {counter = 0;}

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

int PmergeMe::getComparesentCounter( void ) const {
	return this->_comparesentCounter;
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
	this->generateJacobsthalSequence(this->_vector.size());
	this->initPairs(this->_vector);
}

// void PmergeMe::binaryInsertion(unsigned int start, unsigned int end, int value) {

// }

void printPairs(const std::vector<std::pair<int, int> >& pairedValues) {
    // First, print all upper values
    for (std::vector<std::pair<int, int> >::const_iterator it = pairedValues.begin(); it != pairedValues.end(); ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    // Then, print all corresponding lower values
    for (std::vector<std::pair<int, int> >::const_iterator it = pairedValues.begin(); it != pairedValues.end(); ++it) {
        std::cout << it->first << " ";
    }

    std::cout << std::endl;

}

void printVector( std::vector<int>& vector ) {
	std::cout << "======" << std::endl;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "======" << std::endl;
}

void perfect_algorithm( std::vector<int>& upper ) {
	
}

void PmergeMe::mergeInsertion() {

}


void PmergeMe::generateJacobsthalSequence( int size ) {
	int j0 = 1;
	int j1 = 1;
	int max = 1;
	int jn;

	this->_jacobSequence.push_back(1);
	for (int i = 0; i < size; i++) {
		jn = 2 * j0 + j1;
		this->_jacobSequence.push_back(jn);
		for (int k = jn - 1; k > max; k--) {
			this->_jacobSequence.push_back(k);
		}
		j0 = j1;
		max = jn;
		j1 = jn;
	}
}

void PmergeMe::initPairs( std::vector<int>& vector ) {
	// int last = -1;

	// this->printVector();

	// if (this->_vector.size() % 2 == 1) {
	// 	last = this->_vector.back();
	// 	this->_vector.pop_back();
	// }
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it += 2) {
		if (it + 1 != this->_vector.end()) {
			if (*(it + 1) < *it) {
				std::swap(*it, *(it + 1));
			}
			this->_pairedValues.push_back(std::make_pair(*it, *(it + 1)));
			this->_comparesentCounter++;
		}
	}
}
