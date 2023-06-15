#include "Jobs.h"
#include "../utilities.h"
Ninja::Ninja(std::string &name) : Player(name.c_str()) {}

void Ninja::addCoins(const int coinsToAdd) {
    Player::addCoins(2*coinsToAdd);
}
void Ninja::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Ninja",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);
}

Warrior::Warrior(std::string &name) : Player(name.c_str()) {}

int Warrior::getAttackStrength() const {
    return 2*m_force + m_level;
}
void Warrior::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Warrior",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);

}

Healer::Healer(std::string &name) : Player(name.c_str()) {}
void Healer::heal(const int hpToHeal) {
    Player::heal(2*hpToHeal);
}
void Healer::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Healer",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);

}
