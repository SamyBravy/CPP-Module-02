/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:39:55 by samuele           #+#    #+#             */
/*   Updated: 2024/11/26 01:15:35 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point;
typedef Point Vector;

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;


    public:
        Point();
        Point(const float x, const float y);
        Point(const Fixed &x, const Fixed &y);
        Point(const Point &point);
        ~Point();
        
        Point &operator=(const Point &point);

        bool operator==(const Point &point) const;

        Point operator+(const Point &point) const;
        Point operator-(const Point &point) const;

        const Fixed &getX() const;
        const Fixed &getY() const;

        static Fixed dot_product(const Vector &p1, const Vector &p2);
        static Fixed cross_product(const Vector &v1, const Vector &v2);
};

#endif
