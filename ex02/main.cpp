/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:29 by anarama           #+#    #+#             */
/*   Updated: 2024/11/14 18:43:19 by anarama          ###   ########.fr       */
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
		a.printVectorsArr();
		a.mergeInsertion();
		std::cout << "OUTPUT: " << std::endl;
		a.printVectorsArr();
		std::cout << "Num of comparesents: " << a.getComparesentCounter() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception caught!\n" << e.what() << std::endl;
	}
	return 0;
}
