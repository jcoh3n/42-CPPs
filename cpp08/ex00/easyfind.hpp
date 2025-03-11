#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &type_container, int n)
{
    typename T::iterator it = std::find(type_container.begin(), type_container.end(), n);
    if (it == type_container.end())
        throw std::exception(); // Utilisation de std::exception
    return it;
}

#endif