/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:22:01 by wzielins          #+#    #+#             */
/*   Updated: 2025/09/16 16:22:51 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: N must be greater than 0." << std::endl;
		return (NULL);
	}
	Zombie* zHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zHorde[i].setName(name);
	}
	return (zHorde);
}