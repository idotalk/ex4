#include "Barfight.h"
#include "../Players/Jobs.h"
void Barfight::applyEncounter(Player& player) const {
    try {
        const Warrior& warrior = dynamic_cast<Warrior&>(player); // may be need to do something with warrior - check compiling flags later
    }
    catch (std::bad_cast&){
        player.damage(8);
        printBarfightMessage(false);
    }
    printBarfightMessage(true);
}

void Barfight::printCard(std::ostream& os) const {
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}