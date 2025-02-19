/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:01:38 by j                 #+#    #+#             */
/*   Updated: 2025/02/19 13:09:10 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl Harl;
    std::string level;
    while (1)
    {
        std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR) or Q to quit: ";
        std::cin >> level;
        if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR" && level != "Q")
        {
            std::cout << "Invalid input" << std::endl;
            continue;
        }
        if (level == "Q")
            break;
        Harl.complain(level);
    }
    std::cout << "Exiting..." << std::endl;
    return (0);
}
