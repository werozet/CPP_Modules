/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:24:46 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 16:29:38 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

const std::string &ShrubberyCreationForm::getTarget() const {
	return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
		throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str());
	if (file) {
		file << "           *\n";
		file << "          ***\n";
		file << "         *****\n";
		file << "        *******\n";
		file << "       *********\n";
		file << "      ***********\n";
		file << "     *************\n";
		file << "          |||\n";
		file << "          |||\n";
		file.close();
	}
	std::cout << "Shrubbery has been created in " << target << "_shrubbery" << std::endl;
}
