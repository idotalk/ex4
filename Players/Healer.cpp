#include "Healer.h"
#include "../utilities.h"

Healer::Healer(const std::string &name) : Player(name.c_str()) {}

Healer::Healer(const char* name) : Player(name) {}

void Healer::heal(const int hpToHeal) {
    Player::heal(2*hpToHeal);
}

void Healer::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Healer",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);

}