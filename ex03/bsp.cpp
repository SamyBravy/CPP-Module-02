/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:50:32 by samuele           #+#    #+#             */
/*   Updated: 2024/11/26 01:14:15 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Vector two_points_to_vector(const Point &p1, const Point &p2)
{
    return Vector(p2 - p1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Vector ab = two_points_to_vector(a, b);
    Vector bc = two_points_to_vector(b, c);
    Vector ca = two_points_to_vector(c, a);

    Vector ap = two_points_to_vector(a, point);
    Vector bp = two_points_to_vector(b, point);
    Vector cp = two_points_to_vector(c, point);


    if (Point::cross_product(ap, ab) > 0 && Point::cross_product(bp, bc) > 0 && Point::cross_product(cp, ca) > 0)
        return true;
    if (Point::cross_product(ap, ab) < 0 && Point::cross_product(bp, bc) < 0 && Point::cross_product(cp, ca) < 0)
        return true;
    return false;
}
