#include "Well.h"
#include "../Players/Jobs.h"

void Well::applyEncounter(Player& player) const {
    try {
        const Ninja & ninja = dynamic_cast<Ninja&> (player); // may be need to do something with warrior - check compiling flags later
    }
    catch (std::bad_cast&){
        player.damage(10);
        printWellMessage(false);
    }
    printWellMessage(true);
}

void Well::printCard(std::ostream& os) const {
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
}