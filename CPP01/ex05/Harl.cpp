/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:33:14 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:33:24 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
			<< "pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
    std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger! If you did, "
			<< "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
			<< "I’ve been coming for years whereas you started working here "
			<< "since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void(Harl::*functions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	//tablica do funkcji członkowskich
	//return_type(ClassName::*array_name[])(parameter_list) = { &ClassName::method1, &ClassName::method2, ... };
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if(levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cerr << "Unknown level." << std::endl;
}