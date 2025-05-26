#include "../include/Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_number_value = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor operator called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment called" << std::endl;
		this->_number_value = other.getRawBits();
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
	return (this->_number_value);
}

// setRawBits method
void Fixed::setRawBits(int const raw)
{
	this->_number_value = raw;
}
