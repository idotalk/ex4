#include "Mana.h"
#include "../Players/Healer.h"
void Mana::applyEncounter(Player& player) const {
    bool isHealer = true;
    try {
        const Healer& healer = dynamic_cast<Healer&>(player); // may be need to do something with warrior - check compiling flags later
    }
    catch (std::bad_cast& e){
        isHealer = false;
    }
    if (isHealer) {
        player.heal(10);
        printManaMessage(true);
    } else {
        printManaMessage(false);
    }

}

void Mana::printCard(std::ostream& os) const {
    printCardDetails(os, "Mana");
    printEndOfCardDetails(os);
}