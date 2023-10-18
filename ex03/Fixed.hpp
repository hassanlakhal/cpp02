/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:22:03 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/18 15:19:39 by hlakhal-         ###   ########.fr       */
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
    Fixed operator - (const Fixed& other);
    Fixed& operator * (const Fixed& other);
    Fixed operator + (const Fixed& other);
    Fixed &operator / (const int a);
    bool operator == (const Fixed& other);
    bool operator < (int a);
    ~Fixed();
    float toFloat( void ) const;
    int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif 

