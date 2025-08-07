/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:14:05 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/07 13:19:46 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> //for std::setw
#include "Contact.hpp"

class PhoneBook
{
	public:
		//PhoneBook() {}
		//~PhoneBook() {}
	    void addContact();
	    void searchContact();
	private:
		Contact contacts[8];
};

#endif