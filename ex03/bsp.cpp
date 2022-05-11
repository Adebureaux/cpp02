#include "Point.hpp"

float	calcArea(const Point a, const Point b, const Point c)
{
	Fixed	fixed;

	fixed = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
	return (fixed.toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float a1 = calcArea(p, a, b);
	float a2 = calcArea(p, b, c);
	float a3 = calcArea(p, c, a);

	return ((a1 < 0.0f && a2 < 0.0f && a3 < 0.0f) || (a1 > 0.0f && a2 > 0.0f && a3 > 0.0f));
}
