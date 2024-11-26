/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:28:39 by sdell-er          #+#    #+#             */
/*   Updated: 2024/11/25 00:10:12 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return *this;
	setRawBits(fixed.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	_value++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	_value--;
	return tmp;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return _value / (float)(1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
