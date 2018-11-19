#pragma once

#include "Player.h"
//#include "game/Reinforce.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include <vector>
#include "Pattern/Subject.h"


using namespace std;

class MainGame : public Subject{


private:

    vector<Player> playersInGame;
    vector<Fortify> fortifyVector;
    vector<Attack> attackVector;
    //vector<Reinforce> reinforceVector;
    Map map;

public:
    MainGame();
    MainGame(vector<Player>&, Map&);
    ~MainGame();
    void playGame();
    vector<Player> getPlayers();
    Map getMap();

    Map getMap();

};

