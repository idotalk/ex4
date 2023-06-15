#ifndef MTM4_DRAGON_H
#define MTM4_DRAGON_H
#include "BattleCards.h"


class Dragon : public BattleCards {
public:
    Dragon();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;

};


#endif //MTM4_DRAGON_H
