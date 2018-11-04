#include "MainGame.h"

using namespace std;

MainGame::MainGame(vector<Player> &players) {
    playersInGame = players;
}

void MainGame::playGame() {

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();
    

    while (keepPlaying)
    {
        cout<< "player" << currentPlayer << ".reinforce() called" << endl;
        playersInGame[currentPlayer].reinforce();
        cout<< "player" << currentPlayer << ".attack() called" << endl;
        playersInGame[currentPlayer].attack(0,"");
        cout<< "player" << currentPlayer << ".fortify() called" << endl;
        playersInGame[currentPlayer].fortify(0,"");

        currentPlayer++;

        if (currentPlayer == numberOfPlayers)
            currentPlayer = 0;
    }
}

