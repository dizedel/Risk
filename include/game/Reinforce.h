//
// Created by pamel on 2018-10-11.
//
#pragma once
#ifndef REINFORCE_H
#define REINFORCE_H

#include <string>
#include <vector>
#include <Map.h>
#include <Hand.h>
#include <Player.h>
#include "Phase.h"

using namespace std;

class Reinforce: public Phase{

public:
    Reinforce();
    Reinforce(Player);
    ~Reinforce();

    bool reinforce(string, int);
    void giveArmiesForTerritory();

private:
    Player player;

};
#endif