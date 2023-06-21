#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <string>
#include <queue>
#include "Leaderboard.h"
#include "Players/Player.h"
#include "Cards/Card.h"
#include "utilities.h"

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    Mtmchkin operator=(Mtmchkin&) = delete;
    Mtmchkin(Mtmchkin&) = delete;
    ~Mtmchkin();

private:
    std::queue<Player*> m_playersQueue;
    std::queue<const Card*> m_cardsDeck;
    Leaderboard m_leaderBoard;
    int m_playersAmount;
    int m_remainPlayers;
    int m_roundsPlayed;
    static const int m_maxLevel = 10;
};



#endif /* MTMCHKIN_H_ */
