/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:35:54 by wzielins          #+#    #+#             */
/*   Updated: 2025/08/28 18:36:03 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat has been created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& sourceObj) : WrongAnimal(sourceObj)
{
    type = sourceObj.type;
    std::cout << "WrongCat has been copied!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& sourceObj)
{
    if (this != &sourceObj)
    {
        WrongAnimal::operator=(sourceObj);
        type = sourceObj.type;
    }
    std::cout << "WrongCat has been assigned!" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat has been destroyed!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "<WrongCat> Miau?" << std::endl;
}