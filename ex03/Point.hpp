#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point
{
	public:
	Fixed _x;
	Fixed _y;
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	private:
	const Fixed x;
	const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);
std::ostream &operator<<(std::ostream &o, const Point &point);

#endif