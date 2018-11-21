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

    cout << "########################## Game Stat View ############################" << endl;
    cout << "======================================================================" << endl;
    cout << "Player         Armies      Territories      Percentage of map Occupied" << endl;
    cout << "======================================================================" << endl;
    for(int i=0; i<players.size(); i++){
        Player p = players.at(i);
        int territoriesOccupied = players.at(i).getCountries().size();

        percentageOccupied = ((float)(territoriesOccupied)/(float)territoriesOnMap)*100;

        cout << p.getName() << " \t\t";
        cout << " " << p.getArmies() << " \t\t";
        cout << " " << territoriesOccupied << " \t\t\t";
        cout << " " << percentageOccupied << "%" << endl;

        if(percentageOccupied==100){
            cout << "Congratulations to " << p.getName() << " for winning the game!" << endl;
            exit(0);
        }
    }

    cout << "###########################################################" << endl;
    cout << "===========================================================" << endl;
    cout << "Territory                  Occupier                  Armies" << endl;
    cout << "===========================================================" << endl;
    string territoryInfo="";
    string tName="";
    string tOccupier="";
    int tArmies=0;
    for(Player p : players){
        for(int i=0; i<p.getCountries().size(); i++){
            tName = p.getCountries().at(i).getName();
            tOccupier = p.getCountries().at(i).getTerritoryOwner();
            tArmies = p.getCountries().at(i).getArmies();
            territoryInfo = territoryInfo + tName + " \t\t" + tOccupier + " \t\t" + to_string(tArmies) + "\n";
        }
    }
    cout << territoryInfo;
    cout << "###########################################################" << endl;
}

