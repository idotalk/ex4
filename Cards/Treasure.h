#ifndef MTM4_TREASURE_H
#define MTM4_TREASURE_H
#include "Card.h"

class Treasure : public Card {
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
};


#endif //MTM4_TREASURE_H
