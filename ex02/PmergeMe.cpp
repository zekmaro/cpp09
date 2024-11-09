/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:27 by anarama           #+#    #+#             */
/*   Updated: 2024/11/09 18:50:10 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _comparesentCounter(DEFAULT_COMPARESENT_COUNTER) {}

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
}

void PmergeMe::binaryInsertion(unsigned int start, unsigned int end, int value) {
	std::cout << "start: " << start << " end: " << end << " value: " << value << std::endl;
    if (end - start == 1 || start - end == 1 || start == end) {
		this->_comparesentCounter++;
        this->_vector.insert(this->_vector.begin() + start, value);
        return;
    }

    int medium = (start + end) / 2;

    if (value > this->_vector[medium]) {
        this->binaryInsertion(medium + 1, end, value);
		this->_comparesentCounter++;
    } else {
        this->binaryInsertion(start, medium, value);
		this->_comparesentCounter++;
    }
}

void PmergeMe::mergeInsertion() {
	std::vector<int> tempLittleVector;
	std::vector<int> tempBigVector;
	int last;

	std::cout << "===BIG===" << std::endl;
	this->printVector();
	if (this->_vector.size() % 2 == 1) {
		last = this->_vector.back();
		std::cout << "Last: " << last << std::endl;
		this->_vector.pop_back();
	}
	std::cout << "===BIG===" << std::endl;
	if (this->_vector.size() <= 2) {
		if (this->_vector[1] < this->_vector[0]) {
			std::swap(this->_vector[1] , this->_vector[0]);
		}
		return ;
	}
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it += 2) {
		if (it + 1 != this->_vector.end()) {
			if (*(it + 1) < *it) {
				std::swap(*it, *(it + 1));
			}
			this->_comparesentCounter++;
		}
		tempLittleVector.push_back(*it);
		tempBigVector.push_back(*(it + 1));
	}
	this->_vector = tempBigVector;
	std::cout << "===LITTLE===" << std::endl;
	for (std::vector<int>::iterator it = tempLittleVector.begin(); it != tempLittleVector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "===LITTLE===" << std::endl;
	this->mergeInsertion();
	std::cout << "===LITTLE AFTER===" << std::endl;
	for (std::vector<int>::iterator it = tempLittleVector.begin(); it != tempLittleVector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "===LITTLE AFTER===" << std::endl;
	for (unsigned int i = 0; i < this->_jacobSequence.size(); i++) {
		if (i == 0) {
			this->_vector.insert(this->_vector.begin(), tempLittleVector[i]);
		}
		
	}
}

void PmergeMe::printVector( void ) {
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::generateJacobsthalSequence( int size ) {
	int j0 = 1;
	int j1 = 1;
	int jn;
	int max = 1;

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
	// for (std::vector<int>::iterator it = this->_jacobSequence.begin(); it != this->_jacobSequence.end(); it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
}
