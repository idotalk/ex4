#ifndef MTM4_NINJA_H
#define MTM4_NINJA_H
#include "Player.h"


class Ninja : public Player {
public:
    explicit Ninja(const std::string&);
    explicit Ninja(const char*);
    void addCoins(const int) override;
    void printInfo(std::ostream&) const override;
};


#endif //MTM4_NINJA_H
