/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:35:20 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:36:53 by wzielins         ###   ########.fr       */
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

void Harl::filter(std::string level)
{
	int index = -1;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			debug();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			info();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			warning();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}