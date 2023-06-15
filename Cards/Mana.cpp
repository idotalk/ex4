#include "Mana.h"
#include "../Players/Jobs.h"

void Mana::applyEncounter(Player& player) const {
    try {
        const Healer& healer = dynamic_cast<Healer&>(player); // may be need to do something with warrior - check compiling flags later
    }
    catch (std::bad_cast&){
        printManaMessage(false);
    }
    player.heal(10);
    printManaMessage(true);
}

void Mana::printCard(std::ostream& os) const {
    printCardDetails(os, "Mana");
    printEndOfCardDetails(os);
}