/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:51:59 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/17 22:47:33 by hlakhal-         ###   ########.fr       */
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
Fixed::Fixed() : fixed(0)
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

bool Fixed::operator < (const Fixed& other)
{
    if (fixed < other.fixed)
      return true;
    else
        return false;
}

bool Fixed::operator > (Fixed& other)
{
    if (fixed > other.fixed)
      return true;
    else
        return false;
}

bool Fixed::operator == (const Fixed& other)
{
    if (fixed == other.fixed)
      return true;
    else
        return false;
}

bool Fixed::operator >= (const Fixed& other)
{
    if (fixed >= other.fixed)
      return true;
    else
        return false;
}

bool Fixed::operator <= (const Fixed& other)
{
    if (fixed <= other.fixed)
      return true;
    else
        return false;
}

bool Fixed::operator != (const Fixed& other)
{
    if (fixed != other.fixed)
      return true;
    else
        return false;
}

Fixed Fixed::operator + (const Fixed& other)
{
    if (this == &other)
        return *this;
    fixed += other.fixed;
    return *this;
}

Fixed Fixed::operator - (const Fixed& other)
{
    return Fixed(this->fixed - other.fixed);
}

Fixed &Fixed::operator*(const Fixed& other)
{
    this->fixed *= other.fixed / (1 << fracBit);
    return  *this;
}


Fixed &Fixed::operator / (const Fixed& other)
{
    if (other.fixed == 0)
    {
        std::cout << "Form indefine" << std::endl;
        this->fixed = 0;
        return *this;
    }
    this->fixed /= other.fixed * (1 << fracBit);
    return *this;
}

Fixed &Fixed::operator++()
{
    ++this->fixed;
    return *this;
}

Fixed &Fixed::operator--()
{
    --this->fixed;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixed++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixed--;
    return temp;
}

bool Fixed::compare(const Fixed& a, const Fixed& b, bool check)
{
    return (check ? (a.fixed > b.fixed) : (a.fixed < b.fixed));
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
   return((compare(a,b,true)) ? a:b);
}

Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return((compare(a,b,true)) ? (Fixed &)a:(Fixed &)b);
}
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
   return((compare(a,b,false)) ? a:b);
}

Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return((compare(a,b,false)) ? (Fixed &)a:(Fixed &)b);
}
int Fixed::getRawBits( void )  const
{
    return fixed;
}

void Fixed::setRawBits( int const raw)
{
    fixed = raw;
}