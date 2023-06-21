#ifndef MTM4_MANA_H
#define MTM4_MANA_H
#include "Card.h"


class Mana : public Card {
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
private:
    static const int m_manaCardHealing = 10;
};


#endif //MTM4_MANA_H
