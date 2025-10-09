/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:10:55 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/09 13:34:03 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &sourceObj);
		Fixed(int value);
		Fixed(float value);
		~Fixed();

		Fixed &operator=(const Fixed &sourceObj);

		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
//Operator << musi być POZA klasą (globalny) żeby działać z std::cout
#endif