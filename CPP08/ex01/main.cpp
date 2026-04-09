 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:55 by wzielins          #+#    #+#             */
/*   Updated: 2026/03/04 13:19:28 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
	{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Test 1 - single addition" << std::endl; //Single addition
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span bigSpan(10000);
		std::vector<int> values;
		for (int i = 0; i < 10000; ++i)
		{
			values.push_back(i * 2);
		}
		bigSpan.addNumbers(values.begin(), values.end());
		std::cout << "Test 2 - multiple additions" << std::endl; //Multiple additions
		std::cout << "10000 shortestSpan: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "10000 longestSpan: " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
