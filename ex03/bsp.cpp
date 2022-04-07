#include "Point.hpp"

float	calcArea(const Point a, const Point b, const Point c)
{
	Fixed	fixed;

	fixed = (a._x - c._x) * (b._y - c._y) - (b._x - c._x) * (a._y - c._y);
	return (fixed.toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	float a1 = calcArea(p, a, b);
	float a2 = calcArea(p, b, c);
	float a3 = calcArea(p, c, a);

	return ((a1 < 0.0f && a2 < 0.0f && a3 < 0.0f) || (a1 > 0.0f && a2 > 0.0f && a3 > 0.0f));
}
