/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:22:08 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 13:02:46 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created (default constructor)!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& sourceObj)
{
    *this = sourceObj;
    std::cout << "ClapTrap " << _name << " has been copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& sourceObj)
{
    if (this != &sourceObj)
    {
        _name = sourceObj._name;
        _hitPoints = sourceObj._hitPoints;
        _energyPoints = sourceObj._energyPoints;
        _attackDamage = sourceObj._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " has been assigned!" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cannot attack due to insufficient hit points or energy!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired, recovering " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cannot be repaired due to insufficient hit points or energy!" << std::endl;
    }
}