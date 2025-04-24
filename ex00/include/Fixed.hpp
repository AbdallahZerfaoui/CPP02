#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int number_value;
		static const int number_fractional_bits = 8;

	public:
		// Canonical Form
		Fixed();                            // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();                           // Destructor
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// Add other member functions here (declared above or add more manually)

};

// Optional: Overload stream insertion operator (common 42 practice)
// std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
