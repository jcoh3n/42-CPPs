#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


template <typename T, typename Function>
void iter(T *array, int length, Function function) {
    if (length <= 0) {
        return;
    }
    for (int i = 0; i < length; i++) {
        function(array[i]);
    }
}

template <typename T>
void printElement(const T &element) {
    std::cout << element << std::endl;
}

template <typename T>
struct Multiply {
    int factor;
    Multiply(int factor) : factor(factor) {}
    void operator()(T &element) {
        element *= factor;
    }
};

template <typename T>
void isEven(const T &element) {
    if (element % 2 == 0) {
        std::cout << element << " is even" << std::endl;
    } else {
        std::cout << element << " is odd" << std::endl;
    }
}

#endif