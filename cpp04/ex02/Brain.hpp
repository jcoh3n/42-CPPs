#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain &copy);
    Brain &operator=(const Brain &brain);
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};


#endif