//
// Created by pamel on 2018-10-11.
//
#pragma once
#include "stdafx.h"

#include <string>
#include <vector>
#include "Territory.h"
#include "Dice.h"
#include "Hand.h"
#include "Map.h"
#include "Player.h"
#include "Pattern/Subject.h"

using namespace std;

class PlayerView;

class Player: public Subject {

    public:
        Player();
        Player(string);
        ~Player();

        string getName();
        Dice getDice();
        Hand getHand();
        vector<Territory> getCountries();
        int getArmies();

        void setName(string);
        void setCountries(vector<Territory>);
        void setHand(Hand);
        void setArmies(int);

        void addCountry(Territory);
        void addArmies(int);
        void setStartingArmy(int);



        void giveArmiesForTerritory();

        bool hasCountry(string);
        int posOfCountry(string);
        void reinforce();
        void attack(int, string);
        void fortify(int, string);

        string displayCountries();

        void addTerritory(Territory);

        void setInitialArmies(int);
        int getInitialArmies();
        void assignInitialArmyToCountry(int);



    private:
        string playerName;                      //player's name as an identifier
        int numOfExchanges;                     //number of times the player has exchanged his cards for armies
        int armies=0;
        vector<Territory> countries;
        Hand hand;
        Dice dice;
        int initialArmies=0;



};