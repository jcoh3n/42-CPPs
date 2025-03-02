#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;

    class ShrubberyCreationFormFileException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif