#include "MainGame.h"
#include "game/Fortify.h"
#include "game/Attack.h"

using namespace std;

MainGame::MainGame(){}

MainGame::MainGame(vector<Player> &players, Map &mapRef) {
    playersInGame = players;
    map = mapRef;
}

MainGame::~MainGame(){}

void MainGame::playGame() {

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();

    for (int i = 0; i < playersInGame.size(); i++)
    {
        //reinforceVector.push_back(Reinforce{playersInGame[i]});
    }

    for(int k = 0; k < playersInGame.size(); k++){
        attackVector.push_back(Attack{playersInGame[k], playersInGame, map});
    }

    for (int j = 0; j < playersInGame.size(); j++)
    {
        fortifyVector.push_back(Fortify{playersInGame[j]});
    }


    while (keepPlaying)
    {
        cout<< "Player " << currentPlayer + 1 << " -- Reinforce::playPhase() called" << endl;
        //reinforceVector[currentPlayer].playPhase();
        cout<< "Player" << currentPlayer + 1 << " attack() called" << endl;
        attackVector[currentPlayer].attack();
        cout<< "Player" << currentPlayer + 1 << " -- Fortify::playPhase() called" << endl;
        fortifyVector[currentPlayer].playPhase();

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


Map MainGame::getMap() {
    return map;
}


