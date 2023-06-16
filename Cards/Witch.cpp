#include "Witch.h"

Witch::Witch() : BattleCards(11,10,2) {}

void Witch::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getPlayerName(),"Witch");
    } else {
        player.weak();
        player.damage(m_damage);
        printLossBattle(player.getPlayerName(),"Witch");
    }
}

void Witch::printCard(std::ostream& os) const {
    printCardDetails(os, "Witch");
    printMonsterDetails(os,m_force,m_damage,m_loot);
    printEndOfCardDetails(os);
}
