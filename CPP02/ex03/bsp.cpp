/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzielins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:17:25 by wzielins          #+#    #+#             */
/*   Updated: 2025/10/02 12:28:06 by wzielins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getY() - a.getY()) +
                  c.getX() * (a.getY() - b.getY())) / Fixed(2.0f);
	//if (area < Fixed(0))
	//{
	//	area = area * Fixed(-1);
	//}				
    return (area < Fixed(0)) ? area * Fixed(-1) : area;
}

//Area = (1/2) * |x1(y2 – y3) + x2(y3 – y1) + x3(y1 – y2)

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = calculateArea(a, b, c);

    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    return (totalArea == (area1 + area2 + area3));
}