//
// Created by pamel on 2018-11-18.
//

#include "strategy/AggressivePlayer.h"


void AggressivePlayer::executeReinforce(Player * p) {

    Reinforce r;
    //Find strongest territory
    vector<Territory*> countries = p->getCountries();
    Territory* max = p->getCountries()[0];
    for (int i = 0; p->getCountries().size(); i++)
    {
        if (p->getCountries()[i]->getArmies() > max->getArmies())
            max = p->getCountries()[i];
    }
    string strongestCountry = max->getName();
    r.setCountryToReinforce(strongestCountry);
    r.setNumOfArmiesToPutDown(p->getArmies());
    r.reinforce();
}


void AggressivePlayer::executeAttack(Player *) {

}
void AggressivePlayer::executeFortify(Player *) {

}