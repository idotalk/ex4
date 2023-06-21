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
static int findFirstChar(const std::string& str);
static int findLastChar(const std::string& str);
static void deleteConsecutiveSpaces(std::string& str);
static std::string trimBoundSpaces(std::string& str);
static std::string trimInput(std::string& input);


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
    printStartGameMessage();
    std::ifstream deckFile(fileName);
    if(!deckFile){
        throw DeckFileNotFound();
    }
    m_cardsDeck= initializeCardsQueue(deckFile);
    m_roundsPlayed = 0;
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
            } else if (currentPlayer->getLevel() == m_maxLevel) {
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
    std::queue<Player*> playersQueue;
    for (int i=0; i<amount; i++){
        bool valid = false;
        printInsertPlayerMessage();
        do{
            std::getline(std::cin,playerDetailsBuffer);
            std::string trimmedInput = trimInput(playerDetailsBuffer);
            if (countSpacesInString(trimmedInput) == 1) {
                valid = true;
            } else {
                printInvalidInput();
                printInsertPlayerMessage();
                continue;
            }
            std::istringstream stream(trimmedInput);
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
    int maxLengthAllowed = 15, count = 0;
    for(const char c:name){
        if(!std::isalpha(c)){
            return false;
        }
        count++;
    }
    if(count > maxLengthAllowed) {
        return false;
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
    return std::stoi(teamSizeBuffer);
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
    const int minimumCardsAmount = 5;
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
    if (linesCounter < minimumCardsAmount){
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


static int findFirstChar(const std::string& str){
    int pos = 0;
    while (isspace(str[pos])) {
        pos++;
    }
    if(pos == (int)str.length()) {
        return -1;
    }
    return pos;
}
static int findLastChar(const std::string& str){
    int pos = str.length()-1;
    while (isspace(str[pos])) {
        pos--;
    }
    if(pos == (int)str.length()) {
        return -1;
    }
    return pos;
}
static void deleteConsecutiveSpaces(std::string& str){
    for(int i=str.size() - 1; i >= 0; i--)
    {
        if(str[i]==' ' && str[i] == str[i-1]) {
            str.erase( str.begin() + i );
        }
    }
}
static std::string trimBoundSpaces(std::string& str){
    int start = findFirstChar(str);
    int end = findLastChar(str);
    if (start == -1 || end == -1) {
        return str;
    }
    std::string trimmedString = str.substr(start,(end-start+1));
    return trimmedString;
}

static std::string trimInput(std::string& input){
    std::string trimBeginEnd = trimBoundSpaces(input);
    deleteConsecutiveSpaces(trimBeginEnd);
    return trimBeginEnd;
}


