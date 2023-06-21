#include "Well.h"
#include "../Players/Ninja.h"

void Well::applyEncounter(Player& player) const {
    try {
        __attribute__((unused)) Ninja& ninja = dynamic_cast<Ninja&> (player); // may be need to do something with warrior - check compiling flags later
        printWellMessage(true);
    }
    catch (std::bad_cast&){
        player.damage(m_wellCardDamage);
        printWellMessage(false);
    }
}

void Well::printCard(std::ostream& os) const {
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
}