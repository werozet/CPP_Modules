/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:20:04 by wzielins          #+#    #+#             */
/*   Updated: 2025/09/16 16:29:26 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {} //default constructor

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl; //default destructor
}

void Zombie::setName(std::string name) //new method to set the name
{
	this->name = name;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ... Moar brainz!" << std::endl;
}