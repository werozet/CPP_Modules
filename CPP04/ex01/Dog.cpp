/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:44:40 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/15 14:08:50 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
	brain = new Brain();
    std::cout << "Dog has been created!" << std::endl;
}

Dog::Dog(const Dog& sourceObj) : Animal(sourceObj)
{
    type = sourceObj.type;
	brain = new Brain(*sourceObj.brain); //deep copy
    std::cout << "Dog has been copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& sourceObj)
{
    if (this != &sourceObj)
    {
        Animal::operator=(sourceObj);
        type = sourceObj.type;
		if (brain)
        	delete brain;                       //delete existing brain
        brain = new Brain(*sourceObj.brain); // deep copy
    }
    std::cout << "Dog has been assigned!" << std::endl;
    return *this;
}

Dog::~Dog()
{
	delete brain;
    std::cout << "Dog has been destroyed!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Hau! Hau!" << std::endl;
}