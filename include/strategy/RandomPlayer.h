//
// Created by aloys on 2018-11-28.
//

#ifndef RISK_RANDOMPLAYER_H
#define RISK_RANDOMPLAYER_H


#include <string>
#include "Player.h"
#include "Strategy.h"
using namespace std;

class RandomPlayer: public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);
    string toString();
    int randomNumGen(int);

};

#endif //RISK_RANDOMPLAYER_H
