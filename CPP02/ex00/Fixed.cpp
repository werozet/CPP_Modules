/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:07:15 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/09 13:05:40 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) //initializer list
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &sourceObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = sourceObj;
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &sourceObj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &sourceObj) // Zabezpieczenie przed a = a;
	{
		this->setRawBits(sourceObj.getRawBits());
	}
	return *this; // Zwraca referencję;
}

int Fixed::getRawBits(void) const
{
	std::cout <<"getRawBits member function called" << std::endl;
	return this->_fixedPointValue; //return raw value
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw; //set raw value
}