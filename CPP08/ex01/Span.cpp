/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:15:42 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/16 17:16:38 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int maxSize): _maxSize(maxSize) {}

Span::Span(const Span& other): _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
};

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
	{
		throw SpanFullException();
	}
	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t distanceSize = std::distance(begin, end);
	if (_numbers.size() + distanceSize > _maxSize)
	{
		throw SpanFullException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
	if(_numbers.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortest = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int difference = sortedNumbers[i] - sortedNumbers[i - 1];
		if (difference < shortest)
		{
			shortest = difference;
		}
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
	{
		throw NotEnoughNumbersException();
	}
	int minElement = *std::min_element(_numbers.begin(), _numbers.end());
	//min_element dont return value only iterator so we need "*" to readout <- this is dereference
	int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
	return maxElement - minElement;
}

const char* Span::SpanFullException::what() const throw() 
{
    return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() 
{
    return "Not enough numbers to calculate a span";
}