/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:29 by anarama           #+#    #+#             */
/*   Updated: 2024/11/09 12:35:34 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <vector>

#include "PmergeMe.hpp"
#include "iostream"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error!\nIncorrect argument amount!" << std::endl;
	}
	std::vector<std::string> args(argv + 1, argv + argc);
	try {
		PmergeMe a;
		a.convertStringToVector(args);
		a.printVector();
	} catch (std::exception& e) {
		std::cerr << "Exception caught!\n" << e.what() << std::endl;
	}
	return 0;
}
