/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:36 by anarama           #+#    #+#             */
/*   Updated: 2024/11/05 11:52:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange a(argv[1]);
		a.initMap();
		a.parseInput();
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}