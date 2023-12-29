#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _value;
        float               _scale;
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
        bool    operator> ( const Fixed &object ) const;
        bool    operator>= ( const Fixed &object ) const;
        bool    operator< ( const Fixed &object ) const;
        bool    operator<= ( const Fixed &object ) const;
        bool    operator!= ( const Fixed &object ) const;
        bool    operator== ( const Fixed &object ) const;
        Fixed   operator+ ( const Fixed &object );
        Fixed   operator- ( const Fixed &object );
        Fixed   operator* ( const Fixed &object );
        Fixed   operator/ ( const Fixed &object );
        Fixed   operator++ ( void );
        Fixed   operator-- ( void );
        Fixed   operator++ ( int i );
        Fixed   operator-- ( int i );
        static const Fixed&   min(const Fixed &nb1, const Fixed &nb2);
        static const Fixed&   max(const Fixed &nb1, const Fixed &nb2);
        static Fixed&   min(Fixed &nb1, Fixed &nb2);
        static Fixed&   max(Fixed &nb1, Fixed &nb2);
};

std::ostream    &operator<< ( std::ostream &out, const Fixed &object );

#endif