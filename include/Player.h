//
// Created by pamel on 2018-10-11.
//
#pragma once
#include <string>
#include <vector>
#include "Territory.h"
#include "Dice.h"
#include "Hand.h"
#include "Map.h"

using namespace std;

class Player {

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

        void addCountry(string);
        void addArmies(int);
        bool addTerritory(string , Map);

        void giveArmiesForTerritory();

        int hasCountry(string);
        void reinforce();
        void attack(int, string);
        void fortify(int, string);

        string displayCountries();

    private:
        string playerName;                      //player's name as an identifier
        int numOfExchanges;                     //number of times the player has exchanged his cards for armies
        int armies;
        vector<Territory> countries;
        Hand hand;
        Dice dice;

};