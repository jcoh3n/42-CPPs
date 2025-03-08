#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>


template <typename T>
class Array 
{
private:
    T *array;
    unsigned int size;
public:
    Array() : array(NULL), size(0) {}
    Array(unsigned int n) : array(new T[n]), size(n) {}
    Array(const Array &other) : array(new T[other.size]), size(other.size) {
        for (unsigned int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }
    ~Array() {
        delete[] array;
    }
    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }
        delete[] array;
        array = new T[other.size];
        size = other.size;
        for (unsigned int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
        return *this;
    }
    T &operator[](unsigned int i) {
        if (i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[i];
    }
    unsigned int size() const {
        return size;
    }
};


#endif 