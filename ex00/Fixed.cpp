#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor Called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor Called" << std::endl;
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
