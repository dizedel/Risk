//
// Created by pamel on 2018-11-18.
//

#include "strategy/AggressivePlayer.h"
void AggressivePlayer::executeReinforce(Player * p) {

    //Find strongest territory
    vector<Territory*> countries = p->getCountries();
    for(int i ; i<countries.size(); i++){
        countries.at(i)->getArmies();
    }

}


void AggressivePlayer::executeAttack(Player *) {

}
void AggressivePlayer::executeFortify(Player *) {

}