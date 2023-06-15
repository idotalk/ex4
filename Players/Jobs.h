#ifndef MTM4_JOBS_H
#define MTM4_JOBS_H
#include "Player.h"

class Ninja : public Player {
public:
    explicit Ninja(std::string&);
    void addCoins(const int) override;
    void printInfo(std::ostream&) const override;
};

class Warrior : public Player {
public:
    explicit Warrior(std::string&);
    int getAttackStrength() const override;
    void printInfo(std::ostream&) const override;
};

class Healer : public Player {
    explicit Healer(std::string&);
    void heal(const int) override;
    void printInfo(std::ostream&) const override;
};

#endif //MTM4_JOBS_H
