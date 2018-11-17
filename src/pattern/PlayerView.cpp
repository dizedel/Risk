//
// Created by aloys on 2018-11-17.
//

#include "pattern/PlayerView.h"

using namespace std;

// UNFINISHED
void PlayerView::Update(){
    
}

void PlayerView::headerUpdate(Player p, string phase){
    cout << p.getName() << " : " << phase << " phase";
}

void PlayerView::attackUpdate(Player attacker, Player defender, bool boolTerritoryChange, Territory attackCountry, Territory defendCountry){
    if(boolTerritoryChange){
        cout << attacker.getName() << "(attacker) has conquered " << defendCountry.getName() << " from " << defender.getName() <<
        "(Number of armies : " << attackCountry.getArmies() << ") from " << attackCountry.getName() << "(Number of armies : "
        << defendCountry.getArmies() << ")." << endl;
    }else{
        cout << attacker.getName() << "(attacker) has failed to conquer " << defendCountry.getName() << " from " << defender.getName() <<
             "(Number of armies : " << attackCountry.getArmies() << ") from " << attackCountry.getName() << "(Number of armies : "
             << defendCountry.getArmies() << ")." << endl;
    }
}

void PlayerView::reinforceUpdate(Player p, Territory country, int numberOfArmiesAdded){
    cout << p.getName() << " has added " << numberOfArmiesAdded << " to " << country.getName()
    << ". Total number of armies on territory : " << country.getArmies() << endl;
}

void PlayerView::fortifyUpdate(Player p, Territory giver, Territory receiver, int numberOfArmiesGiven){
    cout << p.getName() << " has added " << numberOfArmiesGiven << " from " << giver.getName() << " to "
    << receiver.getName() << endl;
}

