/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:22:13 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/09 09:54:09 by hlakhal-         ###   ########.fr       */
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

Fixed Point::area(Fixed x1,Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
    Fixed det;
    det =  (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (det < 0)
       det = det * Fixed(-1);
    // std::cout << "det : " << det << std::endl;
    return det / 2;
}
bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a.x,a.y,b.x,b.y,c.x,c.y);
    Fixed A1 = area(point.x,point.y,b.x,b.y,c.x,c.y);
    Fixed A2 = area(a.x,a.y,point.x,point.y,c.x,c.y);
    Fixed A3 = area(a.x,a.y,b.x,b.y,point.x,point.y);
    // std::cout << A1 << "\t"  << A2 << "\t" << A3 << std::endl;
    // std::cout << A << std::endl;
    return A == (A1 + A2 + A3);
}
void Point::dispaly(Point const a, Point const b, Point const c, Point const point)
{
    Point other;
    // std::cout << other.bsp(a,b,c,point) << std::endl;
    if (other.bsp(a,b,c,point))
       std::cout << "Inside" << std::endl;
    else
        std::cout << "Outside" << std::endl;
    
}