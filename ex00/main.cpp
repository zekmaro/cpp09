/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:36 by anarama           #+#    #+#             */
/*   Updated: 2024/10/24 13:57:36 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream intputFile(argv[1]);
	if (!intputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	return 0;
}