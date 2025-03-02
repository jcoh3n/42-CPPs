#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 130);
        ShrubberyCreationForm shrubberyForm("home");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
