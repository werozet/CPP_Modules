/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:34:20 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 17:41:20 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
const std::string &RobotomyRequestForm::getTarget() const {
	return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy of " << target << " failed." << std::endl;
	}
}