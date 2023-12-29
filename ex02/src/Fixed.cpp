#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
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
    this->setRawBits( number * _scale );
}

Fixed::Fixed ( const float number )
{
    std::cout << "Float constructor called" << std::endl;
    _scale = 1 << _bits;
    this->setRawBits( roundf( number * _scale ) );
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

float   Fixed::toFloat( void ) const
{
    return ( _value / _scale );
}

int     Fixed::toInt ( void ) const
{
    return ( _value / _scale );
}

Fixed&  Fixed::operator=( const Fixed &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = object.getRawBits();
    _scale = object._scale;
    return ( *this );
}

bool   Fixed::operator>( const Fixed &object ) const
{
    return ( this->getRawBits() > object.getRawBits() ) ;
}

bool   Fixed::operator>=( const Fixed &object ) const
{
    return ( this->getRawBits() >= object.getRawBits() ) ;
}

bool   Fixed::operator<( const Fixed &object ) const
{
    return ( this->getRawBits() < object.getRawBits() ) ;
}

bool   Fixed::operator<=( const Fixed &object ) const
{
    return ( this->getRawBits() <= object.getRawBits() ) ;
}

bool   Fixed::operator!=( const Fixed &object ) const
{
    return ( this->getRawBits() != object.getRawBits() ) ;
}

bool   Fixed::operator==( const Fixed &object ) const
{
    return ( this->getRawBits() == object.getRawBits() ) ;
}

Fixed   Fixed::operator+( const Fixed &object )
{
    Fixed   temp( *this);

    temp.setRawBits(this->getRawBits() + object.getRawBits());
    return temp ;
}

Fixed   Fixed::operator-( const Fixed &object )
{
    Fixed   temp( *this );

    temp.setRawBits(this->getRawBits() - object.getRawBits());
    return ( temp );
}

Fixed   Fixed::operator*( const Fixed &object )
{
    Fixed   temp( *this );

    temp.setRawBits(((int64_t)this->getRawBits() * (int64_t)object.getRawBits()) / this->_scale);
    return ( temp );
}

Fixed   Fixed::operator/( const Fixed &object )
{
    Fixed   temp( *this );

    if ( object.getRawBits() )
        temp.setRawBits(((int64_t)this->getRawBits() * this->_scale) / (int64_t)object.getRawBits());
    return ( temp );
}

Fixed   Fixed::operator++( void )
{
    this->setRawBits(this->getRawBits() + 1);
    return ( *this );
}

Fixed   Fixed::operator++( int i )
{
    Fixed   temp( *this );

    (void)i;
    this->setRawBits(this->getRawBits() + 1);
    return ( temp );
}

Fixed   Fixed::operator--( void )
{
    this->setRawBits(this->getRawBits() - 1);
    return ( *this );
}

Fixed   Fixed::operator--( int i )
{
    Fixed   temp( *this );

    (void)i;
    this->setRawBits(this->getRawBits() - 1);
    return ( temp );
}

const Fixed&   Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
    return (nb1.getRawBits() < nb2.getRawBits()) ? nb1 : nb2;
}

const Fixed&   Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
    return (nb1.getRawBits() < nb2.getRawBits()) ? nb2 : nb1;
}

Fixed&   Fixed::min(Fixed &nb1, Fixed &nb2)
{
    return (nb1.getRawBits() < nb2.getRawBits()) ? nb1 : nb2;
}

Fixed&   Fixed::max(Fixed &nb1, Fixed &nb2)
{
    return (nb1.getRawBits() < nb2.getRawBits()) ? nb2 : nb1;
}

std::ostream    &operator<< ( std::ostream &out, const Fixed &object )
{
    out << object.toFloat();
    return ( out );
}
