/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:26:24 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/06 03:16:17 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

const int Fixed::fracBit = 8;

Fixed::Fixed():fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj): fixed(obj.fixed)
{
    std::cout <<"Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
    if (this == &obj)
        return *this;
    fixed = obj.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void )  const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed;
}

void Fixed::setRawBits( int const raw)
{
    fixed = raw;
} 