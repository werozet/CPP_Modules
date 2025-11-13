/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:27:02 by wzielins          #+#    #+#             */
/*   Updated: 2025/11/13 13:14:38 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
	: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}
	
Form &Form::operator=(const Form &other) {
	if (this != &other) {
		// name is const, so we cannot assign it
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecGrade() const {
	return execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form: " << form.getName()
	   << ", Sign Grade: " << form.getSignGrade()
	   << ", Exec Grade: " << form.getExecGrade();
	return os;
}
