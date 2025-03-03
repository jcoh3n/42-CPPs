#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



Intern::Intern() { std::cout << "Intern default constructor" << std::endl; }

Intern::Intern(Intern const &src)
{
    std::cout << "Intern copy constructor" << std::endl;
    *this = src;
}

Intern &Intern::operator=(Intern const &src)
{
    std::cout << "Intern operator=" << std::endl;
    if (this != &src)
        *this = src;
    return *this;
}

Intern::~Intern() { std::cout << "Intern destructor" << std::endl; }

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    // Tableau de pointeurs sur fonctions membres de la classe Intern
    if (formName.empty())
    {
        std::cout << "Intern cannot create form: form name is empty" << std::endl;
        throw FormNotFoundException();
    }
    if (target.empty())
    {
        std::cout << "Intern cannot create " << formName << ": target is empty" << std::endl;
        throw FormNotFoundException();
    }
    AForm *(Intern::*formCreators[3])(std::string) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std ::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << ": form name not recognized" << std::endl; 
    throw FormNotFoundException();
    return (NULL);
}

const char *Intern::FormNotFoundException::what() const throw() { return "Form not found"; }