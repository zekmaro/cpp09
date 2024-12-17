/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:27 by anarama           #+#    #+#             */
/*   Updated: 2024/12/17 12:51:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <deque>
#include <utility>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _comparesentCounterVector(DEFAULT_COMPARESENT_COUNTER), _comparesentCounterDeque(DEFAULT_COMPARESENT_COUNTER) {_counterVector = _counterDeque = 1;}

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

const char* PmergeMe::NegativeIntegerFoundException::what() const throw() {
	return "Error!\nInput has negative integers!";
}

int PmergeMe::getComparesentCounterVector( void ) const {
	return this->_comparesentCounterVector;
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
		if (num < 0) {
			throw NegativeIntegerFoundException();
		}
        this->_vector.push_back(num);
		this->_deque.push_back(num);
    }
	this->generateJacobsthalSequence(this->_vector.size());
	this->_vectorsArr.push_back(this->_vector);
	this->_dequesArr.push_back(this->_deque);
}


void printVector( std::vector<int>& vector ) {
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorsArr( void ) {
	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
		for (std::vector<int>::iterator itVector = (*itVectorsArr).begin(); itVector != (*itVectorsArr).end(); itVector++) {
			std::cout << *itVector << " ";
		}
		std::cout << std::endl;
	}
}

void PmergeMe::printDequesArr( void ) {
	for (std::deque<std::deque<int> >::iterator itDequesArr = this->_dequesArr.begin(); itDequesArr != this->_dequesArr.end(); itDequesArr++) {
		for (std::deque<int>::iterator itDeque = (*itDequesArr).begin(); itDeque != (*itDequesArr).end(); itDeque++) {
			std::cout << *itDeque << " ";
		}
		std::cout << std::endl;
	}
}

void PmergeMe::binaryInsertionVector(std::vector<int>& dest, size_t start, size_t end, int value, int *destIndex) {
	if (start == end) {
		dest.insert(dest.begin() + start, value);
		*destIndex = start;
		return ;
	}
	
	this->_comparesentCounterVector++;
	size_t mid = (start + end) / 2;
	if (dest[mid] > value) {
		binaryInsertionVector(dest, start, mid, value, destIndex);
	} else if (dest[mid] == value)
	{
		dest.insert(dest.begin() + start, value);
		*destIndex = start;
		return ;
	} else {
		binaryInsertionVector(dest, mid + 1, end, value, destIndex);
	}
}

void PmergeMe::binaryInsertionDeque(std::deque<int>& dest, size_t start, size_t end, int value, int *destIndex) {
	if (start == end) {
		dest.insert(dest.begin() + start, value);
		*destIndex = start;
		return ;
	}
	
	this->_comparesentCounterDeque++;
	size_t mid = (start + end) / 2;
	if (dest[mid] > value) {
		binaryInsertionDeque(dest, start, mid, value, destIndex);
	} else if (dest[mid] == value)
	{
		dest.insert(dest.begin() + start, value);
		*destIndex = start;
		return ;
	} else {
		binaryInsertionDeque(dest, mid + 1, end, value, destIndex);
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

bool dequeIsEmpty( std::deque<int>& deque ) {
	size_t counter = 0;
	for (size_t i = 0; i < deque.size(); i++) {
		if (deque[i] == -1) {
			counter++;
		}
	}
	if (counter == deque.size()) {
		return true;
	}
	return false;
}

void PmergeMe::mergeInsertionVector() {
	std::vector<int> upper;
	std::vector<int> lower;
	int last = -1;

	if (this->_vectorsArr[0].size() <= 2) {
		if (this->_vectorsArr[0].size() == 2) {
			this->_comparesentCounterVector++;
		}
		if (this->_vectorsArr[0].size() == 2 && (this->_vectorsArr[0][0] > this->_vectorsArr[0][1])) {
			for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
				std::swap((*itVectorsArr)[0], (*itVectorsArr)[1]);
			}
		}
		// this->printVectorsArr();
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
		this->_comparesentCounterVector++;
		upper.push_back(*(it + 1));
		lower.push_back(*it);
	}
	if (last != -1) {
		// std::cout << "i removed " << last << std::endl;
		lower.push_back(last);
		swapRecords.push_back(false);
	}
	last = -1;
	newVectorsArr.push_back(upper);
	newVectorsArr.push_back(lower);
	upper.clear();
	lower.clear();

	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin() + 1; itVectorsArr != this->_vectorsArr.end(); itVectorsArr++) {
		if ((*itVectorsArr).size() % 2 == 1) {
			last = (*itVectorsArr).back();
			// std::cout << "i removed " << last << std::endl;
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
		last = -1;
		newVectorsArr.push_back(upper);
		newVectorsArr.push_back(lower);
		upper.clear();
		lower.clear();
	}
	this->_vectorsArr = newVectorsArr;
	this->_counterVector++;
	// this->printVectorsArr();
	this->mergeInsertionVector();
	
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
	for (size_t i = 0; i < firstVector.size(); i++) {
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
			this->binaryInsertionVector(firstVector, 0, indexToInsert, secondVector[indexToInsert], &tempDestIndex);
			secondVector[indexToInsert] = -1;
			secondVector.insert(secondVector.begin() + increment, -1);
		}
		insertionIndexTableSrc.push_back(indexToInsert - increment - decrement2);
		insertionIndexTableDest.push_back(tempDestIndex);
		// ::printVector(firstVector);
		// ::printVector(secondVector);
		if (decrementFlag == true) {
			decrement2++;
		} else {
			increment++;
		}
	}
	newInsertedVectorsArr.push_back(firstVector);
	if (this->_vectorsArr.size() == 2) {
		this->_vectorsArr = newInsertedVectorsArr;
		return ;
	}
	this->_vectorsArr.erase(this->_vectorsArr.begin());
	this->_vectorsArr.erase(this->_vectorsArr.begin());
	// this->printVectorsArr();
	// ::printVector(firstVector);

	for (std::vector<std::vector<int> >::iterator itVectorsArr = this->_vectorsArr.begin(); itVectorsArr != this->_vectorsArr.end(); itVectorsArr += 2) {
		firstVector = *itVectorsArr;
		secondVector = *(itVectorsArr + 1);
		if (secondVector.size() > insertionIndexTableSrc.size()) {
			firstVector.push_back(secondVector.back());
		}
		for (size_t i = 0; i < insertionIndexTableSrc.size(); i++) {
			size_t indexToInsert = insertionIndexTableSrc[i];
			if (indexToInsert < secondVector.size()) {
				firstVector.insert(firstVector.begin() + insertionIndexTableDest[i], secondVector[indexToInsert]);
				secondVector[insertionIndexTableSrc[i]] = -1;		
			}
		}
		newInsertedVectorsArr.push_back(firstVector);
		firstVector.clear();
		secondVector.clear();
	}
	this->_vectorsArr = newInsertedVectorsArr;
	// this->printVectorsArr();
}

void PmergeMe::mergeInsertionDeque() {
	std::deque<int> upper;
	std::deque<int> lower;
	int last = -1;

	if (this->_counterDeque > 1 && this->_dequesArr[0].size() <= 2) {
		this->_comparesentCounterDeque++;
		if (this->_dequesArr[0].size() == 2 && (this->_dequesArr[0][0] > this->_dequesArr[0][1])) {
			for (std::deque<std::deque<int> >::iterator itDequesArr = this->_dequesArr.begin(); itDequesArr != this->_dequesArr.end(); itDequesArr++) {
				std::swap((*itDequesArr)[0], (*itDequesArr)[1]);
			}
		}
		return;
	}

	std::deque<std::deque<int> > newDequesArr;
	std::deque<bool> swapRecords;

	std::deque<int> firstDeque = this->_dequesArr[0];
	if (firstDeque.size() % 2 == 1) {
		last = firstDeque.back();
		firstDeque.pop_back();
	}
	for (std::deque<int>::iterator it = firstDeque.begin(); it != firstDeque.end(); it += 2) {
		if (*it > *(it + 1)) {
			swapRecords.push_back(true);
			std::swap(*it, *(it + 1));
		} else {
			swapRecords.push_back(false);
		}
		this->_comparesentCounterDeque++;
		upper.push_back(*(it + 1));
		lower.push_back(*it);
	}
	if (last != -1) {
		lower.push_back(last);
		swapRecords.push_back(false);
	}
	last = -1;
	newDequesArr.push_back(upper);
	newDequesArr.push_back(lower);
	upper.clear();
	lower.clear();

	for (std::deque<std::deque<int> >::iterator itDequesArr = this->_dequesArr.begin() + 1; itDequesArr != this->_dequesArr.end(); itDequesArr++) {
		if ((*itDequesArr).size() % 2 == 1) {
			last = (*itDequesArr).back();
			(*itDequesArr).pop_back();
		}
		int swapIndex = 0;
		for (std::deque<int>::iterator itDeque = (*itDequesArr).begin(); itDeque != (*itDequesArr).end(); itDeque += 2) {
			if (swapRecords[swapIndex] == true) {
				std::swap(*itDeque, *(itDeque + 1));
			}
			upper.push_back(*(itDeque + 1));
			lower.push_back(*itDeque);
			swapIndex++;
		}
		if (last != -1) {
			lower.push_back(last);
		}
		last = -1;
		newDequesArr.push_back(upper);
		newDequesArr.push_back(lower);
		upper.clear();
		lower.clear();
	}
	this->_dequesArr = newDequesArr;
	this->_counterDeque++;
	this->mergeInsertionDeque();
	
	firstDeque.clear();
	firstDeque = this->_dequesArr[0];
	std::deque<int> secondDeque = this->_dequesArr[1];
	
	std::deque<std::deque<int> > newInsertedDequesArr;
	
	std::deque<int> insertionIndexTableSrc;
	std::deque<int> insertionIndexTableDest;
	
	int increment = 0;
	int decrement2 = 0;
	bool decrementFlag = false;
	int tempDestIndex = 0;
	for (size_t i = 0; i < firstDeque.size(); i++) {
		if (::dequeIsEmpty(secondDeque)) {
			break ;
		}
		size_t indexToInsert = _jacobSequence[i] + increment - 1;
		if (indexToInsert >= secondDeque.size() || decrementFlag == true) {
			indexToInsert = secondDeque.size() - 1;
			while (secondDeque[indexToInsert] == -1) {
				indexToInsert--;
			}
			decrementFlag = true;
		}
		if (indexToInsert == 0) {
			firstDeque.insert(firstDeque.begin() + increment, secondDeque[indexToInsert]);
			secondDeque[indexToInsert] = -1;
			secondDeque.insert(secondDeque.begin() + increment, -1);
			tempDestIndex = 0;
		} else {
			this->binaryInsertionDeque(firstDeque, 0, indexToInsert, secondDeque[indexToInsert], &tempDestIndex);
			secondDeque[indexToInsert] = -1;
			secondDeque.insert(secondDeque.begin() + increment, -1);
		}
		insertionIndexTableSrc.push_back(indexToInsert - increment - decrement2);
		insertionIndexTableDest.push_back(tempDestIndex);
		if (decrementFlag == true) {
			decrement2++;
		} else {
			increment++;
		}
	}
	newInsertedDequesArr.push_back(firstDeque);
	if (this->_dequesArr.size() == 2) {
		this->_dequesArr = newInsertedDequesArr;
		return ;
	}
	this->_dequesArr.erase(this->_dequesArr.begin());
	this->_dequesArr.erase(this->_dequesArr.begin());

	for (std::deque<std::deque<int> >::iterator itDequesArr = this->_dequesArr.begin(); itDequesArr != this->_dequesArr.end(); itDequesArr += 2) {
		firstDeque = *itDequesArr;
		secondDeque = *(itDequesArr + 1);
		if (secondDeque.size() > insertionIndexTableSrc.size()) {
			firstDeque.push_back(secondDeque.back());
		}
		for (size_t i = 0; i < insertionIndexTableSrc.size(); i++) {
			size_t indexToInsert = insertionIndexTableSrc[i];
			if (indexToInsert < secondDeque.size()) {
				firstDeque.insert(firstDeque.begin() + insertionIndexTableDest[i], secondDeque[indexToInsert]);
				secondDeque[insertionIndexTableSrc[i]] = -1;		
			}
		}
		newInsertedDequesArr.push_back(firstDeque);
		firstDeque.clear();
		secondDeque.clear();
	}
	this->_dequesArr = newInsertedDequesArr;
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

bool PmergeMe::isSorted(void) {
	std::vector<int> vector = this->_vectorsArr[0];
	int counter = 1;
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector[i] != counter) {
			return false;
		}
		counter++;
	}
	return true;
}

int PmergeMe::getSize( void ) const{
	return this->_vectorsArr[0].size();
}