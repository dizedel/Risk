//
// Created by aloys on 2018-11-17.
//

#ifndef RISK_PLAYERVIEW_H
#define RISK_PLAYERVIEW_H

#include "Pattern/Observer.h"
#include "Player.h"
#include "Map.h"
#include "Territory.h"

using namespace std;

class PlayerView : public Observer{
public:
    PlayerView();
    PlayerView(Player* p);
    ~PlayerView();
    PlayerView(Map);
    void Update();
    void headerUpdate(Player, string);
    void attackUpdate(Player, Player, bool, Territory, Territory);
    void fortifyUpdate(Player, Territory, Territory, int);
    void reinforceUpdate(Player, Territory, int);
private:
    vector<Territory> theMap;
    Player* _player;

};

#endif //RISK_PLAYERVIEW_H
