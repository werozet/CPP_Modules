/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:17:55 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/17 12:53:54 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

/*int main()
	{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/
int main()
{
	Span sp = Span(5);
    try {
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cout << "Exception (full): " << e.what() << std::endl;
    }

    // Test wyjątku przy zbyt małej liczbie elementów
    try {
        Span sp2(2);
        sp2.addNumber(1);
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception (not enough numbers): " << e.what() << std::endl;
    }

    // Test masowego dodawania przez iteratory
	try {
		Span sp3(5);
		std::vector<int> vec;
		for (int i = 0; i < 10000; ++i)
			vec.push_back(i * 2);
		sp3.addNumbers(vec.begin(), vec.end());
		std::cout << "sp3 shortestSpan: " << sp3.shortestSpan() << std::endl; // powinno być 2
		std::cout << "sp3 longestSpan: " << sp3.longestSpan() << std::endl;   // powinno być 19998
	} catch (const std::exception& e) {
		std::cout << "Exception (too many numbers): " << e.what() << std::endl;
	}

}