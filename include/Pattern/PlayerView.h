//
// Created by aloys on 2018-11-17.
//

#ifndef RISK_PLAYERVIEW_H
#define RISK_PLAYERVIEW_H

#include "pattern/Observer.h"
#include "Player.h"
#include "Territory.h"

using namespace std;

class PlayerView : public Observer{
public:
    PlayerView();
    ~PlayerView();
    void Update();
    void headerUpdate(Player, string);
    void attackUpdate(Player, Player, bool, Territory, Territory);
    void fortifyUpdate(Player, Territory, Territory, int);
    void reinforceUpdate(Player, Territory, int);

};

#endif //RISK_PLAYERVIEW_H
