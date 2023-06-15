#ifndef MTM4_BARFIGHT_H
#define MTM4_BARFIGHT_H
#include "Card.h"


class Barfight : public Card {
    void applyEncounter(Player& player) const override;
    void printCard() const override;
};


#endif //MTM4_BARFIGHT_H
