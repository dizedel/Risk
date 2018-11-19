#pragma once
#ifndef RISK_STRATEGY_H
#define RISK_STRATEGY_H

#include "Player.h"

class Player;

class Strategy {
public:

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);

    virtual ~Strategy();
};

#endif