/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:46:24 by j                 #+#    #+#             */
/*   Updated: 2025/02/19 14:31:25 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string readFile(std::ifstream &file)
{
    std::string content;
    std::string line;
    while (std::getline(file, line)) // getline ne prend pas en compte le '\n'
    {
        content += line;
        if (!content.empty()) // ajout d'un '\n' si la ligne n'est pas vide
            content += '\n';
    }
    return (content);
}

std::string findReplace(std::string content, std::string s1, std::string s2)
{
    std::string result;
    size_t pos = 0;
    size_t pos_found;
    // std::string::spos valeur quelconque en gros une valeur impossible -1
    while ((pos_found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, pos_found - pos); // on ajoute le contenu avant la chaine a remplacer
        result += s2;                                   // on ajoute la nouvelle chaine
        pos = pos_found + s1.length();                  // on avance de la taille de la chaine a remplacer
    }
    result += content.substr(pos); // on ajoute le reste de la chaine
    return (result);
}
