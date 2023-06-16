#ifndef MTM4_HEALER_H
#define MTM4_HEALER_H
#include "Player.h"


class Healer : public Player {
public:
    explicit Healer(const std::string&);
    explicit Healer(const char*);
    void heal(const int) override;
    void printInfo(std::ostream&) const override;
};

#endif //MTM4_HEALER_H
