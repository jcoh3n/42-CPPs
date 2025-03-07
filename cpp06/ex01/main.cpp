#include "Serializer.hpp"
#include <iostream>
#include <stdexcept>  // Pour std::invalid_argument

int main() {
    try {
        // Crée une instance de Data = User
        Data myData("John Doe", 42, 1000);
        
        // Affiche les valeurs originales
        std::cout << "=== Données originales ===" << std::endl;
        myData.get_name();
        myData.get_age();
        myData.get_solde();
        
        // Transforme l'adresse de myData en un numéro --> SERIALISE LA DATA
        uintptr_t num = Serializer::serialize(&myData);
        std::cout << "\n=== Après sérialisation ===" << std::endl;
        std::cout << "Valeur numérique: " << num << std::endl;

        // Transforme le numéro en un pointeur vers Data --> RECUPERE L'ADRESSE ORIGINALE
        Data* ptr = Serializer::deserialize(num);
        if (ptr == NULL) {
            std::cerr << "Erreur: Désérialisation a retourné un pointeur null." << std::endl;
            return 1;
        }
        std::cout << "\n=== Après désérialisation ===" << std::endl;
        std::cout << "Adresse récupérée: " << ptr << std::endl;
        
        // Vérifie que les pointeurs sont égaux
        std::cout << "\n=== Vérification ===" << std::endl;
        if (ptr == &myData) {
            std::cout << "Succès: Les pointeurs sont identiques!" << std::endl;
        } else {
            std::cout << "Échec: Les pointeurs sont différents." << std::endl;
        }
        
        // Accès aux données à travers le pointeur pour vérifier que tout fonctionne
        std::cout << "\n=== Accès aux données via le pointeur désérialisé ===" << std::endl;
        ptr->get_name();
        ptr->get_age();
        ptr->get_solde();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}