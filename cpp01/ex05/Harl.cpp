/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:02:09 by j                 #+#    #+#             */
/*   Updated: 2025/02/19 13:07:54 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "DEBUG MESSAGE" << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO MESSAGE" << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING MESSAGE" << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR MESSAGE" << std::endl;
}

void Harl::complain(std::string level) {

    // Tableau de pointeurs où chaque case pointe vers une fonction de la classe Harl
    void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // Tableau avec les messages de log

    // On boucle sur les types de messages
    for (int i = 0; i < 4; i++)
    {
        // Si message trouvé
        if (levels[i] == level)
            (this->*function[i])(); // Appelle de la fonction en fonction du message
    }
}

