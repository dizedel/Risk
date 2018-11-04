//
// Created by pamel on 2018-11-03.
//
#ifndef FORTIFY_H
#define FORTIFY_H

#pragma once

#include <string>
#include <vector>
#include <Player.h>

using namespace std;

class Fortify{

public:
    Fortify(Player);
    ~Fortify();

    bool fortify(string, string, int);
    void playPhase();
    void giveArmiesForTerritory();

private:
    Player player;

};

#endif //FORTIFY_H
