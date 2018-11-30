//
// Created by aloys on 2018-11-08.
//

#pragma once
#ifndef RISK_ATTACK_H
#define RISK_ATTACK_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Player.h>
#include <Dice.h>
#include <Territory.h>
//#include <Map.h>

using namespace std;

class Attack{

public:
    Attack();
    Attack(Player, vector<Player>*, Map&);
    ~Attack();
    void attack();
    bool attackOrNot();

    Territory attackingCountrySelection();
    string defendingCountry();
    void diceAttack();
    bool stopAttack();
    vector<string> filterNeighbors(vector<string>);
    bool wasTerritoryConquered();

    void setAttacker(Player);
    void setDefender(Player);
    void setAttackCountry(string);
    void setnumberOfArmiesAttack();
    void setNumberOfArmiesDefend();
    void setPlayerVector(vector<Player>*);
    void setMap(Map&);

    void autoAttack();

private:
    vector<Player>* pVector;
    Player attacker;
    Player defender;
    Territory attackCountry;
    Territory defendCountry;
    int numberOfArmiesAttack;
    int numberOfArmiesDefend;
    Map map;
    bool wasConquered=false;
    string sourceCountryName="";
    string targetCountryName="";
};


#endif //RISK_ATTACK_H
