/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:04 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 11:55:39 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <string>
# include <fstream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _mapData;
		std::ifstream _inputFile;
		std::ifstream _data;

	public:
		BitcoinExchange( void );
		BitcoinExchange( char* fileName );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange( void );

		void	displayValue();
		void	initMap( void );
		void	parseInput();
		void	exchange();
		void	checkDate();
		void	checkRate();
};

# endif // BITCOIN_EXCHANGE_HPP
