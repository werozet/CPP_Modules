/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:15:13 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/02 12:28:07 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &sourceObj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = sourceObj;
}

Fixed::Fixed(int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
	//10 << 8 = 10 * 256 = 2560
}

Fixed::Fixed(float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
	/* 1 << 256 next 42.42 * 256 = 10859.52 czyli najbliżej do 10860*/
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &sourceObj)
{
	//std::cout << "Copy assigment operator called" << std::endl;
	if (this != &sourceObj)
	{
		this->setRawBits(sourceObj.getRawBits());
		//this->_fixedPointValue = sourceObj._fixedPointValue;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	//std::cout <<"getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
	/*ponieważ _fixedPointValue jest stałoprzecinkowa to należy dokonać 
	rzutowania bo float jest zmiennoprzecinkową*/
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
	/* lub liczba dzielona przez 256 bo 8 bitów
	stałoprzecinkowa na całkowitą*/
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
/*przeciązenie operatora << służy do wypyisywania różnego rodzaju typu danych
na wskazany typ, jest poza klasą bo jest globalny bo ma std::ostream

ostream to strumień wyjściowy

std::ostream &operator<<(std::ostream &out, const YourClass &obj)
{
    Wypisz dane obiektu obj do strumienia out
    out << obj.someData; Możesz użyć metod lub pól obiektu obj
    Zwróć referencję do strumienia wyjściowego
    return out;
}*/

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const 
{
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const 
{
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const 
{
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const 
{
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const 
{
    return this->_fixedPointValue != rhs._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &rhs) const 
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const 
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const 
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const 
{
    if (rhs._fixedPointValue == 0)
        throw std::runtime_error("Division by zero");
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}