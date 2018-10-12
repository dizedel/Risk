//
// Created by pamel on 2018-10-11.
//

#ifndef RISK_PLAYER_H
#define RISK_PLAYER_H

#include <string>
#include <vector>
#include "Territory.h"
#include "Dice.h"

using namespace std;

class Player {

public:
    Player();
    Player(string);
    ~Player();

    string getName();
    Dice getDice();
    vector<Territory> getTerritories();


    void setName(string);



private:
    string playerName;
    vector<Territory> territories;
    //vector<Card> cards;
    Dice dice;

};
#endif //RISK_PLAYER_H
