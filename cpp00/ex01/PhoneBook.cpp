/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:04 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/06 18:31:43 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructeur
PhoneBook::PhoneBook()
{
    this->contactCount = 0;
    this->oldestIndex = 0;
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
        this->contacts[this->oldestIndex] = contact;
        this->oldestIndex = (this->oldestIndex + 1) % 8;
    }
}

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

// Afficher un contact 
void PhoneBook::displayContact(int index)
{
    if (index >= 0 && index < this->contactCount)
    {
        std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << this->contacts[index].getFirstName() << "|"
                  << std::setw(10) << this->contacts[index].getLastName() << "|"
                  << std::setw(10) << this->contacts[index].getNickname() << std::endl;
    }
    else
    {
        std::cout << "Error: Invalid index. Please enter a number between 0 and " << this->contactCount - 1 << "." << std::endl;
    }
}
