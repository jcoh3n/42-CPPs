/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:04 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/05 21:40:06 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructeur
PhoneBook::PhoneBook()
{
    this->contactCount = 0;
}

// Destructeur
PhoneBook::~PhoneBook() {}

int PhoneBook::getContactCount()
{
    return this->contactCount;
}

// Ajouter un contact
void PhoneBook::addContact(Contact contact)
{
    if (this->contactCount < 8)
    {
        this->contacts[this->contactCount] = contact;
        this->contactCount++;
    }
    else
    {
        this->contacts[0] = contact;
    }
}

// Fonction utilitaire pour tronquer une chaîne
std::string truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width - 1) + ".";
    return str;
}

// Afficher la liste des contacts
void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < this->contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(this->contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getNickname(), 10) << std::endl;
    }
}

// Afficher les détails d'un contact
void PhoneBook::displayContact(int index)
{
    if (index >= 0 && index < this->contactCount)
    {
        std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cout << "Error: Invalid index. Please enter a number between 0 and " << this->contactCount - 1 << "." << std::endl;
    }
}
