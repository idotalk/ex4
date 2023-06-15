#include "Leaderboard.h"
#include "utilities.h"
Leaderboard::Leaderboard(int playersAmount) : m_playersArray(std::vector<Player*>(playersAmount)){
    m_topIndex = 0;
    m_endIndex = playersAmount - 1;

}

void Leaderboard::printLeaderboard(const std::queue<Player *> &playersQueue, bool isOver) const {
    printLeaderBoardStartMessage();
    if (isOver){
        for (int i=0; i<m_playersArray.size(); i++){
            printPlayerLeaderBoard(1,*(m_playersArray[i]));
        }

    } else {

    }
}


void Leaderboard::updateWinner(Player *newWinner) {
    m_playersArray.insert(m_playersArray.begin()+m_topIndex, newWinner);
}

void Leaderboard::updateLoser(Player *newLoser){
    m_playersArray.insert(m_playersArray.begin()+m_endIndex, newLoser);
}