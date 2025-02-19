/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:57:26 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/19 15:25:25 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
private:
    int value;
    static const int bits = 8;
public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif