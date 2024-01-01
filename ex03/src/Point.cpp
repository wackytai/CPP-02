#include "../inc/Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point ( const Point &object ) : _x(object.getX()), _y(object.getY())
{
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
    std::cout << "Custom constructor called" << std::endl;
}

Point::~Point()
{
    std::cout << "Default destructor called" << std::endl;
}

Fixed Point::getX( void ) const
{
    return ( _x );
}

Fixed Point::getY( void ) const
{
    return ( _y );
}

Point&  Point::operator= ( const Point &object )
{
    std::cout << "Copy assignment operator called" << std::endl;
    (void)object;
    return ( *this );
}
