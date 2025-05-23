#include "../include/Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_nbr = 0;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_nbr = value << bits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	_nbr = value * (1 << bits); // here we multiply by 2^bits
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
		this->_nbr = other._nbr;
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
	return _nbr > other._nbr;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return _nbr < other._nbr;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return _nbr >= other._nbr;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return _nbr <= other._nbr;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return _nbr == other._nbr;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return _nbr != other._nbr;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
	// std::cout << "Addition operator called" << std::endl;
	Fixed result;
	result._nbr = this->_nbr + other._nbr;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	// std::cout << "Subtraction operator called" << std::endl;
	Fixed result;
	result._nbr = this->_nbr - other._nbr;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	// std::cout << "Multiplication operator called" << std::endl;
	Fixed result;
	result._nbr = (this->_nbr * other._nbr) >> bits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	// std::cout << "Division operator called" << std::endl;
	Fixed result;
	result._nbr = (this->_nbr << bits) / other._nbr;
	return result;
}

// Increment and Decrement operators
Fixed&	Fixed::operator++(void)
{
	_nbr++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy(*this);
	_nbr++;
	return (copy);
}

Fixed&	Fixed::operator--(void)
{
	_nbr--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy(*this);

	_nbr--;
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

// Conversion functions
// toFloat method
float Fixed::toFloat(void) const
{

	float result;
	result = _nbr *1.0 / (1 << bits);
	return result;
}

// toInt method
int Fixed::toInt(void) const
{
	int result;
	result = _nbr >> bits; // here we divide by 2^bits
	return (result);
}

// Setters and Getters
int Fixed::getRawBits(void) const
{
	return _nbr;
}

void Fixed::setRawBits(int const raw)
{
	_nbr = raw;
}
