#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &object )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::Fixed( const int number )
{
    std::cout << "Int constructor called" << std::endl;
    _value = setRawBits(number);
}

Fixed::Fixed ( const float number )
{
    std::cout << "Float constructor called" << std::endl;
    _value = setRawBits( number );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return (_value);
}

float   Fixed::getRawBits( void ) const
{
    return (_value);
}

void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

void    Fixed::setRawBits( float const raw )
{
    _value = raw;
}

float   Fixed::toFloat ( void ) const
{

}

int     Fixed::toInt ( void ) const
{

}

Fixed&  Fixed::operator= ( const Fixed &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = object.getRawBits();
    return (*this);
}

void    Fixed::operator<< ( const float number )
{

}
