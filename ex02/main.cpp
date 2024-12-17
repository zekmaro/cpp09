/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:29 by anarama           #+#    #+#             */
/*   Updated: 2024/12/17 12:58:01 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include <vector>
#include <ctime>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error!\nIncorrect argument amount!" << std::endl;
		return 1;
	}
	std::vector<std::string> args(argv + 1, argv + argc);
	try {
		PmergeMe a;
		a.convertStringToVector(args);
		std::cout << "Before: ";
		a.printVectorsArr();
		std::clock_t start = std::clock();
		a.mergeInsertionVector();
		std::clock_t end = std::clock();
        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "After: ";
		a.printVectorsArr();
		std::cout << "Time to process a range of " << a.getSize() << " elements with std::vector " << elapsed_time << " seconds" << std::endl;
		start = std::clock();
		a.mergeInsertionDeque();
		// std::cout << "CHECKING DEQUE " << std::endl;
		// a.printDequesArr();
		end = std::clock();
		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of " << a.getSize() << " elements with std::deque " << elapsed_time << " seconds" << std::endl;
		// if (a.isSorted()) {
		// 	std::cout << "I DID IT!" << std::endl;
		// } else {
		// 	std::cout << "I HAVE A BAD NEWS BRO!" << std::endl;
		// }
		// std::cout << "Num of comparesents: " << a.getComparesentCounterVector() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught!\n" << e.what() << std::endl;
	}
	return 0;
}
