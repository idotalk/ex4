#include "Mtmchkin.h"
#include <fstream>
#include "Exception.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"


static Card* createCardByString(const std::string& className);
static std::queue<const Card*> initializeCardsQueue (std::ifstream& deckFile);
static int teamSizeSelection();
static int countSpacesInString(const std::string& buffer);
static bool validateName(std::string& name);
static bool validateJob(std::string& job);
static Player* createPlayerByString(const std::string& name,const std::string& job);
static std::queue<Player*> initializePlayersQueue(int amount);

Mtmchkin::~Mtmchkin() {
    while(!m_cardsDeck.empty()){
        const Card* cardToDelete = m_cardsDeck.front();
        m_cardsDeck.pop();
        delete cardToDelete;
    }
    if(m_remainPlayers > 0) {
        while (!m_playersQueue.empty()) {
            delete m_playersQueue.front();
            m_playersQueue.pop();
        }
    }
}
Mtmchkin::Mtmchkin(const std::string &fileName) : m_leaderBoard(6) {
    std::ifstream deckFile(fileName);
    if(!deckFile){
        throw DeckFileNotFound();
    }
    m_cardsDeck= initializeCardsQueue(deckFile);
    m_roundsPlayed = 0;
    printStartGameMessage();
    m_remainPlayers = teamSizeSelection();
    m_playersAmount = m_remainPlayers;
    Leaderboard gameLeaderboard(m_playersAmount);
    m_leaderBoard = gameLeaderboard;
    m_playersQueue = initializePlayersQueue(m_playersAmount);
}

