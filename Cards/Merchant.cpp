#include "Merchant.h"
#include <vector>
#include <algorithm>
static std::string getInputAndValidate() ;

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(),player.getCoins());
    const std::string selection = getInputAndValidate();
    const int numericSelection = std::stoi(selection);
    switch (numericSelection) {
        case 0:
            printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
            break;
        case 1:
            if (player.pay(m_healthPointsPrice)) {
                player.heal(1);
                printMerchantSummary(std::cout, player.getPlayerName(), 1, m_healthPointsPrice);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getPlayerName(), 1, 0);
            }
            break;
        case 2:
            if (player.pay(m_forcePointsPrice)) {
                player.buff(1);
                printMerchantSummary(std::cout, player.getPlayerName(), 2, m_forcePointsPrice);
            } else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getPlayerName(), 2, 0);
            }
            break;
    }
}


static std::string getInputAndValidate() {
    const std::vector<std::string> validSelections = {"0","1","2"};
    std::vector<std::string>::const_iterator it;
    std::string selection;
    while (it != validSelections.cend()){
        std::getline(std::cin,selection);
        it = std::find(validSelections.cbegin(),validSelections.cend(), selection);
        if (it == validSelections.cend()){
            printInvalidInput();
            it = validSelections.cbegin();
        } else {
            break;
        }
    }
    return selection;
}
void Merchant::printCard(std::ostream& os) const {
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
}