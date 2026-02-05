/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:28:10 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 17:08:06 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>


int main()
{
	srand(time(0)); // Initialize random seed
	
	ShrubberyCreationForm shrubberyForm("Home");
	RobotomyRequestForm robotomyForm("Robot");
	PresidentialPardonForm pardonForm("Alien");
	Bureaucrat b1("Tom", 1);
	Bureaucrat b2("John", 150);
	Bureaucrat b3("Rick", 30);
	
	try {
		b1.signForm(shrubberyForm);
		b1.signForm(robotomyForm);
		b1.signForm(pardonForm);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b3.signForm(shrubberyForm);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		b1.executeForm(shrubberyForm);
		b1.executeForm(robotomyForm);
		b1.executeForm(pardonForm);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b2.executeForm(shrubberyForm);
		b2.executeForm(robotomyForm);
		b2.executeForm(pardonForm);
	} catch (const std::exception &e) {
		std::cerr <<e.what() << std::endl;
	}
		
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
		b2.signForm(shrubberyForm);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	ShrubberyCreationForm unsignedForm("Garden");
	try {
		b1.executeForm(unsignedForm);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}