#ifndef MTM4_MERCHANT_H
#define MTM4_MERCHANT_H
#include "Card.h"


class Merchant : public Card{
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
};


#endif //MTM4_MERCHANT_H
