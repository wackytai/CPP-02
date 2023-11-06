#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed( const Fixed &object );
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        Fixed&  operator= ( const Fixed &object );
};

#endif