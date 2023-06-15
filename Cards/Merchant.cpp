#include "Merchant.h"
#include <vector>
#include <algorithm>
static std::string getInputAndValidate() ;

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(),player.getCoins());
    const std::string selection = getInputAndValidate();
    if (selection == "0") {
        printMerchantSummary(std::cout, player.getPlayerName(),0,0);
    } else if(selection == "1") {
        if(player.pay(5)){
            player.heal(1);
            printMerchantSummary(std::cout,player.getPlayerName(),1,5);
        } else {
            printMerchantInsufficientCoins(std::cout);
            return;
        }
    } else {
        if(player.pay(10)){
            player.buff(1);
            printMerchantSummary(std::cout,player.getPlayerName(),2,10);
        } else {
            printMerchantInsufficientCoins(std::cout);
            return;
        }
    }
}


static std::string getInputAndValidate() {
    const std::vector<std::string> validSelections = {"0","1","2"};
    std::vector<std::string>::const_iterator it;
    std::string selection;
    while (it != validSelections.end()){
        std::cin >> selection;
        it = std::find(validSelections.cbegin(),validSelections.cend(), selection);
        if (it == validSelections.end()){
            printInvalidInput();
        } else {
            break;
        }
    }
    return selection;
}
void Merchant::printCard() const {
    printCardDetails(std::cout, "Merchant");
    printEndOfCardDetails(std::cout);
}