#pragma once
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
