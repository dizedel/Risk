#include "MainGame.h"
#include "game/Reinforce.h"
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


    while (keepPlaying)
    {
        playersInGame[currentPlayer].play();

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

