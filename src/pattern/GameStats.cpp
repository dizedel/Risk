#include "Pattern/GameStats.h"

GameStats::GameStats(){}

GameStats::GameStats(MainGame* mg){
    mainGame=mg;
    mainGame->Attach(this);
}

GameStats::~GameStats(){
    mainGame->Detach(this);
}

void GameStats::Update(){
    Display();
}

void GameStats::Display(){
    cout << "####### Game Stat View #######" << endl;
    cout << "Player #\t Armies #\t Territories #\t Percentage of map Occupied";

    vector<Player> players = mainGame->getPlayers();
    int territoryCount = mainGame->getMap().getNbTerritories();

    for(int i=0; i<players.size(); i++){
        Player p =players.at(i);

        double percentageOccupied = (p.getCountries().size())/territoryCount;

        cout << p.getName() << " \t";
        cout << " " << p.getArmies() << " \t";
        cout << " " << p.getCountries().size() << " \t";
        cout << " " << percentageOccupied << endl;
    }
}

