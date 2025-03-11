#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>

int main() {
    try {
        // Test 1 : Span de petite capacité (5 éléments)
        {
            std::cout << "=== Test 1: Small Span (Capacity: 5) ===" << std::endl;

            Span sp(5);

            // Ajout de nombres un par un
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            // Calcul et affichage des distances
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Doit afficher 2
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;  // Doit afficher 14
        }

        // Test 2 : Ajout d'une plage d'éléments via des itérateurs
        {
            std::cout << "\n=== Test 2: Adding a Range of Numbers ===" << std::endl;

            Span sp(8);  // Span de capacité 8

            // Ajout de nombres un par un
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);

            // Ajout d'une plage de nombres via des itérateurs
            int temp[] = {100, 200, 300};  // Tableau temporaire
            std::vector<int> vec(temp, temp + sizeof(temp) / sizeof(temp[0]));  // Initialisation du vector
            sp.addRange(vec.begin(), vec.end());

            // Calcul et affichage des distances après ajout de la plage
            std::cout << "Shortest span after adding range: " << sp.shortestSpan() << std::endl; // Doit afficher 2
            std::cout << "Longest span after adding range: " << sp.longestSpan() << std::endl;  // Doit afficher 297
        }

        // Test 3 : Span de grande capacité (10 000 éléments)
        {
            std::cout << "\n=== Test 3: Large Span (Capacity: 10,000) ===" << std::endl;

            Span bigSpan(10000);
            Span RellyBigSpan(1000000);
            // Remplissage du Span avec 10 000 nombres
            for (int i = 0; i < 10000; ++i) {
                bigSpan.addNumber(i);
            }
            for (int i = 0; i < 1000000; ++i) {
                RellyBigSpan.addNumber(i);
            }

            // Calcul et affichage des distances
            std::cout << "Shortest span for bigSpan: " << bigSpan.shortestSpan() << std::endl; // Doit afficher 1
            std::cout << "Longest span for bigSpan: " << bigSpan.longestSpan() << std::endl;  // Doit afficher 9999
            std::cout << "Shortest span for RellyBigSpan: " << RellyBigSpan.shortestSpan() << std::endl; // Doit afficher 1
            std::cout << "Longest span for RellyBigSpan: " << RellyBigSpan.longestSpan() << std::endl;  // Doit afficher 999999
        }

        // Test 4 : Span vide (doit lancer une exception)
        {
            std::cout << "\n=== Test 4: Empty Span ===" << std::endl;

            Span emptySpan(5);

            // Tentative de calcul des distances sur un Span vide
            std::cout << "Shortest span for emptySpan: " << emptySpan.shortestSpan() << std::endl; // Ne sera pas exécuté
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}