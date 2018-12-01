//
// Created by Ramy on 2018-11-28.
//
#pragma once
#include "Map.h"
#include "Player.h"

class Tournament {

private:
    static Tournament* instance;
    Tournament();
    int numOfPlayers=0;
    int numOfGames=0;
    int numOfTurns=0;
    int numOfMaps=0;
    vector<string> mapList;
    vector<Player> tournamentPlayers;
    vector<vector<string>> winnerStrategies;


public:
    static vector<vector<string>> winners;
    Tournament(int,int,int,int);
    static Tournament* getInstance();

    int getNumPlayers();
    int getNumTurns();
    int getNumGames();
    int getNumMaps();
    void setNumPlayers(int);
    void setNumTurns(int);
    void setNumGames(int);
    void setNumMaps(int);

    vector<string> getMapList();
    void setMapList(vector<string>);
    void addToMapList(string);
    void printMapList();

    bool allArmiesAssigned(vector<Player>*);
    void startupPhase(vector<Player>*, Map&);
    void playTournament();

    void setUpPlayers(int,vector<Player>*);
};