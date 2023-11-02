#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
    _bits = 8;
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed( const Fixed &object )
{
    std::cout << "Copy Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;
}

void    Fixed::getRawBits( void )
{}

void    Fixed::setRawBits( int const raw )
{}
