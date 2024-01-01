#include "../inc/Fixed.hpp"

int main()
{
    Point a(0, 0);
    Point b(-1, -1);
    Point c(1, -1);

    triarea(a, b, c);
    bsp();
}

Fixed   triarea( const Point a, const Point b, const Point c)
{
    Fixed   rect_x((Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()).getRawBits()) - (Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX()).getRawBits()));
    Fixed   rect_y((Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()).getRawBits()) - (Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY()).getRawBits()));

    return ((rect_x * rect_y) / 2 );
}