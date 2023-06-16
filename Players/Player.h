#ifndef MTM4_PLAYER_H
#define MTM4_PLAYER_H
#include <string>

#include "HealthPoints.h"


class Player {
public:
    /* C'tor of Player class
     * @param name - The name of the player.
     * @param maxHP - The starting HP and maximum HP of the player.
     * @param level - The starting level of the player.
     *
     * maxHP and Level has default values - @see static const members of this class.
     * @result
     *      an instance of Player.
     *  */
    explicit Player(const char* name, int maxHP = m_startingHP ,int forcePoints = m_startingForce);

    // D'tor, copy c'tor and assigment operator are set to their default provided by the compiler.
    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player&) = default;

    // Player class methods:

    /* Leveling up a player by 1 level up to maximum level (@see static const members of this class).
     * In case the player is already maxed out his level this functions does nothing. */
    void levelUp();

    /* Leveling down a player by 1 level up to minimum level (@see static const members of this class).
     * In case the player is already at the minimum level this functions does nothing. */
    void weak();

    // Return current player level.
    int getLevel() const;

    /* Adding points to the force value of the player.
     * @param points - How much points to buff a player.
     * In case of negative argument does nothing. */
    void buff(const int);

    /* Adding HP points to player - up to the maximum HP (m_maxHP).
     * @param healPoints - How much points to heal a player.
     * In case of negative argument does nothing. */
    virtual void heal(const int) ;

    /* Deducting HP points to player - if suppress the minimum HP (m_minimumHP) player HP would set to minimum HP.
     * @param damagePoints - How much points to damage a player.
     * In case of positive argument does nothing. */
    void damage(const int);

    /* Adding coins to player
    * @param coinsToAdd - How much coins to add.
    * In case of negative argument does nothing. */
    virtual void addCoins(const int) ;

    // Returns true if player HP is minimum HP (m_minimumHP).
    bool isKnockedOut() const;

    /* Pay interaction for player
     * If the player has enough coins this function will deduct the amount passed as parameter from the player coins.
     * In case the player doesn't have enough coins - not changing the player's coins amount.
     * If the payment succeed returns true else false.
     * @param coinsToPay - how much coins the player need to pay. */
    bool pay(const int);

    // Name Getter
    std::string getPlayerName() const;

    int getHP() const;
    int getCoins() const;

    // Returns player level + force values.
    virtual int getAttackStrength() const ;

protected:
    // Player Attributes
    std::string m_name;
    int m_level;
    int m_force;
    HealthPoints m_HP;
    int m_coins;

    // Default Player values
    static const int m_minimumHP = 0;
    static const int m_startingHP = 100;
    static const int m_startingLevel = 1;
    static const int m_maxLevel = 10;
    static const int m_startingCoins = 10;
    static const int m_startingForce = 5;

    // Printing a Player information
    virtual void printInfo(std::ostream& os) const = 0;

private:
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

};


#endif //MTM4_PLAYER_H
