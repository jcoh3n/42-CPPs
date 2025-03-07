#include "ABC.hpp"
#include <iostream>

A::A() { std::cout << "A constructor called" << std::endl; }
B::B() { std::cout << "B constructor called" << std::endl; }
C::C() { std::cout << "C constructor called" << std::endl; }

A::~A() { std::cout << "A destructor called" << std::endl; }
B::~B() { std::cout << "B destructor called" << std::endl; }
C::~C() { std::cout << "C destructor called" << std::endl; }