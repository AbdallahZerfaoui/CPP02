#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	nbr = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	nbr = roundf(value * (1 << bits)); // here we multiply by 2^bits
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
	// std::cout << "Fixed copy constructor called" << std::endl;
	// Copy member variables from 'other'.
	// Often done by calling the copy assignment operator:
    *this = other;
    // Alternatively, copy them directly here:
    // 
	// Copy member variables
	nbr = other.nbr;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Clean up existing resources if necessary

        
	// Copy member variables
		this->nbr = other.nbr;
		// Assign member variables from 'other' (assigned above or add more manually)
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
	// Clean up resources if necessary
}

// toFloat method
float Fixed::toFloat(void) const
{

	float result;
	result = nbr *1.0 / (1 << bits);
	return result;
}

// toInt method
int Fixed::toInt(void) const
{
	int result;
	result = nbr >> bits; // here we divide by 2^bits
	return (result);
}

int Fixed::getRawBits(void) const
{
	return this->nbr; //TODO: should i use this??
}

void Fixed::setRawBits(int const raw)
{
	this->nbr = raw;
}
// Add other member function definitions here (declared above or add more manually)

// Optional: Overload stream insertion operator definition
// std::ostream& operator<<(std::ostream& os, const Fixed& obj)
// {
//     // Output object state to stream
//     return os;
// }
