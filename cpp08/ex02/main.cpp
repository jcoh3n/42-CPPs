#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <string>

// Function to print a separator line for better readability
void printSeparator(const std::string &title) {
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

// Test basic operations
void testBasicOperations() {
    printSeparator("TEST BASIC OPERATIONS");
    
    MutantStack<int> mstack;
    
    std::cout << "Pushing 5 and 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    std::cout << "Popping top element" << std::endl;
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    std::cout << "Pushing 3, 5, 737, 231, 992, 6, 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(231);
    mstack.push(992);
    mstack.push(6);
    mstack.push(0);
    
    std::cout << "Final size: " << mstack.size() << std::endl;
}

// Test iteration capabilities
void testIteration() {
    printSeparator("TEST ITERATION");
    
    MutantStack<int> mstack;
    
    // Push some elements
    mstack.push(5);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(231);
    mstack.push(992);
    mstack.push(6);
    mstack.push(0);
    
    std::cout << "Iterating through MutantStack:" << std::endl;
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;    // Move to second element
    std::cout << "After ++it: " << *it << std::endl;
    
    --it;    // Move back to first element
    std::cout << "After --it: " << *it << std::endl;
    
    std::cout << "Full iteration:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

// Compare MutantStack with std::list for identical behavior
void compareWithList() {
    printSeparator("COMPARE WITH STD::LIST");
    
    // Create and add elements to MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Create et add les memes elements a une liste standard
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "MutantStack contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    std::cout << "std::list contents:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

// Test with different data types
void testDifferentTypes() {
    printSeparator("TEST WITH DIFFERENT TYPES");
    
    // Test with strings
    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("42");
    sstack.push("World");
    
    std::cout << "String stack top: " << sstack.top() << std::endl;
    std::cout << "String stack size: " << sstack.size() << std::endl;
    
    std::cout << "String stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    // Test with doubles
    MutantStack<double> dstack;
    dstack.push(3.14);
    dstack.push(2.718);
    dstack.push(1.618);
    
    std::cout << "Double stack top: " << dstack.top() << std::endl;
    std::cout << "Double stack contents:" << std::endl;
    for (MutantStack<double>::iterator it = dstack.begin(); it != dstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

// Test copy constructor and assignment operator
void testCopyAndAssignment() {
    printSeparator("TEST COPY AND ASSIGNMENT");
    
    MutantStack<int> stack1;
    stack1.push(5);
    stack1.push(10);
    stack1.push(15);
    
    // Test copy constructor
    std::cout << "Testing copy constructor:" << std::endl;
    MutantStack<int> stack2(stack1);
    
    std::cout << "Original stack:" << std::endl;
    for (MutantStack<int>::iterator it = stack1.begin(); it != stack1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    std::cout << "Copied stack:" << std::endl;
    for (MutantStack<int>::iterator it = stack2.begin(); it != stack2.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    // Test assignment operator
    std::cout << "Testing assignment operator:" << std::endl;
    MutantStack<int> stack3;
    stack3.push(100);
    stack3.push(200);
    
    std::cout << "Stack3 before assignment:" << std::endl;
    for (MutantStack<int>::iterator it = stack3.begin(); it != stack3.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    stack3 = stack1;
    
    std::cout << "Stack3 after assignment:" << std::endl;
    for (MutantStack<int>::iterator it = stack3.begin(); it != stack3.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

// Test stack conversion
void testStackConversion() {
    printSeparator("TEST STACK CONVERSION");
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    
    std::cout << "Converting MutantStack to standard stack" << std::endl;
    std::stack<int> s(mstack);
    
    std::cout << "Standard stack size: " << s.size() << std::endl;
    std::cout << "Standard stack top: " << s.top() << std::endl;
    
    // On ne peut pas parcourir une stack donc on la vide et print chaque element retire
    std::cout << "Popping standard stack elements:" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}

int main()
{
    // Run the original test from the subject
    printSeparator("ORIGINAL TEST FROM SUBJECT");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(231);
    mstack.push(992);
    mstack.push(6);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    // Run additional tests
    testBasicOperations();
    testIteration();
    compareWithList();
    testDifferentTypes();
    testCopyAndAssignment();
    testStackConversion();
    
    return 0;
}
