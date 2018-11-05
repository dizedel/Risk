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

    while(true){
        string fortifiedCountry;
        string providerCountry;

        cout<< "Which country do you wish to fortify? If you are done, say 'done'";
        cin >> fortifiedCountry;

        if(fortifiedCountry == "done")
            break;
        else if (player.hasCountry(fortifiedCountry)) {
            cout << "You do not have that country";
        }

        else{
            cout<<"Which country do you want to take armies from?" << endl;
            cin >> providerCountry;
            cout << "How many armies do you want to use?" << endl;
            //Todo: Print out how many armies are available for use
        }
    }
}

