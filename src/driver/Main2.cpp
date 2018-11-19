//
// Created by pamel on 2018-11-18.
//

#include <strategy/BenevolentPlayer.h>
#include <Player.h>

int Hand::exchangedHands = 0;

int main(){
    Strategy *benevolentPlayer = new BenevolentPlayer();
    Player p1("charlie", benevolentPlayer);

}