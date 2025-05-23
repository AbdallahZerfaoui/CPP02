#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_nbr = 0;
}

// Constructor from int
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_nbr = value << _bits;
}

// Constructor from float
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_nbr = roundf(value * (1 << _bits)); // here we multiply by 2^bits
}

// Conversion constructor
std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number)
{
	os << fixed_number.toFloat();
	return os;
}
// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_nbr = other._nbr;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}

// toFloat method
float Fixed::toFloat(void) const
{

	float result;
	result = _nbr * 1.0 / (1 << _bits);
	return result;
}

// toInt method
int Fixed::toInt(void) const
{
	int result;
	result = _nbr >> _bits; // here we divide by 2^bits
	return (result);
}

// Getters and Setters
int Fixed::getRawBits(void) const
{
	return _nbr;
}

void Fixed::setRawBits(int const raw)
{
	_nbr = raw;
}
