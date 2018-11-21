#pragma once
#ifndef RISK_STRATEGY_H
#define RISK_STRATEGY_H

#include <string>

using namespace std;

class Player;

class Strategy {
public:

    virtual void executeReinforce(Player*);
    virtual void executeAttack(Player*);
    virtual void executeFortify(Player*);

    virtual string toString();

    Strategy();
    ~Strategy();
};

#endif