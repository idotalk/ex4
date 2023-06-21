#include "Barfight.h"
#include "../Players/Warrior.h"

void Barfight::applyEncounter(Player& player) const {
    try {
        __attribute__((unused)) const Warrior& warrior = dynamic_cast<Warrior&>(player); // may be need to do something with warrior - check compiling flags later
        printBarfightMessage(true);
    }
    catch (std::bad_cast& e){
        player.damage(m_barfightCardDamage);
        printBarfightMessage(false);
    }
}

void Barfight::printCard(std::ostream& os) const {
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
}