//
// Created by pamel on 2018-11-18.
//

#include <strategy/BenevolentPlayer.h>
#include <Player.h>
#include <vector>
#include "Map.h"
using namespace std;

int Hand::exchangedHands = 0;

int main(){

    vector<Player> playersInGame;
    Map map;
    Strategy *benevolentPlayer = new BenevolentPlayer();
    Player p1("charlie", benevolentPlayer);

    playersInGame.push_back(p1);
    MainGame mainGame {playersInGame, map};
    mainGame.playGame();

}