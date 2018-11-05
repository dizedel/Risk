//
// Created by pamel on 2018-11-03.
//

#include <string>
#include <vector>
#include <Player.h>
#include "game/Fortify.h"

using namespace std;

Fortify::Fortify(Player p){
    player = p;
}

bool Fortify::fortify(string countryToFortify, string armyProvider, int){

    if (!player.hasCountry(countryToFortify) || !player.hasCountry(armyProvider))
        return false;
    else{
        return true;
    }
}

void Fortify::playPhase(){
    int numOfArmies;

    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's " << player.getName() <<"'s turn to reinforce!"<<endl;
    cout<< endl<< "---------------------------------------------"<< endl;

    while(true){
        string fortifiedCountry;
        string providerCountry;

        cout<< "Which country do you wish to fortify? If you are done, say 'done'";
        cin >> fortifiedCountry;

        if(fortifiedCountry == "done")
            break;
        else if (!player.hasCountry(fortifiedCountry)) {
            cout << "You do not have that country";
        }
        else{
            while(true) {
                cout << "Which country do you want to take armies from?" << endl;
                cin >> providerCountry;
                if (!player.hasCountry(providerCountry)) {
                    cout << "You do not have that country";
                }
                else if ( player.getCountries().at(player.posOfCountry(providerCountry)).getArmies() <= 1) {
                    cout << "You do not have enough armies to take from this country";
                }
                else {
                    cout<<"How many armies should we fortify with?";
                    cin >> numOfArmies;
                    int providerCountryArmies = player.getCountries().at(player.posOfCountry(providerCountry)).getArmies();
                    while(numOfArmies >= providerCountryArmies){
                        cout << "Provider country only has " << providerCountryArmies << " armies.";
                        cout << "Choose a number of Armies lower than " << providerCountryArmies;
                        cin >> numOfArmies;
                    }
                    player.getCountries().at(player.posOfCountry(fortifiedCountry)).addArmies(numOfArmies);              //Add armies to fortified country
                    player.getCountries().at(player.posOfCountry(providerCountry)).setArmies(providerCountryArmies - numOfArmies); // Remove armies from provider country
                    break;
                }
            }
        }
    }

}

