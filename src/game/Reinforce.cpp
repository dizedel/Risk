//
// Created by pamel on 2018-11-03.
//
#include "game/Reinforce.h"

using namespace std;

Reinforce::Reinforce() {}

Reinforce::Reinforce(Player* player, Map map) {
    this->player = player;
    this->map= map;
}

Reinforce::Reinforce(Player* player, int numOfArmies, string ctry, Map map) {
    numOfArmiesToPutDown = numOfArmies;
    countryToReinforce = ctry;
    this->player = player;
    this->map = map;
}

Reinforce::~Reinforce() {

}

bool Reinforce::reinforce(){
    bool executed;
    if(player->hasCountry(countryToReinforce)){
        player->getCountries().at(player->posOfCountry(countryToReinforce)).addArmies(numOfArmiesToPutDown);
        player->setArmies(player->getArmies()-numOfArmiesToPutDown); //Remove armies from player after putting them down
        cout<<"You reinforced "<< numOfArmiesToPutDown << "on " << countryToReinforce  << endl;
        return true;
    }
    else{
        return false;
    }
}

void Reinforce::setNumOfArmiesToPutDown(int i) {
    numOfArmiesToPutDown = i;
}


void Reinforce::setCountryToReinforce(string s) {
    countryToReinforce = s;
}

