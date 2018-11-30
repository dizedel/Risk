//
// Created by Ramy on 2018-11-28.
//
#pragma once
#include "Map.h"
#include "Player.h"

class tournament {

private:

public:
    tournament();
    void startupPhase(vector<Player> *vp, Map &map1);
    bool allArmiesAssigned(vector<Player> *vp);
};
