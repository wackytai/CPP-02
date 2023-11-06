#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _value;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed( const Fixed &object );
        Fixed( const int number );
        Fixed ( const float number );
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat ( void ) const;
        int     toInt ( void ) const;
        Fixed&  operator= ( const Fixed &object );
        void    operator<< ( const float number ); 
};


#endif