#include <iostream>
#include "Exception.h"
#include "utilities.h"
#include "./Players/Player.h"
#include "./Players/Jobs.h"
int main() {
    std::string name = "BOL";
    Player* p = new Ninja(name);
    printPlayerLeaderBoard(1,*p);
}
