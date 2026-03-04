/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:00 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 13:27:23 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector> // for container, size
#include <iterator>
#include <exception>
#include <algorithm> //for sort, min_element, max_element
#include <iostream>
#include <climits>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		Span();
	public:
		Span(unsigned int_maxSize);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		template <typename InputIt>
		void addNumbers(InputIt begin, InputIt end);
		int shortestSpan() const;
		int longestSpan() const;
		
		class SpanFullException: public std::exception
		{
			const char* what() const throw(); 
			//no need add virtual for begin becausse "what" in basic is always virtual
		};
		class NotEnoughNumbersException : public std::exception 
		{
        	const char* what() const throw();
    	};

};

template <typename InputIt>
void Span::addNumbers(InputIt begin, InputIt end)
{
	for (InputIt it = begin; it != end; ++it)
	{
		if (_numbers.size() >= _maxSize)
		{
			throw SpanFullException();
		}
		_numbers.push_back(*it);
	}
}