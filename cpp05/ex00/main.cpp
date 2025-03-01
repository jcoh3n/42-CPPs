#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        // Test 1 : Création d'un bureaucrate avec un grade valide
        std::cout << "--- Test 1 : Création d'un bureaucrate avec un grade valide ---" << std::endl;
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;  // Affiche : Alice, bureaucrat grade 2

        // Test 2 : Incrémenter le grade
        std::cout << "\n--- Test 2 : Incrémenter le grade ---" << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;  // Affiche : Alice, bureaucrat grade 1

        // Test 3 : Décrémenter le grade
        std::cout << "\n--- Test 3 : Décrémenter le grade ---" << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;  // Affiche : Alice, bureaucrat grade 2

        // Test 4 : Création d'un bureaucrate avec un grade invalide (trop haut)
        std::cout << "\n--- Test 4 : Création d'un bureaucrate avec un grade invalide (trop haut) ---" << std::endl;
        Bureaucrat b2("Bob", 0); // Cela va lever une exception GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    try
    {
        // Test 5 : Création d'un bureaucrate avec un grade invalide (trop bas)
        std::cout << "\n--- Test 5 : Création d'un bureaucrate avec un grade invalide (trop bas) ---" << std::endl;
        Bureaucrat b3("Charlie", 151); // Cela va lever une exception GradeTooLowException
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    try
    {
        // Test 6 : Incrémenter le grade jusqu'à la limite
        std::cout << "\n--- Test 6 : Incrémenter le grade jusqu'à la limite ---" << std::endl;
        Bureaucrat b4("David", 2);
        std::cout << b4 << std::endl;  // Affiche : David, bureaucrat grade 2
        b4.incrementGrade();
        std::cout << b4 << std::endl;  // Affiche : David, bureaucrat grade 1
        b4.incrementGrade(); // Cela va lever une exception GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    try
    {
        // Test 7 : Décrémenter le grade jusqu'à la limite
        std::cout << "\n--- Test 7 : Décrémenter le grade jusqu'à la limite ---" << std::endl;
        Bureaucrat b5("Eve", 149);
        std::cout << b5 << std::endl;  // Affiche : Eve, bureaucrat grade 149
        b5.decrementGrade();
        std::cout << b5 << std::endl;  // Affiche : Eve, bureaucrat grade 150
        b5.decrementGrade(); // Cela va lever une exception GradeTooLowException
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    return 0;
}