#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &object )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_value);
}

void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

Fixed&    Fixed::operator= ( const Fixed &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = object.getRawBits();
    return (*this);
}
