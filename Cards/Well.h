#ifndef MTM4_WELL_H
#define MTM4_WELL_H
#include "Card.h"


class Well : public Card{
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
private:
    static const int m_wellCardDamage = 10;
};


#endif //MTM4_WELL_H
