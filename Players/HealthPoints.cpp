#include "HealthPoints.h"

HealthPoints::HealthPoints(const int hp) {
    if (hp <= 0){
        throw HealthPoints::InvalidArgument();
    }
    m_maxHP = hp;
    m_currentHP = hp;
}

HealthPoints& HealthPoints::operator+=(const int hp) {
    if (m_currentHP + hp > m_maxHP) {
        m_currentHP = m_maxHP;
    } else if(m_currentHP + hp < 0) {
        m_currentHP = 0;
    } else {
        m_currentHP = m_currentHP + hp;
    }
    return *this;
}
HealthPoints& HealthPoints::operator-=(const int hp) {
    return (*this += (-hp) );
}
HealthPoints& HealthPoints::operator=(const int hp){
    if (hp <= 0){
        throw InvalidArgument();
    }
    m_currentHP = hp;
    m_maxHP = hp;
    return *this;
}

int HealthPoints::getCurrentHP() const {
    return m_currentHP;
}
HealthPoints operator+(const HealthPoints& healthPoints,const int hp){
    HealthPoints result = healthPoints;
    result += hp;
    return result;
}
HealthPoints operator-(const HealthPoints& healthPoints,const int hp){
    HealthPoints result = healthPoints;
    result -= hp;
    return result;
}
HealthPoints operator+(const int hp, const HealthPoints& healthPoints){
    return healthPoints + hp;
}
HealthPoints operator-(const int hp, const HealthPoints& healthPoints){
    return healthPoints - hp;
}

bool operator==(const HealthPoints& firstHP, const HealthPoints& secondHP) {
    if (!(firstHP > secondHP) && !(secondHP > firstHP)) {
        return true;
    }
    return false;
}

bool operator>(const HealthPoints& firstHP, const HealthPoints& secondHP) {
    if (firstHP.m_currentHP > secondHP.m_currentHP){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream &stream, const HealthPoints& hpToPrint) {
    stream << hpToPrint.m_currentHP; // << '(' << hpToPrint.m_maxHP << ')';
    return stream;
}

bool operator!=(const HealthPoints& firstHP, const HealthPoints& secondHP){
    return !(firstHP==secondHP);
}
bool operator>=(const HealthPoints& firstHP, const HealthPoints& secondHP){
    return (firstHP==secondHP || firstHP>secondHP);
}
bool operator<=(const HealthPoints& firstHP, const HealthPoints& secondHP){
    return !(firstHP>secondHP);
}
bool operator<(const HealthPoints& firstHP, const HealthPoints& secondHP){
    return !(firstHP>secondHP || firstHP==secondHP);

}
