/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:02:09 by j                 #+#    #+#             */
/*   Updated: 2025/02/19 13:40:35 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
}

void Harl::complain(std::string level) {

    // Tableau de pointeurs où chaque case pointe vers une fonction de la classe Harl
    void (Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // Tableau avec les messages de log
    int index = 0;

    // But: Recuperer l'index du message dans le tableau
   switch (level == "DEBUG" ? 0 : level == "INFO" ? 1 : level == "WARNING" ? 2 : level == "ERROR" ? 3 : -1)
   {
    case 0: index = 0; break;
    case 1: index = 1; break;
    case 2: index = 2; break;
    case 3: index = 3; break;
    default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; return;
   }
   for (int i = index; i < 4; i++)
      (this->*function[i])(); // Appelle de la fonction en fonction du message
}


