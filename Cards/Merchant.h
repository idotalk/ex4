#ifndef MTM4_MERCHANT_H
#define MTM4_MERCHANT_H
#include "Card.h"


class Merchant : public Card{
public:
    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
private:
    static const int m_healthPointsPrice = 5;
    static const int m_forcePointsPrice = 10;
};


#endif //MTM4_MERCHANT_H
