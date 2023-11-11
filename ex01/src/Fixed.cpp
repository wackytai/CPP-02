#include "../inc/Fixed.hpp"

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
    _scale = 1 << _bits;
    setRawBits(toFixed( number ));
}

Fixed::Fixed ( const float number )
{
    std::cout << "Float constructor called" << std::endl;
    _scale = 1 << _bits;
    setRawBits( toFixed( number ) );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    return (_value);
}

void    Fixed::setRawBits( int const raw )
{
    _value = raw;
}

float   Fixed::toFloat ( void ) const
{
    float   f;

    f = roundf(static_cast<float>(_value) / static_cast<float>(_scale));
    return (f);
}

int     Fixed::toInt ( void ) const
{
    float f;

    f = roundf(static_cast<float>(_value) / _scale);
    return (static_cast<int>(f));
}

int     Fixed::toFixed ( int const i )
{
    //missing things
    return (i * _scale);
}

int     Fixed::toFixed ( float const i )
{
    return (static_cast<int>(roundf(i *_scale)));
}

Fixed&  Fixed::operator= ( const Fixed &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = object.getRawBits();
    return (*this);
}

std::ostream&    operator<< (std::ostream& out, const Fixed &object )
{
    out << object.toFloat();
    return out;
}
