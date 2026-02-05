/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:29:02 by wzielins          #+#    #+#             */
/*   Updated: 2026/01/28 12:29:13 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat 
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	int incrementGrade();	
	int decrementGrade();
	void signForm(AForm &form);
	void executeForm(AForm const &form) const;

	std::string getName() const;
	int getGrade() const;
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
		
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif