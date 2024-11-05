/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:05:18 by anarama           #+#    #+#             */
/*   Updated: 2024/11/05 14:41:07 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Incorrect argument amount!" << std::endl;
		return 1;
	}
	RPN a;
	std::string str = argv[1];
	a.fillStack(str);
	return 0;
}