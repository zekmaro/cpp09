/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:24 by anarama           #+#    #+#             */
/*   Updated: 2024/12/10 14:28:53 by anarama          ###   ########.fr       */
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
		int _counterVector;
		int _counterDeque;
		std::vector<int> _jacobSequence;
		std::deque<int> _deque;
		std::deque<std::deque<int> > _dequesArr;
		int _comparesentCounterVector;
		int _comparesentCounterDeque;

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

		class NegativeIntegerFoundException: public std::exception {
			public:
				const char* what() const throw();
		};

		int getComparesentCounterVector( void ) const;

		bool IsIntegerOverflow( std::string& number );
		void convertStringToVector( std::vector<std::string>& args );

		void mergeInsertionVector( void );
		void mergeInsertionDeque( void );
		
		void binaryInsertionVector(std::vector<int>& dest, size_t start, size_t end, int value, int *destIndex);
		void binaryInsertionDeque(std::deque<int>& dest, size_t start, size_t end, int value, int *destIndex);
		
		void printVector( void );
		void printVectorsArr( void );
		void printDequesArr( void );

		void generateJacobsthalSequence( size_t size );

		void initPairs( std::vector<int>& vector );

		bool isSorted( void) ;
		int getSize( void ) const;
};

#endif // PMERGE_ME_HPP
