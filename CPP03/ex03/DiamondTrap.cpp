/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:34:20 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 14:34:30 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("noName_clap_name"), ScavTrap(), FragTrap(), _name("noName")
{
    _hitPoints = 100;      // FragTrap
    _energyPoints = 50;    // ScavTrap
    _attackDamage = 30;    // FragTrap
    std::cout << "DiamondTrap " << _name << " has been created (default constructor)!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& sourceObj)
    : ClapTrap(sourceObj), ScavTrap(sourceObj), FragTrap(sourceObj), _name(sourceObj._name)
{
    *this = sourceObj;
    std::cout << "DiamondTrap " << _name << " has been copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& sourceObj)
{
    if (this != &sourceObj)
    {
        ClapTrap::operator=(sourceObj);
        ScavTrap::operator=(sourceObj);
        FragTrap::operator=(sourceObj);
        _name = sourceObj._name; //object.field -> field of object
    }
    std::cout << "DiamondTrap " << _name << " has been assigned!" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " has been destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name
              << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}