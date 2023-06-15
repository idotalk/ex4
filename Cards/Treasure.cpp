#include "Treasure.h"

void Treasure::applyEncounter(Player& player) const {
    player.addCoins(10);
    printTreasureMessage();
}
void Treasure::printCard() const {
    printCardDetails(std::cout, "Treasure");
}