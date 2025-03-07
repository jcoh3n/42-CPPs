#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdint.h> // Ajoute ceci pour le type uintptr_t

class Data {
public:
    std::string _name_user;
    int _age_user;
    double _solde_user;
};

class Serializer {

private:
    Serializer() {};
    ~Serializer() {};
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};




#endif 