/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:21:05 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/27 14:21:10 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		//Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
		void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif