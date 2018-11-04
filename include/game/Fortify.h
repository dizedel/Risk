//
// Created by pamel on 2018-11-03.
//

#ifndef FORTIFY_H
#define FORTIFY_H

#pragma once

#include <string>
#include <vector>
#include <Map.h>
#include <Hand.h>
#include <Player.h>
#include "Phase.h"

using namespace std;

class Fortify: public Phase{

public:
    Fortify();
    Fortify(Player);
    ~Fortify();

    bool fortify(string, int);
    void giveArmiesForTerritory();

};

#endif //FORTIFY_H
