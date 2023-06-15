#ifndef MTM4_WELL_H
#define MTM4_WELL_H
#include "Card.h"


class Well : public Card{
    void applyEncounter(Player& player) const override;
    void printCard() const override;
};


#endif //MTM4_WELL_H
