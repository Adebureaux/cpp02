#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
	/* Constructors */
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);

	/* Copy assignment operator */
	Fixed &operator=(const Fixed &other);

	/* Comparison operators */
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/* Arithmetic operators */
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	/* Increment/decrement operators */
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	/* Static Members */
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	/* Utilities */
	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

	/* Destructor */
	~Fixed();

	private:
	int _fixed;
	const static int _bits = 8;
	float _total;
};

/* Insertion operator */
std::ostream &operator<<(std::ostream &o, Fixed const &other);

#endif
