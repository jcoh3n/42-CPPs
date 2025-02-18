/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:46:24 by j                 #+#    #+#             */
/*   Updated: 2025/02/18 15:54:24 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string readFile(std::ifstream &file)
{
    std::string content;
    std::string line;
    while (std::getline(file, line))
    {
        content += line;
        if (!file.eof())
            content += '\n';
    }
    return (content);
}

std::string findReplace(std::string content, std::string s1, std::string s2)
{
    std::string result;
    size_t pos = 0;
    size_t pos_found;
    while ((pos_found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, pos_found - pos);
        result += s2;
        pos = pos_found + s1.length();
    }
    result += content.substr(pos);
    return (result);
}
