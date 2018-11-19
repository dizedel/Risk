//
// Created by pamel on 2018-11-18.
//

#include "strategy/AggressivePlayer.h"
void AggressivePlayer::executeReinforce(Player * p) {

    //Find strongest territory
    vector<Territory*> countries = p->getCountries();
    Territory* max = p->getCountries()[0];
    for (int i = 0; p->getCountries().size(); i++)
    {
        if (p->getCountries()[i]->getArmies() > max->getArmies())
            max = p->getCountries()[i];
    }
    string strongestCountry = max->getName();


}


void AggressivePlayer::executeAttack(Player *) {

}
void AggressivePlayer::executeFortify(Player *) {

}