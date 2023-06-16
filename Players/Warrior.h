#ifndef MTM4_WARRIOR_H
#define MTM4_WARRIOR_H
#include "Player.h"


class Warrior : public Player {
public:
    explicit Warrior(const std::string&);
    explicit Warrior(const char*);
    int getAttackStrength() const override;
    void printInfo(std::ostream&) const override;
};


#endif //MTM4_WARRIOR_H
