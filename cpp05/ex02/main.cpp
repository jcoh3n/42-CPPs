#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testBureaucratCreation() {
    std::cout << "\n=== Testing Bureaucrat Creation ===\n" << std::endl;
    
    try {
        std::cout << "Creating bureaucrat with valid grade (42):" << std::endl;
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nCreating bureaucrat with too high grade (0):" << std::endl;
        Bureaucrat john("John", 0);
        std::cout << john << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nCreating bureaucrat with too low grade (151):" << std::endl;
        Bureaucrat alice("Alice", 151);
        std::cout << alice << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTesting increment/decrement:" << std::endl;
        Bureaucrat dave("Dave", 5);
        std::cout << "Initial: " << dave << std::endl;
        
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
        
        dave.decrementGrade();
        std::cout << "After decrement: " << dave << std::endl;
        
        // Test incrementing beyond the limit
        Bureaucrat maxGrade("Max", 1);
        std::cout << "Max grade bureaucrat: " << maxGrade << std::endl;
        std::cout << "Trying to increment beyond limit:" << std::endl;
        maxGrade.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testShrubberyForm() {
    std::cout << "\n=== Testing ShrubberyCreationForm ===\n" << std::endl;
    
    try {
        // Create form and bureaucrats with different grades
        ShrubberyCreationForm form("garden");
        Bureaucrat highRank("Director", 1);
        Bureaucrat midRank("Manager", 100);
        Bureaucrat lowRank("Intern", 145);
        Bureaucrat tooLowRank("Visitor", 146);
        
        std::cout << form << std::endl;
        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << tooLowRank << std::endl;
        
        // Test signing permissions
        std::cout << "\nTesting signing permissions:" << std::endl;
        tooLowRank.signForm(form);  // Should fail (grade too low)
        lowRank.signForm(form);     // Should succeed (just enough grade)
        
        // Test execution permissions
        std::cout << "\nTesting execution permissions:" << std::endl;
        tooLowRank.executeForm(form);  // Should fail (grade too low)
        midRank.executeForm(form);     // Should succeed
        highRank.executeForm(form);    // Should succeed
        
    } catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
}

void testRobotomyForm() {
    std::cout << "\n=== Testing RobotomyRequestForm ===\n" << std::endl;
    
    try {
        // Create form and bureaucrats with different grades
        RobotomyRequestForm form("Bender");
        Bureaucrat highRank("CEO", 1);
        Bureaucrat midRank("Assistant", 45);
        Bureaucrat lowRank("Secretary", 72);
        Bureaucrat tooLowRank("Temp", 73);
        
        std::cout << form << std::endl;
        
        // Test signing permissions
        std::cout << "\nTesting signing permissions:" << std::endl;
        tooLowRank.signForm(form);  // Should fail (grade too low)
        lowRank.signForm(form);     // Should succeed (just enough grade)
        
        // Test execution permissions
        std::cout << "\nTesting execution permissions:" << std::endl;
        lowRank.executeForm(form);  // Should fail (grade too low for execution)
        midRank.executeForm(form);  // Should succeed
        highRank.executeForm(form); // Should succeed
        
        // Try multiple robotomies to see randomness
        std::cout << "\nMultiple robotomy attempts:" << std::endl;
        RobotomyRequestForm form2("C3PO");
        highRank.signForm(form2);
        for (int i = 0; i < 5; i++) {
            highRank.executeForm(form2);
        }
        
    } catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n=== Testing PresidentialPardonForm ===\n" << std::endl;
    
    try {
        // Create form and bureaucrats with different grades
        PresidentialPardonForm form("Arthur Dent");
        Bureaucrat president("President", 1);
        Bureaucrat vicePresident("Vice President", 5);
        Bureaucrat secretary("Secretary", 25);
        Bureaucrat tooLowRank("Citizen", 26);
        
        std::cout << form << std::endl;
        
        // Test signing permissions
        std::cout << "\nTesting signing permissions:" << std::endl;
        tooLowRank.signForm(form);  // Should fail (grade too low)
        secretary.signForm(form);   // Should succeed (just enough grade)
        
        // Test execution permissions
        std::cout << "\nTesting execution permissions:" << std::endl;
        secretary.executeForm(form);  // Should fail (grade too low for execution)
        vicePresident.executeForm(form);  // Should succeed
        president.executeForm(form);      // Should succeed
        
    } catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
}

void testUnsignedFormExecution() {
    std::cout << "\n=== Testing Execution of Unsigned Forms ===\n" << std::endl;
    
    try {
        // Create forms and high-level bureaucrat
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("R2D2");
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat president("President", 1);
        
        // Try executing without signing
        std::cout << "Attempting to execute unsigned forms:" << std::endl;
        president.executeForm(shrub);
        president.executeForm(robot);
        president.executeForm(pardon);
        
    } catch (std::exception &e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
}

void testGradeLimitsEdgeCases() {
    std::cout << "\n=== Testing Edge Cases ===\n" << std::endl;
    
    try {
        // Create bureaucrats at grade boundaries
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
        
        // Test limitations
        std::cout << "\nTrying to increment highest grade bureaucrat:" << std::endl;
        highest.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat lowest("Lowest", 150);
        std::cout << "\nTrying to decrement lowest grade bureaucrat:" << std::endl;
        lowest.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // Seed random for robotomy
    srand(time(NULL));
    
    // Run all tests
    testBureaucratCreation();
    testShrubberyForm();
    testRobotomyForm();
    testPresidentialPardonForm();
    testUnsignedFormExecution();
    testGradeLimitsEdgeCases();
    
    return 0;
}