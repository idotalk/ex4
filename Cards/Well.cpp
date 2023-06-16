#include "Well.h"
#include "../Players/Ninja.h"

void Well::applyEncounter(Player& player) const {
    bool isNinja = true;
    try {
        const Ninja & ninja = dynamic_cast<Ninja&> (player); // may be need to do something with warrior - check compiling flags later
    }
    catch (std::bad_cast&){
        isNinja = false;
    }
    if (isNinja) {
        printWellMessage(true);

    } else {
        player.damage(10);
        printWellMessage(false);
    }
}

void Well::printCard(std::ostream& os) const {
    printCardDetails(os, "Well");
    printEndOfCardDetails(os);
}