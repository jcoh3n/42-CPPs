#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array 
{
private:
    T *array;
    unsigned int arraySize;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    T &operator[](unsigned int i);
    ~Array();
    unsigned int size() const;
};

#include "Array.tpp"

#endif