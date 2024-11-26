/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:41:34 by samuele           #+#    #+#             */
/*   Updated: 2024/11/26 01:18:15 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) { }

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) { }

Point::~Point() { }

Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        // non faccio nulla perché _x e _y sono const
    }
    return *this;
}

bool Point::operator==(const Point &point) const
{
    return (_x == point.getX() && _y == point.getY());
}

Point Point::operator+(const Point &point) const
{
    return Point(_x + point.getX(), _y + point.getY());
}

Point Point::operator-(const Point &point) const
{
    return Point(_x - point.getX(), _y - point.getY());
}

const Fixed &Point::getX() const
{
    return _x;
}

const Fixed &Point::getY() const
{
    return _y;
}

Fixed Point::dot_product(const Vector &p1, const Vector &p2)
{
    return (p1.getX() * p2.getX() + p1.getY() * p2.getY());
}

Fixed Point::cross_product(const Vector &v1, const Vector &v2)
{
    return (v1.getX() * v2.getY() - v1.getY() * v2.getX());
}
