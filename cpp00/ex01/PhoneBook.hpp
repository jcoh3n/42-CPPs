/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:06 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/03 15:41:11 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;
public:
    PhoneBook();
    ~PhoneBook();
    // SETTERS
    void setContactCount(int contactCount);
    // GETTERS
    int getContactCount();
    void addContact(Contact contact);
    void displayContacts();
    void displayContact(int index);
    
};

#endif