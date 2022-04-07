#include "Fixed.hpp"

/************************** Constructors **************************************/
Fixed::Fixed()
{
	this->_total = 1 << this->_bits;
	this->_fixed = 0;
}

Fixed::Fixed(const int n)
{
	this->_total = 1 << this->_bits;
	this->_fixed = n << this->_bits;
}

Fixed::Fixed(const float n)
{
	this->_total = 1 << this->_bits;
	this->_fixed = roundf(n * this->_total);
}

Fixed::Fixed(const Fixed &other)
{
	this->_total = 1 << this->_bits;
	*this = other;
}
/************************** Constructors End **********************************/


/************************** Copy assignment operator **************************/
Fixed &Fixed::operator=(const Fixed &other)
{
	this->_fixed = other.getRawBits();
	return (*this);
}
/************************** Copy assignment operator End **********************/

/************************** Comparison operators ******************************/
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixed > other.getRawBits() ? true : false);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixed < other.getRawBits() ? true : false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixed >= other.getRawBits() ? true : false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixed <= other.getRawBits() ? true : false);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixed == other.getRawBits() ? true : false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixed != other.getRawBits() ? true : false);
}
/************************** Comparison operators End **************************/


/************************** Arithmetic operators ******************************/
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed tmp;
	
	tmp.setRawBits(this->_fixed + other.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed tmp;
	
	tmp.setRawBits(this->_fixed - other.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits((this->_fixed * other.getRawBits()) >> this->_bits);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits((this->_fixed << this->_bits) / other.getRawBits());
	return (tmp);
}
/************************** Arithmetic operators End **************************/


/************************** Increment/decrement operators *********************/
Fixed &Fixed::operator++(void)
{
	this->_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	operator--();
	return (tmp);
}
/************************** Increment/decrement operators End *****************/


/************************** Static Members ************************************/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
}
/************************** Static Members End ********************************/


/************************** Utilities *****************************************/
int Fixed::toInt(void) const
{
	return (this->_fixed >> this->_bits);
}

float Fixed::toFloat(void) const
{
	return (this->_fixed / this->_total);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}
/************************** Utilities End *************************************/


/************************** Destructor ****************************************/
Fixed::~Fixed()
{
	return;
}
/************************** Destructor End ************************************/


/************************** Insertion operator ********************************/
std::ostream &operator<<(std::ostream &o, Fixed const &other)
{
	o << other.toFloat();
	return (o);
}
/************************** Insertion operator End ****************************/
