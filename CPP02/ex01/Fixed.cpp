/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:10:10 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/09 17:29:08 by wzielins         ###   ########.fr       */
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
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
	//10 * 256 = 2560 (raw value)
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
	// 1 << 256 next 42.42 * 256 = 10859.52 czyli najbliżej do 10860
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &sourceObj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &sourceObj)
	{
		this->setRawBits(sourceObj.getRawBits());
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
	/*ponieważ _fixedPointValue jest stałoprzecinkowa to należy dokonać 
	rzutowania bo float jest zmiennoprzecinkową 2560 / 256 = 10.0*/
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
	/* lub liczba dzielona przez 256 bo 8 bitów
	stałoprzecinkowa na całkowitą 2560 >> 8 = 10*/
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
/*przeciązenie operatora << służy do wypyisywania różnego rodzaju typu danych
na wskazany typ, jest poza klasą bo jest globalny bo ma std::ostream

ostream to strumień wyjściowy*/
