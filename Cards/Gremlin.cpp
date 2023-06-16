#include "Gremlin.h"
Gremlin::Gremlin() : BattleCards(5,10,2) {
}

void Gremlin::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getPlayerName(),"Gremlin");
    } else {
        player.damage(m_damage);
        printLossBattle(player.getPlayerName(),"Gremlin");
    }
}

void Gremlin::printCard(std::ostream& os) const {
    printCardDetails(os, "Gremlin");
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}