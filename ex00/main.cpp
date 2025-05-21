#include <iostream>
#include "include/Fixed.hpp"

/**
 * The main function demonstrates the use of the Fixed class.
 * It creates instances of Fixed, copies them, and prints their raw bits.
 */
int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}