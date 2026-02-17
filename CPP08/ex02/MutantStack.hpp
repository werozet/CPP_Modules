/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:59:11 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/17 12:59:22 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {} //create empty stack(PL-stos)
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
    	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    	iterator begin() 
		{ 
			return std::stack<T>::c.begin(); 
		}

    	iterator end() 
		{ 
			return std::stack<T>::c.end(); 
		}

    	const_iterator begin() const 
		{ 
			return std::stack<T>::c.begin(); 
		}
    	
		const_iterator end() const 
		{ 
			return std::stack<T>::c.end(); 
		}
};