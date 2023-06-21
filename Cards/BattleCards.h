#ifndef MTM4_BATTLECARDS_H
#define MTM4_BATTLECARDS_H
#include "Card.h"

class BattleCards : public Card {
public:
    BattleCards(int,int,int);
    BattleCards() = delete;
    BattleCards(BattleCards&) = delete;
    BattleCards& operator=(const BattleCards&) = delete;

protected:
    const int m_force;
    const int m_damage;
    const int m_loot;

};


#endif //MTM4_BATTLECARDS_H
