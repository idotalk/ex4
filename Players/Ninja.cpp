#include "Ninja.h"
#include "../utilities.h"
Ninja::Ninja(const std::string &name) : Player(name.c_str()) {}

Ninja::Ninja(const char* name) : Player(name) {}

void Ninja::addCoins(const int coinsToAdd) {
    Player::addCoins(2*coinsToAdd);
}
void Ninja::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Ninja",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);
}
