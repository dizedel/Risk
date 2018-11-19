#pragma once
#include "Pattern/Observer.h"
#include "MainGame.h"
class GameStats: public Observer{
public:
    GameStats();
    GameStats(MainGame*);
    ~GameStats();
    void Update();
    void Display();


private:
    MainGame* mainGame;

};
