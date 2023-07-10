/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:09:31 by acrespy           #+#    #+#             */
/*   Updated: 2023/06/14 15:59:54 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point)
{
	*this = point;
}

Point& Point::operator=(const Point& point)
{
    if (this != &point)
	{
        this->_x = point.getX();
        this->_y = point.getY();
    }
    return (*this);
}

Point::~Point() {}

Fixed const &Point::getX(void) const
{
	return (this->_x);
}

Fixed const &Point::getY(void) const
{
	return (this->_y);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const ab = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed const bc = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());

	if (ab > 0 && bc > 0)
		return (true);
	else if (ab < 0 && bc < 0)
		return (true);
	return (false);
}
