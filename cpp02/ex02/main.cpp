/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:57:48 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/21 15:45:41 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // std::cout << "\nTESTS en plus" << std::endl;
    // Fixed c(42.42f);
    // Fixed d(21.21f);

    // std::cout << "c = " << c << std::endl;
    // std::cout << "d = " << d << std::endl;
    // std::cout << "c + d = " << c + d << std::endl;
    // std::cout << "c - d = " << c - d << std::endl;
    // std::cout << "c * d = " << c * d << std::endl;
    // std::cout << "c / d = " << c / d << std::endl;

    // std::cout << "\nComparaisons" << std::endl;
    // std::cout << "c > d = " << (c > d) << std::endl;
    // std::cout << "c < d = " << (c < d) << std::endl;
    // std::cout << "c >= d = " << (c >= d) << std::endl;
    // std::cout << "c <= d = " << (c <= d) << std::endl;
    // std::cout << "c == d = " << (c == d) << std::endl;
    // std::cout << "c != d = " << (c != d) << std::endl;

    // std::cout << "\nIncrementations et decrementations" << std::endl;
    // std::cout << "c = " << c << std::endl;
    // std::cout << "c++ = " << c++ << std::endl;
    // std::cout << "c = " << c << std::endl;
    // std::cout << "++c = " << ++c << std::endl;
    // std::cout << "c-- = " << c-- << std::endl;
    // std::cout << "c = " << c << std::endl;
    // std::cout << "--c = " << --c << std::endl;

    // std::cout << "\nmin et max" << std::endl;
    // std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
    // std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl;

    return (0);
};