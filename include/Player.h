//
// Created by pamel on 2018-10-11.
//
#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "Territory.h"
#include "Dice.h"
#include "Hand.h"
#include "Map.h"

class Strategy;

class Player {
    public:
        Player();
        Player(string);
        Player(string, Strategy *);
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
        void setStartingArmy(int);
        void setStrategy(Strategy *strategy);



        void addCountry(Territory);
        void addArmies(int);


        void giveArmiesForTerritory();

        bool hasCountry(string);
        int posOfCountry(string);

        void reinforce(Player*);
        void attack(Player*);
        void fortify(Player*);

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
        Strategy *strategy;

};

#endif