#include "Leaderboard.h"
#include "utilities.h"
Leaderboard::Leaderboard(int playersAmount) : m_playersArray(std::vector<Player*>(playersAmount)){
    m_topIndex = 0;
    m_endIndex = playersAmount - 1;
    m_amount = playersAmount;
    for(int i=0;i<playersAmount;i++){
        m_playersArray[i] = nullptr;
    }

}
Leaderboard::~Leaderboard() {
    for(int i=0; i<m_amount; i++){
        if(m_playersArray[i]!= nullptr){
            delete m_playersArray[i];
        }
    }

}

void Leaderboard::printBoard(const std::queue<Player *> &playersQueue, bool isOver) const {
    printLeaderBoardStartMessage();
    if (isOver){
        for (int i=0; i<m_amount; i++){
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
            i++;
        }
        for (int j=m_amount -1; j>m_endIndex; j--){
            printPlayerLeaderBoard(j+1,*(m_playersArray[j]));
        }
    }
}


void Leaderboard::updateWinner(Player *newWinner) {
    m_playersArray[m_topIndex] = newWinner;
    m_topIndex++;
}

void Leaderboard::updateLoser(Player *newLoser){
    m_playersArray[m_endIndex] = newLoser;
    m_endIndex--;
}