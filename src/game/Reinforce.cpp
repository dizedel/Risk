//
// Created by pamel on 2018-11-03.
//
#include "game/Reinforce.h"

using namespace std;

Reinforce::Reinforce() {}

Reinforce::Reinforce(Map* m) {
    map= m;
}

Reinforce::Reinforce(Player* player, int numOfArmies, string ctry, Map* m) {
    numOfArmiesToPutDown = numOfArmies;
    countryToReinforce = ctry;
    map = m;
    this->player = player;
}

Reinforce::~Reinforce() {

}

bool Reinforce::reinforce(){
    bool executed;
    if(map->hasTerritory(countryToReinforce)){
        map->matchTerritory(countryToReinforce).addArmies(numOfArmiesToPutDown);
        return true;
    }
    else{
        return false;
    }
}

void Reinforce::setNumOfArmiesToPutDown(int i) {
    numOfArmiesToPutDown = i;
}
void Reinforce::setMap(Map* m){
    map = m;
};





