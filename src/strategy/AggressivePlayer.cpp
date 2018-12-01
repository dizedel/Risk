//
// Created by pamel on 2018-11-18.
//

#include "strategy/AggressivePlayer.h"
#include "game/Reinforce.h"
#include "game/Attack.h"
#include "game/Fortify.h"


void AggressivePlayer::executeReinforce(Player * p) {

    Reinforce r;

    //Find strongest territory
    Territory max = p->getCountries()[0];
    for (int i = 0; p->getCountries().size(); i++) {
        if (p->getCountries()[i].getArmies() > max.getArmies())
            max = p->getCountries()[i];
    }
    r.setCountryToReinforce(max.getName());
    r.setNumOfArmiesToPutDown(p->getArmies());
    r.reinforce();
}


void AggressivePlayer::executeAttack(Player * p) {
    cout<< "-----An aggressive player is now attacking ---------"<< endl;
    int diceRolls = 3;

    Attack a;
    Map map = MainGame::getInstance()->getMap();
    a.setMap(map);
    a.setAttacker(*p);
    vector<Territory*> ownedCountries = (map.getPlayerCountries(p->getName()));

    //Will attack with all countries until it cannot attack anymore
    for(int i=0; i<ownedCountries.size(); i++){
        if (ownedCountries.at(i)->getArmies()<=1){                  //Country doesn't have enough armies
            continue;                                               //If all countries have less than 1 army the turn will be over
        }
        else if (ownedCountries.at(i)->getNeighbors().size()==0){   //Country has no neighbours
            continue;
        }
        else{
            i = 0;                                                  //We will restart the loop
            int numOfDice = 3;                                      //An aggressive player will always roll 3 dice
            a.autoAttack(numOfDice);
        }

    }

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
    if(max.getArmies() > 1){
        f.setCountryToTakeFrom(max.getName());
        f.setNumOfTransferArmies(p->getArmies());
        f.fortify();
    }
    else{
        cout << "There are no countries to take armies from" << endl << "Moving along...";
    }
}

string AggressivePlayer::toString() {
    return "Aggressive Player";
}