/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:00:24 by anarama           #+#    #+#             */
/*   Updated: 2024/11/09 12:52:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <exception>
# include <vector>
# include <deque>
# include <string>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

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

		bool IsIntegerOverflow( std::string& number );
		void convertStringToVector( std::vector<std::string>& args );

		void mergeInsertion( void );
		void printVector( void );
};

#endif // PMERGE_ME_HPP
