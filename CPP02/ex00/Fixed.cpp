/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:07:15 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/02 12:27:39 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &sourceObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = sourceObj;
	//this->_fixedPointValue = sourceObj._fixedPointValue;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &sourceObj)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &sourceObj)
	{
		this->setRawBits(sourceObj.getRawBits());
		//this->_fixedPointValue = sourceObj._fixedPointValue;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout <<"getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}