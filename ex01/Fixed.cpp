/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:31:38 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/07 23:10:47 by hlakhal-         ###   ########.fr       */
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
    std::cout << "Int constructor called" << std::endl;
    fixed =  raw << fracBit;
}

Fixed::Fixed(const float raw)
{
    fixed = roundf((raw  * (1 << fracBit)));
    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator= (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &other)
        return *this;
    this->fixed = other.fixed;
    return *this; 
}

Fixed::Fixed(const Fixed& other) : fixed(other.fixed)
{
    std::cout << "Copy constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixed) / (1 << fracBit));
}
int Fixed::toInt(void) const
{
    return (fixed  >> fracBit);
}