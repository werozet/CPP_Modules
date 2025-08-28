/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:32:27 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:32:41 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat has been created!" << std::endl;
}

Cat::Cat(const Cat& sourceObj) : Animal(sourceObj)
{
    type = sourceObj.type;
    std::cout << "Cat has been copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& sourceObj)
{
    if (this != &sourceObj)
    {
        Animal::operator=(sourceObj);
        type = sourceObj.type;
    }
    std::cout << "Cat has been assigned!" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat has been destroyed!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau! Miau!" << std::endl;
}