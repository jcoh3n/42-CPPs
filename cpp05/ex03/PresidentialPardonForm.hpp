#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};

#endif