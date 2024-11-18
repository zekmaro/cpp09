/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:27 by anarama           #+#    #+#             */
/*   Updated: 2024/11/18 19:59:51 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _comparesentCounter(DEFAULT_COMPARESENT_COUNTER) {counter = 1;}

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
	std::cout << this->_vector.size() << std::endl;
	this->generateJacobsthalSequence(this->_vector.size());
	this->_vectorsArr.push_back(this->_vector);
}


void printVector( std::vector<int>& vector ) {
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorsArr( void ) {
	std::cout << "======" << std::endl;
	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
		for (std::vector<int>::iterator itVector = (*itVectorsArr).begin(); itVector != (*itVectorsArr).end(); itVector++) {
			std::cout << *itVector << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "======" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::binaryInsertion(std::vector<int>& dest, size_t start, size_t end, int value, int *destIndex) {
	if (start == end) {
		dest.insert(dest.begin() + start, value);
		*destIndex = start;
		return ;
	}
	
	this->_comparesentCounter++;
	size_t mid = (start + end) / 2;
	if (dest[mid] > value) {
		binaryInsertion(dest, start, mid, value, destIndex);
	} else if (dest[mid] < value) {
		binaryInsertion(dest, mid + 1, end, value, destIndex);
	}
}

bool vectorIsEmpty( std::vector<int>& vector ) {
	size_t counter = 0;
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector[i] == -1) {
			counter++;
		}
	}
	if (counter == vector.size()) {
		return true;
	}
	return false;
}

void PmergeMe::mergeInsertion() {
	std::vector<int> upper;
	std::vector<int> lower;
	int last = -1;

	if (this->counter > 1 && this->_vectorsArr[0].size() <= 2) {
		this->_comparesentCounter++;
		if (this->_vectorsArr[0].size() == 2 && (this->_vectorsArr[0][0] > this->_vectorsArr[0][1])) {
			for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
				std::swap((*itVectorsArr)[0], (*itVectorsArr)[1]);
			}
		}
		//this->printVectorsArr();
		return;
	}
	
	std::vector<std::vector<int> > newVectorsArr;
	std::vector<bool> swapRecords;

	std::vector<int> firstVector = this->_vectorsArr[0];
	if (firstVector.size() % 2 == 1) {
		last = firstVector.back();
		firstVector.pop_back();
	}
	for (std::vector<int>::iterator it = firstVector.begin(); it != firstVector.end(); it += 2) {
		if (*it > *(it + 1)) {
			swapRecords.push_back(true);
			std::swap(*it, *(it + 1));
		} else {
			swapRecords.push_back(false);
		}
		this->_comparesentCounter++;
		upper.push_back(*(it + 1));
		lower.push_back(*it);
	}
	if (last != -1) {
		lower.push_back(last);
	}
	newVectorsArr.push_back(upper);
	newVectorsArr.push_back(lower);
	upper.clear();
	lower.clear();

	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin() + 1; itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
		last = -1;
		if ((*itVectorsArr).size() % 2 == 1) {
			last = (*itVectorsArr).back();
			(*itVectorsArr).pop_back();
		}
		int swapIndex = 0;
		for (std::vector<int>::iterator itVector = (*itVectorsArr).begin(); itVector != (*itVectorsArr).end(); itVector += 2) {
			if (swapRecords[swapIndex] == true) {
				std::swap(*itVector, *(itVector + 1));
			}
			upper.push_back(*(itVector + 1));
			lower.push_back(*itVector);
			swapIndex++;
		}
		if (last != -1) {
			lower.push_back(last);
		}
		newVectorsArr.push_back(upper);
		newVectorsArr.push_back(lower);
		upper.clear();
		lower.clear();
	}
	this->_vectorsArr = newVectorsArr;
	this->counter++;
	//this->printVectorsArr();
	this->mergeInsertion();
	
	firstVector.clear();
	firstVector = this->_vectorsArr[0];
	std::vector<int> secondVector = this->_vectorsArr[1];
	
	std::vector<std::vector<int> > newInsertedVectorsArr;
	
	std::vector<int> insertionIndexTableSrc;
	std::vector<int> insertionIndexTableDest;
	
	int increment = 0;
	int decrement2 = 0;
	bool decrementFlag = false;
	int tempDestIndex = 0;
	for (size_t i = 0; i < secondVector.size(); i++) {
		if (::vectorIsEmpty(secondVector)) {
			break ;
		}
		size_t indexToInsert = _jacobSequence[i] + increment - 1;
		if (indexToInsert >= secondVector.size() || decrementFlag == true) {
			indexToInsert = secondVector.size() - 1;
			while (secondVector[indexToInsert] == -1) {
				indexToInsert--;
			}
			decrementFlag = true;
		}
		if (indexToInsert == 0) {
			firstVector.insert(firstVector.begin() + increment, secondVector[indexToInsert]);
			secondVector[indexToInsert] = -1;
			secondVector.insert(secondVector.begin() + increment, -1);
			tempDestIndex = 0;
		} else {
			this->binaryInsertion(firstVector, 0, indexToInsert, secondVector[indexToInsert], &tempDestIndex);
			secondVector[indexToInsert] = -1;
			secondVector.insert(secondVector.begin() + increment, -1);
		}
		insertionIndexTableSrc.push_back(indexToInsert - increment - decrement2);
		insertionIndexTableDest.push_back(tempDestIndex);
		if (decrementFlag == true) {
			decrement2++;
		} else {
			increment++;
		}
	}
	
	newInsertedVectorsArr.push_back(firstVector);
	if (this->_vectorsArr.size() == 1) {
		return ;
	}
	this->_vectorsArr.erase(this->_vectorsArr.begin());
	this->_vectorsArr.erase(this->_vectorsArr.begin());
	this->printVectorsArr();

	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr += 2) {
		firstVector = *itVectorsArr;
		secondVector = *(itVectorsArr + 1);
		for (size_t i = 0; i < insertionIndexTableSrc.size(); i++) {
			int indexToInsert = insertionIndexTableSrc[i];
			firstVector.insert(firstVector.begin() + insertionIndexTableDest[i], secondVector[indexToInsert]);
			secondVector[insertionIndexTableSrc[i]] = -1;
		}
		if (secondVector.size() > insertionIndexTableSrc.size()) {
			firstVector.push_back(secondVector.back());
		}
		newInsertedVectorsArr.push_back(firstVector);
		firstVector.clear();
		secondVector.clear();
	}
	this->_vectorsArr = newInsertedVectorsArr;
	this->printVectorsArr();
}

void PmergeMe::generateJacobsthalSequence( size_t size ) {
	int j0 = 1;
	int j1 = 1;
	int max = 1;
	int jn;

	this->_jacobSequence.push_back(1);
	for (int i = 0; this->_jacobSequence.size() < size; i++) {
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
