/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:17:23 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:17:32 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* heapZombie = new Zombie(name);
	return (heapZombie);
	//return (new Zombie(name));
	/*create zombie on heap(stercie) and return pointer*/
}