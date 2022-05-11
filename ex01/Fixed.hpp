#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	int toInt(void) const;
	float toFloat(void) const;
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();

	private:
	int _fixed;
	const static int _bits = 8;
	float _total;
};

std::ostream &operator<<(std::ostream &o, Fixed const &other);

#endif
