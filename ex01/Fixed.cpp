#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor Called" << std::endl;
	this->_total = 1 << this->_bits;
	this->_fixed = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor Called" << std::endl;
	this->_total = 1 << this->_bits;
	this->_fixed = n << this->_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor Called" << std::endl;
	this->_total = 1 << this->_bits;
	this->_fixed = roundf(n * this->_total);
}

int Fixed::toInt(void) const
{
	return (this->_fixed >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return (this->_fixed / this->_total);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor Called" << std::endl;
	this->_total = 1 << this->_bits;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = other.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return (o);
}
