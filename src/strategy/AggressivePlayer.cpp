//
// Created by pamel on 2018-11-18.
//

#include "strategy/AggressivePlayer.h"


void AggressivePlayer::executeReinforce(Player * p) {

    Reinforce r;
    //Find strongest territory
    Territory max = p->getCountries()[0];
    for (int i = 0; p->getCountries().size(); i++)
    {
        if (p->getCountries()[i].getArmies() > max.getArmies())
            max = p->getCountries()[i];
    }
    string strongestCountry = max.getName();
    r.setCountryToReinforce(strongestCountry);
    r.setNumOfArmiesToPutDown(p->getArmies());
    r.reinforce();
}


void AggressivePlayer::executeAttack(Player *) {


}
void AggressivePlayer::executeFortify(Player * p) {

    Fortify f;
    //Find strongest territory
    Territory max = p->getCountries()[0];
    for (int i = 0; p->getCountries().size(); i++)
    {
        if (p->getCountries()[i].getArmies() > max.getArmies())
            max = p->getCountries()[i];
    }
    cout << "Aggressive player found " << max.getName() << "to be the strongest Country with "<< max.getArmies();
    f.setCountryToFortify(max.getName());

    for (int i = 0; p->getCountries().size(); i++)
    {
        max = p->getCountries()[0];
        if (p->getCountries()[i].getName() == max.getName())            //If the name of the country is the same as the name of the country fortified
            continue;
        else if(p->getCountries()[i].getArmies() <= 1)                  // If the country has 1 or less armies it is invalid
            continue;
        else if (p->getCountries()[i].getArmies() > max.getArmies())
            max = p->getCountries()[i];
    }
    if(max.getArmies() >= 1){
        f.setCountryToTakeFrom(max.getName());
        f.setNumOfTransferArmies(p->getArmies());
        f.fortify();
    }
    else{
        cout << "There are no countries to take armies from" << endl << "Moving along...";
    }



}