void Mtmchkin::playRound() {
    if(m_remainPlayers > 0){
        printRoundStartMessage(getNumberOfRounds() + 1);
        int playersToPlay = m_remainPlayers;
        for (int i=0; i<playersToPlay; i++) {
            const Card *currentCard = m_cardsDeck.front();
            Player *currentPlayer = m_playersQueue.front();
            printTurnStartMessage(currentPlayer->getPlayerName());
            m_playersQueue.pop();
            m_cardsDeck.pop();
            currentCard->applyEncounter(*currentPlayer);
            if (currentPlayer->isKnockedOut()) {
                m_leaderBoard.updateLoser(currentPlayer);
                m_remainPlayers--;
            } else if (currentPlayer->getLevel() == 10) {
                m_leaderBoard.updateWinner(currentPlayer);
                m_remainPlayers--;
            } else {
                m_playersQueue.push(currentPlayer);
            }
            m_cardsDeck.push(currentCard);
        }
        m_roundsPlayed++;
        if (m_remainPlayers == 0){
            printGameEndMessage();
        }
    } else {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    if(m_remainPlayers == 0) {
        m_leaderBoard.printBoard(m_playersQueue,true);
    } else {
        m_leaderBoard.printBoard(m_playersQueue,false);
    }
}

bool Mtmchkin::isGameOver() const {
    if(m_remainPlayers == 0) {
        return true;
    }
    return false;
}


int Mtmchkin::getNumberOfRounds() const {
    return m_roundsPlayed;
}


static std::queue<Player*> initializePlayersQueue(int amount){
    std::string playerDetailsBuffer,name,job;
    bool valid = false;
    std::queue<Player*> playersQueue;
    for (int i=0; i<amount; i++){
        printInsertPlayerMessage();
        do{
            std::getline(std::cin,playerDetailsBuffer);
            if (countSpacesInString(playerDetailsBuffer) == 1) {
                valid = true;
            } else {
                std::cout << "Check Input" << std::endl;
                continue;
            }
            std::istringstream stream(playerDetailsBuffer);
            std::getline(stream,name,' ');
            if(!validateName(name)){
                printInvalidName();
                valid = false;
                continue;
            }
            std::getline(stream,job,' ');
            if(!validateJob(job)){
                printInvalidClass();
                valid = false;
            }
        } while (!valid);
        Player *newPlayer = createPlayerByString(name,job);
        playersQueue.push(newPlayer);
    }
    return playersQueue;
}
static bool validateJob(std::string& job){
    std::vector<std::string>::const_iterator it;
    if(job != "Ninja" && job!= "Warrior" && job != "Healer"){
        return false;
    }
    return true;
}

static bool validateName(std::string& name){
    for(const char c:name){
        if(!std::isalpha(c)){
            return false;
        }
    }
    return true;
}
static int countSpacesInString(const std::string& buffer){
    int count = 0;
    for(char c:buffer){
        if(std::isspace(c)) count++;
    }
    return count;
}
static int teamSizeSelection(){
    printEnterTeamSizeMessage();
    const std::vector<std::string> validTeamSizeSelections = {"2","3","4","5","6"};
    std::vector<std::string>::const_iterator it;
    std::string teamSizeBuffer;
    while (it!=validTeamSizeSelections.cend()){
        std::getline(std::cin,teamSizeBuffer);
        it = std::find(validTeamSizeSelections.cbegin(),validTeamSizeSelections.cend(), teamSizeBuffer);
        if (it == validTeamSizeSelections.cend()) {
            printInvalidTeamSize();
            it = validTeamSizeSelections.cbegin();
        } else {
            break;
        }
    }
    return atoi(teamSizeBuffer.c_str());
}

/* Initialize Cards Queue reading from file, in case of insufficient amount of Cards throws relevant exception.
 * @param std::ifstream deckFile - file to read cards deck from.
 * @return
 *      std::queue<Card*> - queue of cards pointers.
 */
static std::queue<const Card*> initializeCardsQueue (std::ifstream& deckFile){
    const std::vector<std::string> validSelections = {"Gremlin","Witch",
                                                      "Dragon","Merchant",
                                                      "Treasure","Well",
                                                      "Barfight","Mana"};
    std::queue<const Card*> cardsDeck;
    int linesCounter = 0;
    std::string buffer;
    std::vector<std::string>::const_iterator it;
    while (std::getline(deckFile,buffer)) {
        linesCounter++;
        it = std::find(validSelections.cbegin(),validSelections.cend(), buffer);
        if (it == validSelections.cend()) {
            throw DeckFileFormatError(linesCounter);
        }
        const Card* newCard = createCardByString(buffer);
        cardsDeck.push(newCard);
    }
    if (linesCounter < 5){
        while(!cardsDeck.empty()){
            const Card* toDelete = cardsDeck.front();
            cardsDeck.pop();
            delete toDelete;
        }
        throw DeckFileInvalidSize();
    }
    return cardsDeck;
}

/* Creates new card by name.
 * @param string name - card type name
 * @return
 *        Card* - pointer to the new card
 */
static Card* createCardByString(const std::string& className){
    if(className == "Gremlin"){
        Card* gremlinCard = new Gremlin();
        return gremlinCard;
    }
    else if(className == "Witch"){
        Card* witchCard = new Witch();
        return witchCard;
    }
    else if(className == "Dragon"){
        Card* dragonCard = new Dragon();
        return dragonCard;
    }
    else if(className == "Merchant"){
        Card* merchantCard = new Merchant();
        return merchantCard;
    }
    else if(className == "Treasure") {
        Card *treasureCard = new Treasure();
        return treasureCard;
    }
    else if(className == "Well"){
        Card* wellCard = new Well();
        return wellCard;
    }
    else if(className == "Barfight"){
        Card* barfightCard = new Barfight();
        return barfightCard;
    }
    else if(className == "Mana"){
        Card* manaCard = new Mana();
        return manaCard;
    }
    return nullptr;
}

static Player* createPlayerByString(const std::string& name,const std::string& job){
    if(job == "Ninja"){
        Player* ninja = new Ninja(name);
        return ninja;
    }
    else if(job == "Warrior"){
        Player* warrior = new Warrior(name);
        return warrior;
    }
    else if(job == "Healer"){
        Player* healer = new Healer(name);
        return healer;
    }
    return nullptr;
}