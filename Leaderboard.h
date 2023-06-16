#ifndef MTM4_LEADERBOARD_H
#define MTM4_LEADERBOARD_H
#include <string>
#include <queue>
#include <vector>
#include "Players/Player.h"

class Leaderboard {
public:
    explicit Leaderboard(int);
    void printBoard(const std::queue<Player*>&, bool isOver = false) const;
    void updateWinner(Player*);
    void updateLoser(Player*);
    ~Leaderboard();
    Leaderboard(Leaderboard&) = delete;

private:
    std::vector<Player*> m_playersArray;
    int m_topIndex;
    int m_endIndex;
    int m_amount;
};


#endif //MTM4_LEADERBOARD_H
