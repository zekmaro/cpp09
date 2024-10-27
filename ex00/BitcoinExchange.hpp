/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:04 by anarama           #+#    #+#             */
/*   Updated: 2024/10/27 21:00:45 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <fstream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, int> _inputData;
		std::ifstream _inputFile;
		std::ifstream _data;

	public:
		BitcoinExchange( void );
		BitcoinExchange( std::string& fileName );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange( void );

		void	displayValue();
		void	initMap();
		void	parseInput();
		void	exchange();
};

# endif // BITCOIN_EXCHANGE_HPP
