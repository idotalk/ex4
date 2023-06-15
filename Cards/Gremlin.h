#ifndef MTM4_GREMLIN_H
#define MTM4_GREMLIN_H
#include "BattleCards.h"

class Gremlin : public BattleCards{
public:
    Gremlin();
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
};


#endif //MTM4_GREMLIN_H
