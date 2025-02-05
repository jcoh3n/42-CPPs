/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:43:39 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/05 21:53:49 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

std::string getValidInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
    }
}

int main(int argc, char **argv)
{
    PhoneBook phoneBook;
    std::string command;
    if (argc > 1)
    {
        std::cout << "Usage: " << argv[0] << std::endl;
        return 1;
    }
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            Contact contact;
            std::string input;
            contact.setFirstName(getValidInput("Enter first name: "));
            contact.setLastName(getValidInput("Enter last name: "));
            contact.setNickname(getValidInput("Enter nickname: "));
            contact.setPhoneNumber(getValidInput("Enter phone number: "));
            contact.setDarkestSecret(getValidInput("Enter darkest secret: "));
            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();

            std::cout << "Enter index of contact to display: ";
            std::getline(std::cin, command);
            int index;
            std::istringstream iss(command);
            if (!(iss >> index))
            {
                std::cout << "Error: Invalid input. Please enter a number." << std::endl;
                continue;
            }
            if (index < 0 || index >= phoneBook.getContactCount())
            {
                std::cout << "Error: Index out of range. Please enter a number between 0 and "
                        << phoneBook.getContactCount() - 1 << "." << std::endl;
                continue;
            }
            phoneBook.displayContact(index);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "INVALID COMMAND"<< std::endl;
        }
    }

    return 0;
}