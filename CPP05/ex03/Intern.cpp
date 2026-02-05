/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:29:37 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 18:09:27 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) {return *this;}
Intern::~Intern() {}

typedef AForm* (*FormCreator)(const std::string&);

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct { const char* name; FormCreator creator; } forms[] = {
        {"shrubbery creation form", createShrubbery},
        {"robotomy request form", createRobotomy},
        {"presidential pardon form", createPresidential}
    };
    for (size_t i = 0; i < 3; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }
    std::cerr << "Intern: form name not found!" << std::endl;
    return 0;
}