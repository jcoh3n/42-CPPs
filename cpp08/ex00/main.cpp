#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
    try {
        // Test avec un std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Testing with std::vector:" << std::endl;
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found: " << *it_vec << std::endl;

        // Test avec un std::list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::cout << "\nTesting with std::list:" << std::endl;
        std::list<int>::iterator it_lst = easyfind(lst, 20);
        std::cout << "Found: " << *it_lst << std::endl;

        // Test avec un std::deque
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);

        std::cout << "\nTesting with std::deque:" << std::endl;
        std::deque<int>::iterator it_deq = easyfind(deq, 200);
        std::cout << "Found: " << *it_deq << std::endl;

        // Test avec un élément non présent
        std::cout << "\nTesting with an element not in the container:" << std::endl;
        std::vector<int>::iterator it_not_found = easyfind(vec, 42);
        std::cout << "Found: " << *it_not_found << std::endl; // Cette ligne ne sera pas exécutée
    } catch (std::exception &e) {
        std::cout << "Element not found in container." << std::endl;
    }

    return 0;
}