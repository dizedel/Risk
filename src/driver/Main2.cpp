//
// Created by pamel on 2018-11-18.
//

#include <strategy/BenevolentPlayer.h>
#include <strategy/HumanPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <Player.h>
#include <vector>
#include "Map.h"
using namespace std;

int Hand::exchangedHands = 0;

int main(){

    vector<Player> playersInGame;
    Map map;
    HumanPlayer *strategy = new HumanPlayer();
    Player p1("charlie");
    p1.setStrategy(strategy);
    p1.getStrategy();

}
