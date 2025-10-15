/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:34:53 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 13:55:55 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal has been created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& sourceObj) : type(sourceObj.type)
{
    std::cout << "WrongAnimal has been copied!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    std::cout << "WrongAnimal has been assigned!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal has been destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Unknown WrongAnimal sound!" << std::endl;
}