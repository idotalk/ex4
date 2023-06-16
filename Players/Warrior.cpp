#include "Warrior.h"
#include "../utilities.h"
Warrior::Warrior(const std::string &name) : Player(name.c_str()) {}

Warrior::Warrior(const char* name) : Player(name) {}

int Warrior::getAttackStrength() const {
    return 2*m_force + m_level;
}
void Warrior::printInfo(std::ostream& os) const {
    printPlayerDetails(os, m_name, "Warrior",m_level,
                       m_force,m_HP.getCurrentHP(),m_coins);

}