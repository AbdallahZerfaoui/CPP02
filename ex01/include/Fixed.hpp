#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // Common include, adjust as needed

/**
 * @file Fixed.hpp
 * @brief Header file for the Fixed class.
 * @details This class represents a fixed-point number with a specific number of fractional bits.
 * It provides methods to get and set the raw bits of the fixed-point number.
 * The class follows the canonical form, including a default constructor, copy constructor,
 * copy assignment operator, and destructor.
 * The class also includes methods to convert between fixed-point and integer/float representations.
 */
class Fixed
{
	private:
		int _nbr;
		static const int _bits = 8;

	public:
		// Canonical Form
		Fixed();
		Fixed(const int value);             // Constructor from int
		Fixed(const float value);           // Constructor from float
		Fixed(const Fixed& other);          // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();
		// Getters and Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
		// Conversion methods
		float toFloat(void) const;
		int toInt(void ) const;
	};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number); // TODO: Overload stream insertion operator

#endif
