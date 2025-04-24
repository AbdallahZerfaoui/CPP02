#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->number_value = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
    *this = other;
	std::cout << "Copy assignment operator called" << std::endl;
	number_value = other.number_value;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy constructor called" << std::endl;
		this->number_value = other.number_value;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// getRawBits method
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number_value);
}

// setRawBits method
void Fixed::setRawBits(int const raw)
{
	this->number_value = raw;
}
