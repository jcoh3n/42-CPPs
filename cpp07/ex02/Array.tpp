#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arraySize(0) {}

template <typename T>
// T[n]() - Les parentheses init les valeurs à 0, "" 
Array<T>::Array(unsigned int n) : array(new T[n]()), arraySize(n) {}

template <typename T>
Array<T>::Array(const Array &other) : array(new T[other.arraySize]), arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) // Avoid self-assignment
    {
        T *temp = new T[other.arraySize];
        for (unsigned int i = 0; i < other.arraySize; i++) {
            temp[i] = other.array[i];
        }
        delete[] array;
        array = temp;
        arraySize = other.arraySize;
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
unsigned int Array<T>::size() const {
    return arraySize;
}