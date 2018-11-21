#pragma once
#ifndef RISK_STRATEGY_H
#define RISK_STRATEGY_H

#include "Player.h"
#include "game/Reinforce.h"
#include "game/Attack.h"
#include "game/Fortify.h"

class Player;

class Strategy {
public:

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);

    string toString();

    virtual ~Strategy();
};

#endif