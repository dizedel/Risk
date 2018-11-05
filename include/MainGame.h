#pragma once

#include "Player.h"
#include "game/Reinforce.h"
#include "game/Fortify.h"
#include <vector>

class MainGame {

private:

    vector<Player> playersInGame;
    vector<Fortify> fortifyVector;
    vector<Reinforce> reinforceVector;
    Map map;

public:
    MainGame(vector<Player>&, Map&);
    ~MainGame();
    void playGame();

};

