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

		// Comparaison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// Increment and Decrement operators
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		// Min and Max functions
		static Fixed&		min(Fixed &val1, Fixed &val2);
		static const Fixed&	min(const Fixed &val1, const Fixed &val2);
		static Fixed&		max(Fixed &val1, Fixed &val2);
		static const Fixed&	max(const Fixed &val1, const Fixed &val2);	

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void ) const;
};


#endif
