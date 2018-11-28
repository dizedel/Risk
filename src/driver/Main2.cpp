//
// Created by pamel on 2018-11-18.
//

#include <strategy/BenevolentPlayer.h>
#include <strategy/HumanPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <strategy/RandomPlayer.h>
#include <Player.h>
#include <vector>
#include "Map.h"

using namespace std;

int Hand::exchangedHands = 0;

int main(){
    vector<Player> playersInGame;
    Map map;
    //
    //This small demo is just to show that the actual structure of the Strategy pattern works
    //
    HumanPlayer *humanStrat = new HumanPlayer();
    cout<<"Creating new player"<< endl;
    Player p1("charlie");
    p1.setStrategy(humanStrat);
    cout<<"Name:  "<< p1.getName()<< endl;
    cout<<"Strategy:  "<< p1.getStrategy()->toString()<< endl;


    AggressivePlayer *aggressiveStrat = new AggressivePlayer();
    cout<<"Creating new player"<< endl;
    Player p2("charlie");
    p2.setStrategy(aggressiveStrat);
    cout<<"Name:  "<< p1.getName()<< endl;
    cout<<"Strategy:  "<< p1.getStrategy()->toString()<< endl;

    RandomPlayer *randomStrat = new RandomPlayer;
    cout << "Creating new player" << endl;
    Player p3("charlie");
    p3.setStrategy(randomStrat);
    cout << "Name : " << p3.getName() << endl;
    cout << "Strategy : " << p3.getStrategy()->toString() <<endl;


}