#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        // Test 1 : Création d'un bureaucrate et d'un formulaire valides
        std::cout << "\n--- Test 1 : Création d'un bureaucrate et d'un formulaire valides ---" << std::endl;
        Bureaucrat bureaucrat("Alice", 50);
        Form form("Formulaire A", 75, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        // Test 2 : Le bureaucrate signe le formulaire
        std::cout << "\n--- Test 2 : Le bureaucrate signe le formulaire ---" << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        // Test 3 : Création d'un formulaire avec un grade trop haut
        std::cout << "\n--- Test 3 : Création d'un formulaire avec un grade trop haut ---" << std::endl;
        Form invalidForm("Formulaire Invalide", 0, 50);
    }
    catch (const Bureaucrat::BureaucratGradeTooHighException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::BureaucratGradeTooLowException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    catch (const Form::FormGradeTooHighException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    catch (const Form::FormGradeTooLowException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        // Test 4 : Création d'un formulaire avec un grade trop bas
        std::cout << "\n--- Test 4 : Création d'un formulaire avec un grade trop bas ---" << std::endl;
        Form invalidForm("Formulaire Invalide", 151, 50);
    }
    catch (const Form::FormGradeTooHighException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    catch (const Form::FormGradeTooLowException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try
    {
        // Test 5 : Un bureaucrate avec un grade insuffisant tente de signer un formulaire
        std::cout << "\n--- Test 5 : Un bureaucrate avec un grade insuffisant tente de signer un formulaire ---" << std::endl;
        Bureaucrat bureaucrat("Bob", 100);
        Form form("Formulaire B", 75, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
    }
    catch (const Form::FormGradeTooLowException &e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}