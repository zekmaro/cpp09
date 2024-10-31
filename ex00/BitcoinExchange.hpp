/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:22:04 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 15:10:16 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <exception>
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

		void	initMap( void );
		void	parseInput( void );

		void	isValidDate( std::string& date );
		
		void	isValidRate( float rate );
};

# endif // BITCOIN_EXCHANGE_HPP
