/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:03:38 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 19:03:50 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character(const Character& sourceObj) : _name(sourceObj._name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (sourceObj._inventory[i])
            _inventory[i] = sourceObj._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& sourceObj)
{
    if (this != &sourceObj)
    {
        _name = sourceObj._name;
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (sourceObj._inventory[i])
                _inventory[i] = sourceObj._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            delete _inventory[i];
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    _inventory[idx] = 0;
}
//idx - index of the slot

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}