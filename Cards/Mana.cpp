#include "Mana.h"
#include "../Players/Healer.h"
void Mana::applyEncounter(Player& player) const {
    try {
        Healer& healer = dynamic_cast<Healer&>(player);
        healer.heal(m_manaCardHealing);
        printManaMessage(true);
    }
    catch (std::bad_cast& e){
        printManaMessage(false);
    }
}

void Mana::printCard(std::ostream& os) const {
    printCardDetails(os, "Mana");
    printEndOfCardDetails(os);
}