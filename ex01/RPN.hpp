/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/12/13 15:00:10 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <list>
# include <string>
# include <exception>

class RPN {
	private:
		std::stack<int, std::list<int> > stack;
	public:
		RPN( void );
		RPN( const RPN& other );
		RPN& operator=( const RPN& other );
		~RPN( void );

		class DivisionByZeroException: public std::exception {
			public:
				const char* what() const throw();
		};

		void fillStack( const std::string& input );
		bool validateFormat( const std::string& input );
};

#endif // RPN_HPP