#include <game/Reinforce.h>
#include <Tournament.h>
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

MainGame::~MainGame(){
    instance=0;
}

void MainGame::playGame() {

    cout << "Game start" << endl;

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();

    while (keepPlaying)
    {

        Notify();

        cout<< "Player " << currentPlayer << " -- calling reinforcement phase" << endl;
        cout << playersInGame[currentPlayer].getStrategy()->toString();
        playersInGame[currentPlayer].doReinforce();
        cout << "test" <<endl;
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
               Tournament::getInstance()->addWinner(playersInGame[k].getStrategy()->toString());
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

void MainGame::playGame(int turnLimit) {

    cout << "Game start" << endl;
    cout << "After " << turnLimit << " turns, the current game will end in a draw!" << endl;

    bool keepPlaying = true;
    int currentPlayer = 0;
    int numberOfPlayers = playersInGame.size();
    int currentTurn=1;

    while (keepPlaying)
    {
        Notify();

        cout << "Current turn : #" << currentTurn << endl;

        cout<< "Player " << currentPlayer << " -- calling reinforcement phase" << endl;
        playersInGame[currentPlayer].doReinforce();
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
                Tournament::getInstance()->addWinner(playersInGame[k].getStrategy()->toString());
                keepPlaying = false;
                break;
            }
        }

        currentTurn++;

        if(currentTurn>turnLimit){
            cout << "Game ended in a draw." << endl;
            Tournament::getInstance()->addWinner("DRAW");
            break;
        }
    }
}