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
            printPlayerLeaderBoard(i+1,*(m_playersArray[i]));
        }
    } else {
        std::queue<Player*> clonedQueue(playersQueue);
        int i=0;
        for (;i<m_topIndex; i++){
            printPlayerLeaderBoard(i+1,*(m_playersArray[i]));
        }
        while(!clonedQueue.empty()){
            Player* playerToPrint = clonedQueue.front();
            clonedQueue.pop();
            printPlayerLeaderBoard(i+1,*playerToPrint);
        }
        for (int j=m_playersArray.size()-1 ; j>m_endIndex; j--){
            printPlayerLeaderBoard(j+1,*(m_playersArray[j]));
        }
    }
}


void Leaderboard::updateWinner(Player *newWinner) {
    m_playersArray.insert(m_playersArray.begin()+m_topIndex, newWinner);
    m_topIndex++;
}

void Leaderboard::updateLoser(Player *newLoser){
    m_playersArray.insert(m_playersArray.begin()+m_endIndex, newLoser);
    m_endIndex--;
}