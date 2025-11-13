/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:53:54 by wzielins          #+#    #+#             */
/*   Updated: 2025/11/13 11:25:37 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Tom", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("John", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
	
}