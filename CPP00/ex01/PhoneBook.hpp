/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:14:05 by wzielins          #+#    #+#             */
/*   Updated: 2025/09/03 13:04:06 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> 
#include "Contact.hpp"

class PhoneBook
{
	public:
	    void addContact();
	    void searchContact();
	private:
		Contact contacts[8];
};

#endif