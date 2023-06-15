#include "Gremlin.h"
Gremlin::Gremlin() : BattleCards(5,10,2) {
}

void Gremlin::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getPlayerName(),"Witch");
    } else {
        player.damage(m_damage);
        printLossBattle(player.getPlayerName(),"Witch");
    }
}

void Gremlin::printCard() const {
    printCardDetails(std::cout, "Witch");
    printMonsterDetails(std::cout,m_force,m_damage,m_loot);
    printEndOfCardDetails(std::cout);
}