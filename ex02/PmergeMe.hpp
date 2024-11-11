/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:24 by anarama           #+#    #+#             */
/*   Updated: 2024/11/11 13:51:20 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <exception>
# include <vector>
# include <deque>
# include <string>

# define DEFAULT_COMPARESENT_COUNTER 0

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::vector<std::pair<int, int> > _pairedValues;
		int counter;
		std::vector<int> _jacobSequence;
		std::deque<int> _deque;
		int _comparesentCounter;

	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe& other );
		PmergeMe& operator=( const PmergeMe& other );
		~PmergeMe( void );

		class IncorrectInputException: public std::exception {
			public:
				const char* what() const throw();
		};

		class IsIntegerOverflowException: public std::exception {
			public:
				const char* what() const throw();
		};

		class EmptyInputException: public std::exception {
			public:
				const char* what() const throw();
		};

		int getComparesentCounter( void ) const;

		bool IsIntegerOverflow( std::string& number );
		void convertStringToVector( std::vector<std::string>& args );

		void mergeInsertion( void );
		void binaryInsertion( unsigned int start, unsigned int end, int value );
		
		void printVector( void );

		void generateJacobsthalSequence( int size );
};

#endif // PMERGE_ME_HPP
