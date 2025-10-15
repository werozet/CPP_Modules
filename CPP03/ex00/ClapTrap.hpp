/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:23:08 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 13:12:16 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;          // Live points
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap();                                  // Default constructor
        ClapTrap(const std::string& name);         // Parameterized constructor
        ClapTrap(const ClapTrap& sourceObj);      // Copy constructor
        ClapTrap& operator=(const ClapTrap& sourceObj); // assignment operator
        ~ClapTrap();                            // Destructor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif