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
    if (formName.empty() || target.empty())
    {
        std::cout << "Intern cannot create form: empty parameters" << std::endl;
        throw FormNotFoundException();
    }

    std::string lowerFormName = formName;
    for (size_t i = 0; i < lowerFormName.length(); i++)
    {
        if (lowerFormName[i] == ' ')
            continue;
        lowerFormName[i] = std::tolower(lowerFormName[i]);
    }
        

    // Tableau de pointeurs de fonctions membres de la classe Intern
    AForm *(Intern::*formCreators[3])(std::string) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    for (int i = 0; i < 3; i++)
    {
        if (lowerFormName == formNames[i])
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