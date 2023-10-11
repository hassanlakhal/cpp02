/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:22:13 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/11 18:15:06 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Point.hpp"

Point::Point() :x(0),y(0)
{
}

Point::Point(const float x_val, const float y_val):x(x_val),y(y_val)
{
    
}

Point::Point(const Point& other):x(other.x),y(other.y)
{
    
}

Point &Point::operator=(const Point &other)
{
    if (this == &other)
        return *this;
    (Fixed &)this->x = other.x;
    (Fixed &)this->y = other.y;
    return *this;
}

Point::~Point()
{
}


void Point::dispaly(Point const a, Point const b, Point const c, Point const point)
{
    // Point other;
    // std::cout << other.bsp(a,b,c,point) << std::endl;
    if (bsp(a,b,c,point))
       std::cout << "Inside" << std::endl;
    else
        std::cout << "Outside" << std::endl;
    
}