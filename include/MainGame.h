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

public:
    MainGame(vector<Player>&);
    ~MainGame();
    void playGame();

};

