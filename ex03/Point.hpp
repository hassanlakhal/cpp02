/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlakhal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:22:17 by hlakhal-          #+#    #+#             */
/*   Updated: 2023/10/11 18:52:17 by hlakhal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

class Point
{
    private:
        const Fixed  x;
        const Fixed  y;
    public:
        Point();
        Point(const float x_val, const float y_val);
        Point(const Point& other);
        Fixed area(Fixed x1,Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3);
        Point& operator=(const Point &other);
        Fixed getArea(Point const a, Point const b, Point const c, Point const point, int level); 
        static void dispaly(Point const a, Point const b, Point const c, Point const point);
        ~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);



