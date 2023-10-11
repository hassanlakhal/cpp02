/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:53 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/11 20:02:55 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Point.hpp"

Fixed Point::area(Fixed x1,Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
    Fixed det;
    det =  (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (det < 0)
       det = det * Fixed(-1);
    
    return det / 2;
}

Fixed Point::getArea(Point const a, Point const b, Point const c, Point const point,int level)
{
    if (level == 0)
        return area(a.x,a.y,b.x,b.y,c.x,c.y);
    else if (level == 1)
        return area(point.x,point.y,b.x,b.y,c.x,c.y);
    else if (level == 2)
        return area(a.x,a.y,point.x,point.y,c.x,c.y);
    else if (level == 3)
        return area(a.x,a.y,b.x,b.y,point.x,point.y);
    return Fixed(0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    
    Point A, A1, A2 ,A3;
    if (A1.getArea(a,b,c,point,1) == Fixed(0) || A2.getArea(a,b,c,point,2) == Fixed(0) || A3.getArea(a,b,c,point,3) == Fixed(0))
       return false;
    return A.getArea(a,b,c,point,0) == (A1.getArea(a,b,c,point,1) + A2.getArea(a,b,c,point,2) + A3.getArea(a,b,c,point,3));
}