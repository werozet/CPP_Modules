/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:24:46 by wzielins          #+#    #+#             */
/*   Updated: 2025/11/13 16:24:47 by wzielins         ###   ########.fr       */
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
    file << "      ccee88oo\n";
    file << "   C8O8O8Q8PoOb o8oo\n";
    file << "  dOB69QO8PdUOpugoO9bD\n";
    file << " CgggbU8OU qOp qOdoUOdcb\n";
    file << "    6OuU  /p u gcoUodpP\n";
    file << "      \\\\//  /douUP\n";
    file << "        \\\\////\n";
    file << "         |||/\\\n";
    file << "         |||\\/\n";
    file << "         |||||\n";
    file << "   .....//||||\\....\n";
    file.close();
	}
	std::cout << "Shrubbery has been created in " << target << "_shrubbery" << std::endl;
}
