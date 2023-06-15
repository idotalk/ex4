#ifndef MTM4_WITCH_H
#define MTM4_WITCH_H
#include "BattleCards.h"


class Witch : public BattleCards {
public:
    Witch();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;

};


#endif //MTM4_WITCH_H
