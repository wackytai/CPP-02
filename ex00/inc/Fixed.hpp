#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _bits;

    public:
        Fixed();
        Fixed( const Fixed &object );
        ~Fixed();
        void    getRawBits( void );
        void    setRawBits( int const raw );
}


#endif