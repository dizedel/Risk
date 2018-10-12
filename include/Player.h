//
// Created by pamel on 2018-10-11.
//
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Territory.h"
#include "Dice.h"
#include "Hand.h"

using namespace std;

class Player {

    public:
        Player();
        Player(string);
        ~Player();

        string getName();
        Dice getDice();
        vector<Territory> getCountries();

        void setName(string);
        void setCountries(vector<Territory>);
        //void setCards(vector<Card>);
        void addArmies(int);
        void addTerritories(Territory);
        //void addCard(Card);

        void giveArmiesForTerritory();

        int hasCountry(string);
        void reinforce();
        void attack(int, string);
        void fortify(int, string);

    private:
        string playerName;                      //player's name as an identifier
        int numOfExchanges;                     //number of times the player has exchanged his cards for armies
        int armies;
        vector<Territory> countries;
        Hand hand;
        Dice dice;

};
#endif