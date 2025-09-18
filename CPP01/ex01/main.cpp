/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:21:28 by wzielins          #+#    #+#             */
/*   Updated: 2025/09/16 16:39:27 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 6;
	Zombie* zhorde = zombieHorde(N, "Zombie");
	if(zhorde)
	{
		for(int i = 0; i < N; i++)
		{
			zhorde[i].announce();
		}
		delete[] zhorde;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
	}
	return 0;
}