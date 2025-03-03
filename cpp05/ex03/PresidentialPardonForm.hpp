#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat; // Forward declaration if needed

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