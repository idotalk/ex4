#ifndef MTM4_BARFIGHT_H
#define MTM4_BARFIGHT_H
#include "Card.h"


class Barfight : public Card {
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
private:
    static const int m_barfightCardDamage = 10;

};


#endif //MTM4_BARFIGHT_H
