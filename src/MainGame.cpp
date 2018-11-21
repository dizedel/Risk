#include <game/Reinforce.h>
#include "MainGame.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include "Strategy.h"

using namespace std;

// applying singleton pattern to MainGame
MainGame* MainGame::instance=0;
MainGame* MainGame::getInstance(){
    if(instance==0){
        cout << "Singleton created" << endl;
        instance=new MainGame();
    }
    return instance;
}

MainGame::MainGame(){}

MainGame::MainGame(vector<Player> &players, Map &mapRef) {
    if(instance==0){
        playersInGame = players;
        map = mapRef;
        instance=this;
        cout << "Singleton created2" << endl;
    }
}

MainGame::~MainGame(){}

void MainGame::playGame() {

    cout << "Game start" << endl;

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();
/*
    for (int i = 0; i < playersInGame.size(); i++)
    {
        //reinforceVector.push_back(Reinforce{&playersInGame[i], map});
    }

    for(int k = 0; k < playersInGame.size(); k++){
        attackVector.push_back(Attack{playersInGame[k], &playersInGame, map});
    }

    for (int j = 0; j < playersInGame.size(); j++)
    {
        //fortifyVector.push_back(Fortify{&playersInGame[j], map});
    }
*/

    while (keepPlaying)
    {

        Notify();

        cout<< "Player " << currentPlayer + 1 << " -- calling reinforcement phase" << endl;
        cout << playersInGame[currentPlayer].getStrategy()->toString();


        playersInGame[currentPlayer].doReinforce();
        cout << "test";
        playersInGame[currentPlayer].doAttack();
        Notify();
        playersInGame[currentPlayer].doReinforce();

        currentPlayer++;

        if (currentPlayer == numberOfPlayers)
            currentPlayer = 0;

        for (int k = 0; k < playersInGame.size(); k++)
        {
            if (playersInGame[k].getCountries().size() == map.getNbTerritories()) {
               cout<< "WINNER: Player " << k + 1 << endl;
                keepPlaying = false;
                break;
            }
        }

    }
}




vector<Player>& MainGame::getPlayers() {
    return playersInGame;
}

Map MainGame::getMap() {
    return map;
}
