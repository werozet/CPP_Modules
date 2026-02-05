/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:32:56 by wzielins          #+#    #+#             */
/*   Updated: 2026/01/28 12:33:08 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm (const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}
	
PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}