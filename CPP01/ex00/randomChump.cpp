/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:18:05 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:18:21 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie stackZombie = Zombie(name); //create zombie on stack(stos)
	//Zombie stackZombie(name);
	stackZombie.announce();	// announce the zombie
}