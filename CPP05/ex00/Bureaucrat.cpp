/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:51:14 by wzielins          #+#    #+#             */
/*   Updated: 2025/11/13 11:25:57 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		// name is const, so we cannot assign it
		grade = other.grade;
	}
	return *this;
}
Bureaucrat::~Bureaucrat() {}

int Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
	return grade;
}
int Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
	return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

std::string Bureaucrat::getName() const {
	return name;
}
int Bureaucrat::getGrade() const {
	return grade;
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}