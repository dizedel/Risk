//
// Created by pamel on 2018-11-18.
//
#pragma once
#ifndef RISK_STRATEGY_H
#define RISK_STRATEGY_H


#include <string>
#include <vector>
#include <Map.h>
#include <Hand.h>
#include "Player.h"

using namespace std;


class Strategy{

public:
    Strategy();
    ~Strategy();

    void doAttack();
    void doReinforce();
    bool doFortify();


private:
    Player p;
};

#endif

