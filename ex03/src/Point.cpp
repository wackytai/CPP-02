#include "../inc/Fixed.hpp"

Point::Point()
{
    std::cout << "Default constructor called" std::endl;
    _x = 0;
    _y = 0;
}

Point::Point ( const Point &object )
{
    std::cout << "Copy constructor called" std::endl;
    *this = object;
}

Point::Point( const float x, const float y )
{
    std::cout << "Custom constructor called" std::endl;
    _x = x;
    _y = y;
}

Point::~Point()
{
    std::cout << "Default destructor called" std::endl;
}

Point&  Point::operator= ( const Point &object )
{
    _x = object._x;
    _y = object._y;
    return ( this );
}
