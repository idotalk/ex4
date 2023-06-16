#include "Barfight.h"
#include "../Players/Warrior.h"

void Barfight::applyEncounter(Player& player) const {
    bool isWarrior = true;
    try {
        const Warrior& warrior = dynamic_cast<Warrior&>(player); // may be need to do something with warrior - check compiling flags later
        warrior.getHP();
    }
    catch (std::bad_cast& e){
        isWarrior = false;
    }
    if(isWarrior){
        printBarfightMessage(true);
    } else {
        player.damage(10);
        printBarfightMessage(false);
    }
}

void Barfight::printCard(std::ostream& os) const {
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}