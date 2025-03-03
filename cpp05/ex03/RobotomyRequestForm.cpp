#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm destructor called" << std::endl; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "* drilling noises *";
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " robotomization failed" << std::endl;
}


