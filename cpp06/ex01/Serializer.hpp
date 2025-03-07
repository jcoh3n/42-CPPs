#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdint.h> // uintptr_t

class Data {
private:
    std::string _name_user;
    int _age_user;
    double _solde_user;
public:
    Data(std::string name, int age, int solde) : _name_user(name), _age_user(age), _solde_user(solde) {};
    ~Data() {};
    void get_name() const { std::cout << _name_user << std::endl; };
    void get_age() const { std::cout << _age_user << std::endl; };
    void get_solde() const { std::cout << _solde_user << std::endl; };
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