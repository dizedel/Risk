//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_AGGRESSIVEPLAYER_H
#define RISK_AGGRESSIVEPLAYER_H


#include "Player.h"
#include <string>
#include "Strategy.h"
using namespace std;

class AggressivePlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);
    string toString();

};

#endif //RISK_AGGRESSIVEPLAYER_H
