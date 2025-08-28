/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:52:12 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:53:40 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal base part of a derived object has been created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& sourceObj) : type(sourceObj.type)
{
    std::cout << "AAnimal base part of a derived object has been copied!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    std::cout << "AAnimal base part of a derived object has been assigned!" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal base part of a derived object has been destroyed!" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}
