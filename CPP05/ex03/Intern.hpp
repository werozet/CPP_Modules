/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:30:17 by wzielins          #+#    #+#             */
/*   Updated: 2026/02/05 17:42:05 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	// Function to create a form based on the form name and target
	AForm* makeForm(const std::string& formName, const std::string& target);
};