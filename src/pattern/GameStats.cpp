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
    vector<Player> players = mainGame->getPlayers();
    int territoriesOnMap = mainGame->getMap().getNbTerritories();
    float percentageOccupied;

    cout << "####### Game Stat View #######" << endl;
    cout << "Territories on map: " << territoriesOnMap << endl;
    cout << "Player         Armies      Territories      Percentage of map Occupied" << endl;
    for(int i=0; i<players.size(); i++){
        Player p = players.at(i);

        int territoriesOccupied = players.at(i).getCountries().size();
        percentageOccupied = ((float)(territoriesOccupied)/(float)territoriesOnMap)*100;

        cout << p.getName() << " \t";
        cout << " " << p.getArmies() << " \t\t";
        cout << " " << territoriesOccupied << " \t\t\t";
        cout << " " << percentageOccupied << "%" << endl;
    }
    cout << "##############################" << endl;
}

