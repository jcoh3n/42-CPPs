/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:04 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/03 15:41:21 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setContactCount(int contactCount)
{
    this->contactCount = contactCount;
}

int PhoneBook::getContactCount()
{
    return (this->contactCount);
}

void PhoneBook::addContact(Contact contact)
{
    if (this->contactCount < 8)
    {
        Contact contact;
        std::string input;

        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        contact.setFirstName(input);

        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        contact.setLastName(input);

        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        contact.setNickname(input);

        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        contact.setPhoneNumber(input);

        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        contact.setDarkestSecret(input);

        this->contacts[this->contactCount] = contact;
        this->contactCount++;
    }
    else
    {
        std::cout << "Phone book is full" << std::endl;
    }
}
