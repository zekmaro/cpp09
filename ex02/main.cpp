/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:29 by anarama           #+#    #+#             */
/*   Updated: 2024/11/11 18:25:40 by andrejarama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>

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
		// std::cout << "INPUT: " << std::endl;
		// a.printVector();
		a.mergeInsertion();
		// std::cout << "OUTPUT: " << std::endl;
		// a.printVector();
		std::cout << "Num of comparesents: " << a.getComparesentCounter() << std::endl;
		a.generateJacobsthalSequence(10);
	} catch (std::exception& e) {
		std::cerr << "Exception caught!\n" << e.what() << std::endl;
	}
	return 0;
}
