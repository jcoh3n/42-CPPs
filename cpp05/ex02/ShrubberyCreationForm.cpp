#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm destructor called" << std::endl; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSignedAForm())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::AFormGradeTooLowException();
    std::ofstream file(target + "_shrubbery");
    if (!file.is_open())
        throw ShrubberyCreationFormFileException();
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
    std::cout << "Shrubbery has been created in " << target + "_shrubbery" << std::endl;
}


const char *ShrubberyCreationForm::ShrubberyCreationFormFileException::what() const throw() { return "Cannot open file"; }
