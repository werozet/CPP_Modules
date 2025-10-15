/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:55:15 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 14:15:19 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
	brain = new Brain();
    std::cout << "Cat has been created!" << std::endl;
}

Cat::Cat(const Cat& sourceObj) : AAnimal(sourceObj)
{
    type = sourceObj.type;
	brain = new Brain(*sourceObj.brain);
    std::cout << "Cat has been copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& sourceObj)
{
    if (this != &sourceObj)
    {
        AAnimal::operator=(sourceObj);
        type = sourceObj.type;
		if (brain)
			delete brain;
		brain = new Brain(*sourceObj.brain);
    }
    std::cout << "Cat has been assigned!" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat has been destroyed!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau! Miau!" << std::endl;
}