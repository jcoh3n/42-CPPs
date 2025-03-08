#include <iostream>
#include "Array.hpp"

int main() {
    // Test 1 : Construction par défaut (tableau vide)
    std::cout << "=== Test 1 : Construction par défaut ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Taille de emptyArray : " << emptyArray.size() << std::endl;
    std::cout << std::endl;

    // Test 2 : Construction avec une taille spécifiée
    std::cout << "=== Test 2 : Construction avec une taille ===" << std::endl;
    Array<int> intArray(5); // Tableau de 5 entiers
    std::cout << "Taille de intArray : " << intArray.size() << std::endl;

    // Remplissage du tableau avec des valeurs
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
    }

    // Affichage des éléments du tableau
    std::cout << "Éléments de intArray : ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Test 3 : Test de la gestion des exceptions pour accès hors limites
    std::cout << "=== Test 3 : Accès hors limites ===" << std::endl;
    try {
        std::cout << "Tentative d'accès à intArray[10] : ";
        std::cout << intArray[10] << std::endl; // Doit lever une exception 
    } catch (const std::out_of_range& e) {
        std::cout << "Exception attrapée : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4 : Test du constructeur de copie profonde
    std::cout << "=== Test 4 : Test du constructeur de copie profonde ===" << std::endl;
    Array<int> copiedArray(intArray); // Copie de intArray
    std::cout << "Éléments de copiedArray : ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " "; // 0 10 20 30 40
    }
    std::cout << std::endl;

    // Modification de l'original et vérification de l'indépendance de la copie
    intArray[0] = 100;
    std::cout << "Après modification de intArray[0] : " << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;  // 100
    std::cout << "copiedArray[0] = " << copiedArray[0] << " (doit rester inchangé)" << std::endl; // 0
    std::cout << std::endl;

    // Test 5 : Test de l'opérateur d'affectation (deep copy)
    std::cout << "=== Test 5 : Test de l'opérateur d'affectation (deep copy) ===" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray; // Affectation de intArray
    std::cout << "Éléments de assignedArray : ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " "; // 100 10 20 30 40
    }
    std::cout << std::endl;

    // Modification de l'original et vérification de l'indépendance après affectation
    intArray[1] = 200;
    std::cout << "Après modification de intArray[1] : " << std::endl;
    std::cout << "intArray[1] = " << intArray[1] << std::endl; // 200
    std::cout << "assignedArray[1] = " << assignedArray[1] << " (doit rester inchangé)" << std::endl; // 10
    std::cout << std::endl;

    // Test 6 : Test avec un type différent (std::string)
    std::cout << "=== Test 6 : Utilisation avec std::string ===" << std::endl;
    Array<std::string> strArray(3); // Tableau de 3 chaînes de caractères
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    std::cout << "Éléments de strArray : ";
    for (unsigned int i = 0; i < strArray.size(); ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    // Test 7 : Test de la copie profonde avec std::string
    std::cout << "=== Test 7 : Test de la copie profonde avec std::string ===" << std::endl;
    Array<std::string> copiedStrArray(strArray); 
    strArray[0] = "Bonjour";
    std::cout << "Après modification de strArray[0] : " << std::endl;
    std::cout << "strArray[0] = " << strArray[0] << std::endl; // Bonjour
    std::cout << "copiedStrArray[0] = " << copiedStrArray[0] << " (doit rester inchangé)" << std::endl; // Hello
    std::cout << std::endl;

    return 0;
}