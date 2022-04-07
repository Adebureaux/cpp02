#include "Point.hpp"

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(const float x, const float y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point &other)
{
	*this = other;
}

Point &Point::operator=(const Point &other)
{
	this->_x = other._x;
	this->_y = other._y;
	return (*this);
}

Point::~Point()
{
	return;
}

std::ostream &operator<<(std::ostream &o, const Point &point)
{
	Fixed x(point._x);
	Fixed y(point._y);

	o << "(" << x << ", " << y << ")";
	return (o);
}
