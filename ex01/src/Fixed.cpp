#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _scale = 1 << _bits;
}

Fixed::Fixed( const Fixed &object )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::Fixed( const int number )
{
    std::cout << "Int constructor called" << std::endl;
    _scale = 1 << _bits;
    setRawBits( number * _scale );
}

Fixed::Fixed ( const float number )
{
    std::cout << "Float constructor called" << std::endl;
    _scale = 1 << _bits;
    setRawBits( roundf( number * _scale ) );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return ( _value );
}

void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float   Fixed::toFloat ( void ) const
{
    return ( _value / _scale );
}

int     Fixed::toInt ( void ) const
{
    return ( _value / _scale );
}

Fixed&  Fixed::operator= ( const Fixed &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = object.getRawBits();
    _scale = object._scale;
    return ( *this );
}

std::ostream    &operator<< ( std::ostream &out, const Fixed &object )
{
    out << object.toFloat();
    return ( out );
}
