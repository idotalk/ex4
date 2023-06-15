#ifndef MTM4_MANA_H
#define MTM4_MANA_H
#include "Card.h"


class Mana : public Card {
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
};


#endif //MTM4_MANA_H
