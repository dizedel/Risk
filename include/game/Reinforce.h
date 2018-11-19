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
#include <MainGame.h>

using namespace std;

class Reinforce{

public:
    Reinforce();
    Reinforce(Map*);
    Reinforce(Player*, int, string, Map*);
    ~Reinforce();

    void playPhase();
    bool reinforce();

    void setCountryToReinforce(string);
    void setNumOfArmiesToPutDown(int);
    void setMap(Map*);


private:
    string countryToReinforce;
    int numOfArmiesToPutDown;
    Player* player;
    Map* map;

};
#endif