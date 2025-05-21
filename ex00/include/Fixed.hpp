#ifndef FIXED_HPP
# define FIXED_HPP

/**
 * @file Fixed.hpp
 * @brief Header file for the Fixed class.
 * @details This class represents a fixed-point number with a specific number of fractional bits.
 * It provides methods to get and set the raw bits of the fixed-point number.
 * The class follows the canonical form, including a default constructor, copy constructor,
 * copy assignment operator, and destructor.
 */
class Fixed
{
	private:
		int _number_value;
		static const int _bits = 8;

	public:
		// Canonical Form
		Fixed();                            // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();                           // Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
