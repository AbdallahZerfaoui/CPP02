#include <iostream>
#include "include/Fixed.hpp"
#include "include/colors.hpp"

int main( void ) 
{
	// Mandatory
	std::cout << GREEN << "Mandatory" << RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	//Extra cases
	std::cout << GREEN << "Extra" << RESET << std::endl;
	Fixed val1(5.125f);
	Fixed val2(7.25f);
	bool result;
	// superior
	result = val1 > val2;
	std::cout << val1 << " > " << val2 << " : " << result << std::endl;
	// inferior
	result = val1 < val2;
	std::cout << val1 << " < " << val2 << " : " << result << std::endl;
	// different
	result = val1 != val2;
	std::cout << val1 << " != " << val2 << " : " << result << std::endl;
	// min
	std::cout << Fixed::min(a, b) << std::endl;
	return 0;
}
