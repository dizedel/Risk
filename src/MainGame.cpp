#include "MainGame.h"

using namespace std;

MainGame::MainGame(Player players[]) {
    playersInGame = players;
}

void MainGame::playGame() {

    bool keepPlaying = true;
    int currentPlayer = 0;

    while (keepPlaying)
    {
        cout<< "player" << currentPlayer << ".reinforce() called" << endl;
        playersInGame[0].reinforce();
        cout<< "player" << currentPlayer << ".attack() called" << endl;
        playersInGame[0].attack(0,"");
        cout<< "player" << currentPlayer << ".fortify() called" << endl;
        playersInGame[0].fortify(0,"");

        currentPlayer++;

        if (currentPlayer == sizeof(playersInGame) / sizeof(playersInGame[0]))
            currentPlayer = 0;
    }
}

