#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "../Players/Player.h"
#include "../utilities.h"

class Card {
public:
    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
    */
    virtual void applyEncounter(Player& player) const = 0;


    /* Prints the card info */
    virtual void printCard(std::ostream& os) const = 0;
    virtual ~Card() = default;

private:
    friend std::ostream& operator<<(std::ostream& os, const Card& card){
        card.printCard(os);
        return os;
    }
};

#endif //EX4_Card_H
