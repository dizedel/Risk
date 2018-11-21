//
// Created by pamel on 2018-11-03.
//

#include <string>
#include <vector>
#include <Player.h>
#include "game/Fortify.h"

using namespace std;

Fortify::Fortify(){}

Fortify::Fortify(Player* p, int numOfArmies, string providerCountry, string fortifiedCountry){
    player = p;
    numOfArmiesToUse = numOfArmies;
    countryToTakeFrom = providerCountry;
    countryToFortify = fortifiedCountry;
}

Fortify::Fortify(Player* player, Map map) {
    this->player = player;
    this->map= map;
}

Fortify::~Fortify(){}

bool Fortify::fortify(){
    player->getCountries().at(player->posOfCountry(countryToFortify)).addArmies(numOfArmiesToUse);   //Add armies to fortified country
    player->getCountries().at(player->posOfCountry(countryToTakeFrom)).setArmies(-numOfArmiesToUse); // Remove armies from provider country
    return true;
}

void Fortify::setCountryToTakeFrom(string c) {
    countryToTakeFrom = c;
}

void Fortify::setCountryToFortify(string c) {
    countryToFortify = c;
}

void Fortify::setNumOfTransferArmies(int i) {
    numOfArmiesToUse = i;
}