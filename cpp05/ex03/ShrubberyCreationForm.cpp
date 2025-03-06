#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
        throw FileOpenException();
    if (file.fail())
        throw FileOpenException();

    file << "     ccee88oo" << std::endl;
    file << "  C8O8O8Q8PoOb o8oo" << std::endl;
    file << " dOB69QO8PdUOpugoO9bD" << std::endl;
    file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    file << "    6OuU  /p u gcoUodpP" << std::endl;
    file << "      \\\\\\//  /douUP" << std::endl;
    file << "        \\\\\\////" << std::endl;
    file << "         |||/\\" << std::endl;
    file << "         |||\\/" << std::endl;
    file << "         |||||" << std::endl;
    file << "   .....//||||\\...." << std::endl;
    
    file.close();
    std::cout << "Shrubbery has been created in " << target + "_shrubbery" << std::endl;
}


const char *ShrubberyCreationForm::FileOpenException::what() const throw() { return "Failed to open file!"; }
