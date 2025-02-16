#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_zombies> <zombie_name>" << std::endl;
        return 1;
    }
    int nb_zombie = std::atoi(argv[1]);
    if (nb_zombie <= 0) {
        std::cerr << "Error: Number of zombies must be > 0" << std::endl;
        return 1;
    }
    std::cout << "Creating a horde of " << nb_zombie << " zombies named " << argv[2] << "..." << std::endl;
    Zombie* horde = zombieHorde(nb_zombie, argv[2]);

    std::cout << "\nThe zombies are announcing themselves:" << std::endl;
    for (int i = 0; i < nb_zombie; i++) {
        horde[i].announce();
    }
    std::cout << "\nDestroying the horde of zombies..." << std::endl;
    delete[] horde;

    return 0;
}