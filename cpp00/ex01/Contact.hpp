/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:07 by jcohen            #+#    #+#             */
/*   Updated: 2025/02/03 15:21:28 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

// Cette classe représente un contact individuel
// Elle doit stocker les informations suivantes en privé :

//     Prénom(first name)
//     Nom(last name)
//     Surnom(nickname)
//     Numéro de téléphone
//     Secret le plus sombre(darkest secret)

// Elle doit avoir des méthodes pour accéder et modifier ces informations

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();  // Constructeur
    ~Contact(); // Destructeur

    // LES SETTERS
    // 1 setter par attribut privé
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);

    // LES GETTERS
    // 1 getter par attribut privé
    
};

#endif