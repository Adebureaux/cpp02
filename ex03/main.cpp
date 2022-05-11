#include "Point.hpp"

Point a(1, 0.5);
Point b(1.5, 1.5);
Point c(0.5, 3.0);

void check_bsp(bool res, bool exp)
{
	if (res == exp)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}

int main(void)
{
	std::cout << "Triangle properties:" << std:: endl << "a" << a << std::endl << "b" << b << std::endl << "c" << c << std::endl << std::endl; 
	check_bsp(bsp(a, b, c, a), false);
	check_bsp(bsp(a, b, c, b), false);
	check_bsp(bsp(a, b, c, c), false);
	check_bsp(bsp(a, b, c, Point(15, 15)), false);
	check_bsp(bsp(a, b, c, Point(-1, -1)), false);
	check_bsp(bsp(a, b, c, Point(1, 1.5)), true);
	check_bsp(bsp(a, b, c, Point(0, 1)), false);
	check_bsp(bsp(a, b, c, Point(1.5, 1)), false);
	check_bsp(bsp(a, b, c, Point(0.69, 2.03)), false);
	check_bsp(bsp(a, b, c, Point(0.70, 2.03)), true);
	return (0);
}
