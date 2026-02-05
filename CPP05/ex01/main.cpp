/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:27:40 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 14:52:15 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	
	Bureaucrat b1("Tom", 1);
	Bureaucrat b2("John", 150);
	Bureaucrat b3("Rick", 30);
		
	try {
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f1("TopSecret", 1, 10);
		std::cout << f1 << std::endl;
		b1.signForm(f1); // Tom (grade 1) - sukces
		b2.signForm(f1);  // John (grade 150) - niepowodzenie
       	b3.signForm(f1);  // Rick (grade 30) - niepowodzenie
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Form f2("Normal", 35, 50);
		std::cout << f2 << std::endl;
		b2.signForm(f2); // John ma za niski stopień
		std::cout << b3 << std::endl;
		b3.signForm(f2); // Rick ma wystarczający stopień
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}