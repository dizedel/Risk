#include <game/Reinforce.h>
#include "MainGame.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include "strategy/Strategy.h"

using namespace std;

MainGame::MainGame(){}

MainGame::MainGame(vector<Player> &players, Map &mapRef) {
    playersInGame = players;
    map = mapRef;
}

MainGame::~MainGame(){}

void MainGame::playGame() {

    cout << "Game start" << endl;

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();

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


    while (keepPlaying)
    {
        Notify();

        cout<< "Player " << currentPlayer + 1 << " -- calling reinforcement phase" << endl;
        cout << playersInGame[currentPlayer].getStrategy().toString();
        playersInGame[currentPlayer].getStrategy().executeReinforce(&playersInGame[currentPlayer]);

        cout<< "Player" << currentPlayer + 1 << " attack() called" << endl;
        attackVector[currentPlayer].attack();
        if (attackVector[currentPlayer].wasTerritoryConquered() == true){
            Notify();
        }
        cout<< "Player" << currentPlayer + 1 << " -- Fortify::playPhase() called" << endl;
       // playersInGame[currentPlayer].doFortify(&playersInGame[currentPlayer]);
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
