#include "Player.h"

Player::Player(const char *name, const int maxHP, const int forcePoints) {
    m_name = name;
    if (maxHP <= m_minimumHP) {
        HealthPoints hp(m_startingHP);
        m_HP = hp;
    } else {
        HealthPoints hp(maxHP);
        m_HP = hp;
    }
    m_coins = m_startingCoins;
    m_level = m_startingLevel;
    if (forcePoints <= 0) {
        m_force = m_startingForce;
    } else {
        m_force = forcePoints;
    }

}

void Player::levelUp() {
    if (m_level < m_maxLevel) {
        m_level++;
    }
}

void Player::weak() {
    if (m_force == 1 ) {
        m_force --;
    }
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(const int buffPoints){
    if(buffPoints < 0){
        return;
    } else{
        m_force += buffPoints;
    }
}

void Player::heal(const int healPoints){
    if(healPoints < 0){
        return;
    }
    m_HP += healPoints;
}


void Player::damage(const int damagePoints){
    if (damagePoints <= 0) {
        return;
    }
    m_HP -= damagePoints;
}
void Player::addCoins(const int coinsToAdd){
    if (coinsToAdd <= 0){
        return;
    } else {
        m_coins += coinsToAdd;
    }
}

bool Player::isKnockedOut() const{
    if (m_HP == m_minimumHP) {
        return true;
    }
    return false;
}

bool Player::pay(const int coinsToPay){
    if(coinsToPay < 0){
        return false;
    }
    if (coinsToPay > m_coins){
        return false;
    } else {
        m_coins -= coinsToPay;
    }
    return true;
}

std::string Player::getPlayerName() const{
    return m_name;
}

int Player::getHP() const {
    return m_HP.getCurrentHP();
}

int Player::getCoins() const {
    return m_coins;
}

int Player::getAttackStrength() const{
    return m_force + m_level;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    player.printInfo(os);
    return os;
}
