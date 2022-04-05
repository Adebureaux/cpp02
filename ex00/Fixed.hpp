#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();

	private:
	int _fixed;
	const static int _bits = 8;
};

#endif
