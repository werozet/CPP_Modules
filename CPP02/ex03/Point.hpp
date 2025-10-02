/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:16:59 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/02 12:28:16 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float xValue, const float yValue);
    Point(const Point &source);
    Point &operator=(const Point &source);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed calculateArea(Point const &a, Point const &b, Point const &c);
#endif