#ifndef MTM4_LEADERBOARD_H
#define MTM4_LEADERBOARD_H
#include "/Players/Player.h"
#include <string>
#include <queue>
#include <vector>

class Leaderboard {
public:
    explicit Leaderboard(int);
    void printLeaderboard(const std::queue<Player*>&, bool isOver = false) const;
    void updateWinner(Player*);
    void updateLoser(Player*);
    ~Leaderboard() = default;
    Leaderboard(Leaderboard&) = delete;
    Leaderboard operator=(Leaderboard&) = delete;

private:
    std::vector<Player*> m_playersArray;
    int m_topIndex;
    int m_endIndex;
};


#endif //MTM4_LEADERBOARD_H
