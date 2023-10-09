/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:52:47 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/08 20:40:48 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
    int fixed;
    static const int fracBit;
public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& other);
    Fixed& operator = (const Fixed& other);
    ~Fixed();
    float toFloat( void ) const;
    int toInt( void ) const;
    bool operator < (const Fixed& other);
    bool operator > (Fixed& other);
    bool operator == (const Fixed& other);
    bool operator >= (const Fixed& other);
    bool operator <= (const Fixed& other);
    bool operator != (const Fixed& other); 
    Fixed operator + (const Fixed& other);
    Fixed operator - (const Fixed& other);
    Fixed operator * (const Fixed& other);
    Fixed operator / (const Fixed& other);
    Fixed &operator ++();
    Fixed &operator --();
    Fixed operator ++(int);
    Fixed operator --(int);
    static bool compare(const Fixed& a, const Fixed& b, bool check);
    static  Fixed& max(Fixed &a, Fixed &b) ;
    static Fixed& max(const Fixed &a, const Fixed &b);
    static  Fixed& min(Fixed &a, Fixed &b) ;
    static Fixed& min(const Fixed &a, const Fixed &b);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif 

