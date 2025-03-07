#include "Serializer.hpp"


int main() {
    // Crée une instance de Data = User
    Data myData = {"John", 42, 10250.67};
    
    // Affiche les valeurs originales
    std::cout << "=== Données originales ===" << std::endl;
    std::cout << "Nom: " << myData._name_user << std::endl;
    std::cout << "Age: " << myData._age_user << std::endl;
    std::cout << "Solde: " << myData._solde_user << std::endl;
    std::cout << "Adresse mémoire: " << &myData << std::endl;
    
    // Transforme l'adresse de myData en un numéro --> SERIALISE LA DATA
    uintptr_t num = Serializer::serialize(&myData);
    std::cout << "\n=== Après sérialisation ===" << std::endl;
    std::cout << "Valeur numérique: " << num << std::endl;

    // Transforme le numéro en un pointeur vers Data --> RECUPERE L'ADRESSE ORIGINALE
    Data* ptr = Serializer::deserialize(num);
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
    std::cout << "Nom: " << ptr->_name_user << std::endl;
    std::cout << "Age: " << ptr->_age_user << std::endl;
    std::cout << "Solde: " << ptr->_solde_user << std::endl;

    return 0;
}