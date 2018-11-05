#include "MainGame.h"
#include "game/Reinforce.h"
#include "game/Fortify.h"

using namespace std;

MainGame::MainGame(vector<Player> &players) {
    playersInGame = players;
}

void MainGame::playGame() {

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();

    for (int i = 0; i < playersInGame.size(); i++)
    {
        reinforceVector.push_back(Reinforce{playersInGame[i]});
    }

    for (int j = 0; j < playersInGame.size(); j++)
    {
        fortifyVector.push_back(Fortify{playersInGame[j]});
    }


    while (keepPlaying)
    {
        cout<< "Player " << currentPlayer + 1 << " -- Reinforce::playPhase() called" << endl;
        reinforceVector[currentPlayer].playPhase();
        cout<< "Player" << currentPlayer + 1 << " attack() called" << endl;

        cout<< "Player" << currentPlayer + 1 << " -- Fortify::playPhase() called" << endl;
        fortifyVector[currentPlayer].playPhase();

        currentPlayer++;

        if (currentPlayer == numberOfPlayers)
            currentPlayer = 0;
    }
}

