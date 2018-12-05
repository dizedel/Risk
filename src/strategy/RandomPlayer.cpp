//
// Created by aloys on 2018-11-28.
//
#include <Random>

#include "strategy/RandomPlayer.h"
#include "game/Reinforce.h"
#include "game/Attack.h"
#include "game/Fortify.h"


void RandomPlayer::executeReinforce(Player *p){

    Reinforce r;

    //Find a random country
    Territory randTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];

    r.setCountryToReinforce(randTerr.getName());
    r.setNumOfArmiesToPutDown(p->getArmies());
    r.reinforce();

}

// Not implemented right now
void RandomPlayer::executeAttack(Player *p){
    cout << "Random Player attacking" << endl;
}

void RandomPlayer::executeFortify(Player *p){

    Fortify f;

    //boolean is set to false, if two owned countries are adjacent then sets to true
    bool adjacent = false;
    //Get the territories the player owns
    vector<Territory> terrVec = p->getCountries();
    //Iterate through the vector of territories from beginning to before last
    for (vector<Territory>::iterator i = terrVec.begin(); i != terrVec.end() - 1; i++) {
        //Create a new iterator that is one farther of the other iterator
        //so it goes from 2nd to last element in the vector of territories
        vector<Territory>::iterator j = i++;
        //Get the neighbors of the first territory pointed to by iterator
        vector<string> tempNeighborVec = i->getNeighbors();
        //Check if the territory pointed to by the second iterator is a neighbor the first
        //territory pointed to by the second iterator, set adjacent to true if it is
        for (auto k : tempNeighborVec) {
            if (k == j->getName()) {
                adjacent = true;
            }
        }
    }
    if(!adjacent){
        cout << "No countries are adjacent. Fortify impossible." << endl;
        return;
    }

    //Check that the donor and receiver countries are adjacent
    Territory receiverRandTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];
    Territory donorRandTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];
    bool setAdjacent = false;
    while(!setAdjacent){
        //Find a random country and set it to be fortified
        //Find a random country and set it to be the donor of armies
        receiverRandTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];
        donorRandTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];

        //Check that both of the territories aren't the same and change the donor if they are
        //Check that the donor territory has more then 1 army placed on it
        while(receiverRandTerr.getName() == donorRandTerr.getName() || donorRandTerr.getArmies() > 1) {
            donorRandTerr = p->getCountries()[randomNumGen(size(p->getCountries()))];
        }

        //Check that the territories are adjacent
        vector<string> receiverNeighbors = receiverRandTerr.getNeighbors();
        for(auto i : receiverNeighbors){
            if(i == donorRandTerr.getName()){
                setAdjacent = true;
            }
        }
    }
    // set receiver and donor and number of armies
    // then fortify
    f.setCountryToFortify(receiverRandTerr.getName());
    f.setCountryToTakeFrom(donorRandTerr.getName());
    f.setNumOfTransferArmies(randomNumGen(donorRandTerr.getArmies()-1));
    f.fortify();

}

string RandomPlayer::toString(){
    return "Random Player";
}

int RandomPlayer::randomNumGen(int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, max);
    return dis(gen);
}