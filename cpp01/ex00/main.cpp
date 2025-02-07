#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <ZombieName> ..." << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
        randomChump(argv[i]);
    return 0;
}