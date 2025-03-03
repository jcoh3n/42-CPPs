#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm destructor called" << std::endl; }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
