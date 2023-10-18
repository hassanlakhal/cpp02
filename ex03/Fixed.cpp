/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:22:00 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/18 15:19:11 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

const int Fixed::fracBit = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& other) 
{
    os << other.toFloat();
    return os;
}

Fixed::Fixed(const int raw)
{
    fixed =  raw << fracBit;
}

Fixed::Fixed(const float raw)
{
    fixed = roundf((raw  * (1 << fracBit)));
}
Fixed::Fixed(): fixed(0)
{
}

Fixed::~Fixed()
{
}
Fixed& Fixed::operator= (const Fixed& other)
{
    if(this == &other)
        return *this;
    this->fixed = other.fixed;
    return *this; 
}

Fixed::Fixed(const Fixed& other) : fixed(other.fixed)
{
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixed) / (1 << fracBit));
}
int Fixed::toInt(void) const
{
    return (fixed  >> fracBit);
}
Fixed Fixed::operator - (const Fixed& other)
{
    return Fixed(this->fixed - other.fixed);
}

Fixed &Fixed::operator*(const Fixed& other)
{
    this->fixed *= (other.fixed / (1 << fracBit));
    return *this;
}
Fixed Fixed::operator + (const Fixed& other)
{
    if (this == &other)
        return *this;
    fixed += other.fixed;
    return *this;
}
Fixed &Fixed::operator / (const int a)
{
    if (a == 0)
    {
        this->fixed = 0;
        return *this;
    }
    this->fixed /= a;
    return *this;
}
bool Fixed::operator == (const Fixed& other)
{
    if (fixed == other.fixed)
      return true;
    else
        return false;
}
bool Fixed::operator < (int a)
{
    if (fixed < a)
      return true;
    else
        return false;
}