//
// Created by pamel on 2018-11-04.
//

//
// Created by pamel on 2018-10-11.
//
#pragma once
#ifndef FORTIFY_H
#define FORTIFY_H

#include <string>
#include <vector>
#include <Player.h>

using namespace std;

class Fortify {

public:
    Fortify();
    ~Fortify();

    Player getPlayer();
    void playPhase();
    bool fortify(string, int);



private:
    Player player;

};
#endif