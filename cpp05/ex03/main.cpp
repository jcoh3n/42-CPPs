#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <string>

// Fonction helper pour afficher les titres de section
void displayTitle(const std::string& title) {
    std::cout << "\n=====================================\n"
              << "=== " << title << " ===\n"
              << "=====================================\n" << std::endl;
}

// Test de la création des bureaucrates
void testBureaucratCreation() {
    displayTitle("Test de création des bureaucrates");
    
    try {
        std::cout << "Création d'un bureaucrate avec un grade valide (42):" << std::endl;
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nCréation d'un bureaucrate avec un grade trop élevé (0):" << std::endl;
        Bureaucrat john("John", 0);
        std::cout << john << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nCréation d'un bureaucrate avec un grade trop bas (151):" << std::endl;
        Bureaucrat alice("Alice", 151);
        std::cout << alice << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
}

// Test de l'Intern qui crée des formulaires
void testInternFormCreation() {
    displayTitle("Test de création de formulaires par l'Intern");
    
    Intern intern;
    AForm* form = NULL;
    
    // Test de création d'un formulaire ShrubberyCreation
    try {
        std::cout << "Création d'un formulaire ShrubberyCreation:" << std::endl;
        form = intern.makeForm("shrubbery creation", "jardin");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
            form = NULL;
        }
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }
    
    // Test de création d'un formulaire RobotomyRequest
    try {
        std::cout << "\nCréation d'un formulaire RobotomyRequest:" << std::endl;
        form = intern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    }
    
    // Test de création d'un formulaire PresidentialPardon
    try {
        std::cout << "\nCréation d'un formulaire PresidentialPardon:" << std::endl;
        form = intern.makeForm("presidential pardon", "Zaphod");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    }
    
    // Test de création d'un formulaire inexistant
    try {
        std::cout << "\nTentative de création d'un formulaire inexistant:" << std::endl;
        form = intern.makeForm("unknown form", "target");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL; // Changed nullptr to NULL
        }
    }
}

// Test du cycle complet: création, signature et exécution des formulaires
void testFormWorkflow() {
    displayTitle("Test du cycle complet des formulaires");
    
    Intern intern;
    Bureaucrat boss("Le PDG", 1);              // Peut tout faire
    Bureaucrat manager("Le Manager", 45);      // Peut signer tous les formulaires, mais exécuter seulement Robotomy et Shrubbery
    Bureaucrat employee("L'Employé", 140);     // Peut signer seulement Shrubbery

    std::cout << boss << std::endl;
    std::cout << manager << std::endl;
    std::cout << employee << std::endl;
    
    // Test ShrubberyCreationForm
    try {
        std::cout << "\n--- Test ShrubberyCreationForm ---" << std::endl;
        AForm* shrubForm = intern.makeForm("shrubbery creation", "maison");
        
        // Tentative de signature par différents bureaucrates
        employee.signForm(*shrubForm);
        
        // Tentative d'exécution par différents bureaucrates
        employee.executeForm(*shrubForm);
        manager.executeForm(*shrubForm);
        boss.executeForm(*shrubForm);
        
        delete shrubForm;
    } catch (std::exception &e) {
        std::cout << "Erreur inattendue: " << e.what() << std::endl;
    }
    
    // Test RobotomyRequestForm
    try {
        std::cout << "\n--- Test RobotomyRequestForm ---" << std::endl;
        AForm* robotForm = intern.makeForm("robotomy request", "C3PO");
        
        // Tentative de signature par différents bureaucrates
        employee.signForm(*robotForm);  // Devrait échouer
        manager.signForm(*robotForm);   // Devrait réussir
        
        // Tentative d'exécution par différents bureaucrates
        employee.executeForm(*robotForm);  // Devrait échouer
        manager.executeForm(*robotForm);   // Devrait réussir
        
        delete robotForm;
    } catch (std::exception &e) {
        std::cout << "Erreur inattendue: " << e.what() << std::endl;
    }
    
    // Test PresidentialPardonForm
    try {
        std::cout << "\n--- Test PresidentialPardonForm ---" << std::endl;
        AForm* pardonForm = intern.makeForm("presidential pardon", "Arthur Dent");
        
        // Tentative de signature par différents bureaucrates
        employee.signForm(*pardonForm);  // Devrait échouer
        manager.signForm(*pardonForm);   // Devrait échouer
        boss.signForm(*pardonForm);      // Devrait réussir
        
        // Tentative d'exécution par différents bureaucrates
        employee.executeForm(*pardonForm);  // Devrait échouer
        manager.executeForm(*pardonForm);   // Devrait échouer
        boss.executeForm(*pardonForm);      // Devrait réussir
        
        delete pardonForm;
    } catch (std::exception &e) {
        std::cout << "Erreur inattendue: " << e.what() << std::endl;
    }
}

// Test des cas d'erreur spécifiques
void testEdgeCases() {
    displayTitle("Test des cas particuliers");
    
    Intern intern;
    Bureaucrat boss("Le PDG", 1);
    
    // Tentative d'exécution d'un formulaire non signé
    try {
        std::cout << "Tentative d'exécution d'un formulaire non signé:" << std::endl;
        AForm* form = intern.makeForm("presidential pardon", "Ford Prefect");
        boss.executeForm(*form);  // Devrait échouer car non signé
        delete form;
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test de sensibilité à la casse et aux espaces
    try {
        std::cout << "\nTest de sensibilité à la casse et aux espaces:" << std::endl;
        AForm* form1 = intern.makeForm("ROBOTOMY REQUEST", "R2D2");  // Majuscules
        if (form1) {
            std::cout << "Formulaire créé malgré les majuscules!" << std::endl;
            delete form1;
        }
    } catch (std::exception &e) {
        std::cout << "Erreur (attendue): " << e.what() << std::endl;
    }
    
    try {
        AForm* form2 = intern.makeForm("   shrubbery creation   ", "parc");  // Espaces supplémentaires
        if (form2) {
            std::cout << "Formulaire créé malgré les espaces supplémentaires!" << std::endl;
            delete form2;
        }
    } catch (std::exception &e) {
        std::cout << "Erreur (attendue): " << e.what() << std::endl;
    }
    
    // Test avec une cible vide
    try {
        std::cout << "\nTest avec une cible vide:" << std::endl;
        AForm* form = intern.makeForm("presidential pardon", "");
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }
    } catch (std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
}

int main() {
    srand(time(NULL));
    
    testBureaucratCreation();
    testInternFormCreation();
    testFormWorkflow();
    testEdgeCases();
    
    return 0;
}