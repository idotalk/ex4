#include "Witch.h"

Witch::Witch() : BattleCards(11,10,2) {}

void Witch::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getPlayerName(),"Gremlin");
    } else {
        player.weak();
        player.damage(m_damage);
        printLossBattle(player.getPlayerName(),"Gremlin");
    }
}

void Witch::printCard() const {
    printCardDetails(std::cout, "Witch");
    printMonsterDetails(std::cout,m_force,m_damage,m_loot);
    printEndOfCardDetails(std::cout);
}
