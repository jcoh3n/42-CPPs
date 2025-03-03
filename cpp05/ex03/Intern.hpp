#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"



class Intern
{
public:
    Intern();
    Intern(Intern const &src);
    Intern &operator=(Intern const &src);
    ~Intern();

    AForm *createShrubberyCreationForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createPresidentialPardonForm(std::string target);
    AForm *makeForm(std::string formName, std::string target);

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

};

#endif