//
// Created by pamel on 2018-11-03.
//
#ifndef FORTIFY_H
#define FORTIFY_H

#pragma once

#include <string>
#include <vector>
#include <Player.h>

using namespace std;

class Fortify{

public:
    Fortify();
    Fortify(Player*, int , string, string);
    Fortify(Player*, Map);
    ~Fortify();

    void setCountryToFortify(string);
    void setCountryToTakeFrom(string);
    void setNumOfTransferArmies(int);

    bool fortify();

private:
    Player* player;
    string countryToFortify;
    string countryToTakeFrom;
    int numOfArmiesToUse;
    Map map;

};

#endif //FORTIFY_H
