/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:51:53 by anarama           #+#    #+#             */
/*   Updated: 2024/11/05 12:55:59 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN {
	private:
		std::stack<char> stack;
	private:
		RPN( void );
		RPN( const RPN& other );
		RPN& operator=( const RPN& other );
		~RPN( void );
};

#endif // RPN_HPP