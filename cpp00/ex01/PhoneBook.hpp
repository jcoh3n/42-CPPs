/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:06 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/05 21:28:12 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> // Pour std::setw
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8]; // Tableau de 8 contacts
    int contactCount;    // Nombre de contacts actuellement enregistrés

public:
    PhoneBook();
    ~PhoneBook();

    // Méthodes
    void addContact(Contact contact);
    void displayContacts();
    void displayContact(int index);
    int getContactCount();
};

#endif