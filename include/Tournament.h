#pragma once
#include "stdafx.h"

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
        vector<string> winnerList;
        vector<vector<string>> winnersInTabularForm;


    public:
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
        void addToMapList(string);
        void printMapList();

        bool allArmiesAssigned(vector<Player>*);
        void startupPhase(vector<Player>*, Map&);
        void playTournament();

        void setUpPlayers(int,vector<Player>*);

        void addWinner(string);
        void displayResults();
};
