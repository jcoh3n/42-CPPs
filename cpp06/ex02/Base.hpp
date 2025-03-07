#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
public:
    virtual ~Base() {}

    // Méthodes statiques
    static Base* generate();
    static void identify(Base* p);
    static void identify(Base& p);
};

#endif