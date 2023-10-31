#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:

    public:
        Fixed();
        Fixed   Fixed( Fixed &f );
        ~Fixed();
        void    getRawBits( void );
}


#endif