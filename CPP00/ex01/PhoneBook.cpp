/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:13:10 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/07 13:22:26 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//PhoneBook::PhoneBook() {}

void PhoneBook::addContact()
{
    Contact newContact;
	std::string input;

    do 
	{
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input interrupted. Cancelling contact addition." << std::endl;
            return;
        }
        if (input.empty())
            std::cout << "First name cannot be empty. Please try again." << std::endl;
		else
			newContact.setFirstName(input);
    } 
	while (input.empty());
    do 
	{
        std::cout << "Enter last name: ";
		if (!std::getline(std::cin, input))
        {
            std::cout << "Input interrupted. Cancelling contact addition." << std::endl;
            return;
        }
		if (input.empty())
			std::cout << "Last name cannot be empty. Please try again." << std::endl;
		else
			newContact.setLastName(input);
    } 
	while (input.empty());
    do
	{
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input interrupted. Cancelling contact addition." << std::endl;
            return;
        }
		if (input.empty())
			std::cout << "Nickname cannot be empty. Please try again." << std::endl;
		else
			newContact.setNickname(input);
    }
	while (input.empty());
    do
	{
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input interrupted. Cancelling contact addition." << std::endl;
            return;
        }
        if (input.empty())
            std::cout << "Phone number cannot be empty. Please try again." << std::endl;
		else
			newContact.setPhoneNumber(input);
    }
	while (input.empty());
    do 
	{
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input interrupted. Cancelling contact addition." << std::endl;
            return;
        }
		if (input.empty())
			std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
		else
			newContact.setDarkestSecret(input);
    }
	while (input.empty());
	for (int i = 7; i > 0; --i) 
	{
        contacts[i] = contacts[i - 1];
	}
	contacts[0] = newContact;
    std::cout << "Contact added successfully!" << std::endl;
}


std::string cutContact(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContact()
{
	bool hasContacts = false;
    for (int i = 0; i < 8; ++i) {
        if (!contacts[i].getFirstName().empty())
		{
            hasContacts = true;
            break;
        }
    }
    if (!hasContacts) {
        std::cout << "No contacts available. Please add a contact first." << std::endl;
        return;
    }
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	int lastIndex = 0;
	for (int i = 0; i < 8; ++i) 
	{
        if (!contacts[i].getFirstName().empty())
		{
            std::cout << std::setw(10) << (i + 1) << "|"
                      << std::setw(10) << cutContact(contacts[i].getFirstName()) << "|"
                      << std::setw(10) << cutContact(contacts[i].getLastName()) << "|"
                      << std::setw(10) << cutContact(contacts[i].getNickname()) << "|" << std::endl;
			lastIndex = i + 1;
        }
    }
	int index;
	std::cout << "Enter the index of the contact you want to view (1-" << lastIndex << "): ";
	std::cin >> index;
	if (std::cin.fail()) 
	{
	    std::cin.clear();
	    std::cout << "Invalid index. Please try again." << std::endl;
	    return;
	}
	if (std::cin.eof()) 
    {
    	std::cout << "Input interrupted. Returning to main menu." << std::endl;
    	return;
	}
	if (index < 1 || index > lastIndex) 
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}
	index -= 1;
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}