#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // Common include, adjust as needed
# include <string>   // Common include, adjust as needed

class Fixed
{
	private:
		int nbr;
		static const int bits = 8;

	public:
		// Canonical Form
		Fixed();                            // Default constructor
		Fixed(const int value);             // Constructor from int
		Fixed(const float value);           // Constructor from float
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed_number); // TODO: Overload stream insertion operator
		~Fixed();                           // Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void ) const;
};

// Optional: Overload stream insertion operator (common 42 practice)
// std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
