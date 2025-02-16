#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
    Weapon glock = Weapon("Glock");

    HumanA bob("Bob", glock);
    HumanB max("Max");
    bob.attack();
    glock.setType("Desert Eagle");
    max.attack();
    bob.attack();


    Weapon club = Weapon("crude spiked club");
    max.setWeapon(club);
    max.attack();
    club.setType("a sharp sword");
    max.attack();
    return 0;
}
