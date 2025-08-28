/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:33:25 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:33:37 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog has been created!" << std::endl;
}

Dog::Dog(const Dog& sourceObj) : Animal(sourceObj)
{
    type = sourceObj.type;
    std::cout << "Dog has been copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& sourceObj)
{
    if (this != &sourceObj)
    {
        Animal::operator=(sourceObj);
        type = sourceObj.type;
    }
    std::cout << "Dog has been assigned!" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog has been destroyed!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Hau! Hau!" << std::endl;
}