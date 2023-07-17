/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:09:31 by acrespy           #+#    #+#             */
/*   Updated: 2023/06/14 15:59:54 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed result(const Point a, const Point b, const Point c)
{
	Fixed result;

	result = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;

	if (result >= 0)
		return (result);
	else
		return (result * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed d0 = result(point, b, c);
	Fixed d1 = result(a, point, c);
	Fixed d2 = result(a, b, point);

	Fixed a0 = result(a, b, c);
	Fixed a1 = d0 + d1 + d2;

	const float epsilon = 0.0001f;

	if (d0 == 0 || d1 == 0 || d2 == 0)
		return (false);
	else if (std::abs(a0.toFloat() - a1.toFloat()) <= epsilon)
		return (true);
	else
		return (false);
}

