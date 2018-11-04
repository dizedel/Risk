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

using namespace std;

class Reinforce{

public:
    Reinforce();
    Reinforce(Player);
    ~Reinforce();

    void setPlayer(Player);

    void giveArmiesForTerritory();
    void playPhase();
    bool reinforce();


private:
    Player player;

};
#endif