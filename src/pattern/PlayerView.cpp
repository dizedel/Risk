//
// Created by aloys on 2018-11-17.
//
#include <vector>
#include "Player.h"
#include "Map.h"
#include "pattern/PlayerView.h"

using namespace std;

PlayerView::PlayerView(Map m){
    theMap = m.getTerritory();
}

void PlayerView::Update(){
    for(auto i : theMap){
        cout << i.getName() << " - Number Of Armies : " << i.getArmies()
             << " and owned by : " << i.getTerritoryOwner() << endl;
    }
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

