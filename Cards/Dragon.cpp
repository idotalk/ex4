#include "Dragon.h"

Dragon::Dragon() : BattleCards(25,INT_MAX,1000) {}

void Dragon::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getPlayerName(),"Dragon");
    } else {
        player.damage(player.getHP());
        printLossBattle(player.getPlayerName(),"Dragon");
    }
}

void Dragon::printCard() const {
    printCardDetails(std::cout, "Dragon");
    printMonsterDetails(std::cout,m_force,m_damage,m_loot, true);
    printEndOfCardDetails(std::cout);
}