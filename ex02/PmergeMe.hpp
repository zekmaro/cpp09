/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:24 by anarama           #+#    #+#             */
/*   Updated: 2024/11/18 21:05:23 by anarama          ###   ########.fr       */
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
		std::vector<std::vector<int> > _vectorsArr;
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
		void binaryInsertion(std::vector<int>& dest, size_t start, size_t end, int value, int *destIndex);
		
		void printVector( void );
		void printVectorsArr( void );

		void generateJacobsthalSequence( size_t size );

		void initPairs( std::vector<int>& vector );

		bool checkIsSorted( void );
};

#endif // PMERGE_ME_HPP
