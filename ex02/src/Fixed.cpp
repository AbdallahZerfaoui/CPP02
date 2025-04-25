#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	nbr = 0;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	nbr = value << bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
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
	// std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->nbr = other.nbr;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	return ;
	// std::cout << "Fixed destructor called" << std::endl;
	// Clean up resources if necessary
}
// Comparaison operators
bool	Fixed::operator>(const Fixed& other) const
{
	return nbr > other.nbr;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return nbr < other.nbr;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return nbr >= other.nbr;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return nbr <= other.nbr;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return nbr == other.nbr;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return nbr != other.nbr;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
	// std::cout << "Addition operator called" << std::endl;
	Fixed result;
	result.nbr = this->nbr + other.nbr;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	// std::cout << "Subtraction operator called" << std::endl;
	Fixed result;
	result.nbr = this->nbr - other.nbr;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	// std::cout << "Multiplication operator called" << std::endl;
	Fixed result;
	result.nbr = (this->nbr * other.nbr) >> bits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	// std::cout << "Division operator called" << std::endl;
	Fixed result;
	result.nbr = (this->nbr << bits) / other.nbr;
	return result;
}

// Increment and Decrement operators
Fixed&	Fixed::operator++(void)
{
	nbr++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	nbr++;
	return (copy);
}

Fixed&	Fixed::operator--(void)
{
	nbr--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	nbr--;
	return (copy);
}

// Comparaison operators
Fixed&	Fixed::min(Fixed &val1, Fixed &val2)
{
	if (val1 <= val2)
		return (val1);
	return (val2);
}

const Fixed&	Fixed::min(const Fixed &val1, const Fixed &val2)
{
	if (val1 <= val2)
		return (val1);
	return (val2);
}

Fixed&	Fixed::max(Fixed &val1, Fixed &val2)
{
	if (val1 >= val2)
		return (val1);
	return (val2);
}

const Fixed&	Fixed::max(const Fixed &val1, const Fixed &val2)
{
	if (val1 >= val2)
		return (val1);
	return (val2);
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
