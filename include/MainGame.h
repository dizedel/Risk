#pragma once

#include "Player.h"
#include <vector>

class MainGame {

private:

    vector<Player> playersInGame;

public:
    MainGame(vector<Player>);
    ~MainGame();
    void playGame();

};

