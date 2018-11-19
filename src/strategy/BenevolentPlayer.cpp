//
// Created by pamel on 2018-11-18.
//
#include <iostream>
#include <Player.h>
#include <strategy/BenevolentPlayer.h>

#include "strategy/BenevolentPlayer.h"


using namespace std;

void BenevolentPlayer::executeReinforce(Player* p) {

}
void BenevolentPlayer::executeAttack(Player *) {

    cout << "The player does not wish to attack." << endl;
}
void BenevolentPlayer::executeFortify(Player *) {

}


void BenevolentPlayer::giveArmiesForTerritory(Player* player){
    //Todo: round down
    int newArmies = player->getCountries().size()/3;
    cout << "Giving you " << newArmies << " more armies.\n";
    player->addArmies(newArmies);
    cout << "Your total number of armies is now: " << player->getArmies() << endl;
    //TODO: give armies for entire continent
}

string BenevolentPlayer::weakestCountry(Player* player) {

    Territory* min = player->getCountries()[0];

    for (int i = 0; player->getCountries().size(); i++)
    {
        if (player->getCountries()[i]->getArmies() < min->getArmies())
            min = player->getCountries()[i];
    }

    return min->getName();
}


bool BenevolentPlayer::reinforceLoop(Player* player){
    string str;
    /******************
     * REINFORCE LOOP
     *****************/
    if(player->getArmies()>= 1) {
        while (player->getArmies()>=1) {
            cout <<"You have --- " << player->getArmies() <<" --- armies. Which countries do you wish to reinforce? Enter 'done' if you do not wish to." << endl;
            //getline(cin, str);
            str = weakestCountry(player);
            if (str == "done") {
                break;
            }
            else if (player->hasCountry(str)) {
                int countryPos = player->posOfCountry(str);
                int numOfArmies = 0;
                bool finished = false;
                while (!finished) {
                    int n;
                    cout << "How many armies do you wish to place?" << endl;
                    cin>>n;
                    if (floor(n) == n && n > 0) {
                        player->setArmies(player->getArmies() - n);
                        player->getCountries().at(countryPos).addArmies(n);
                        //cout << "You have added " << n << "armies to " << player.getCountries().at(countryPos).getName() <<endl;
                        cout << player->getCountries().at(countryPos).getName() << " now has " << player->getCountries().at(countryPos).getArmies() << " armies \n";
                        finished = true;
                    }
                    else{
                        cout << "Please enter a valid output" << endl;
                        delete(&n);
                    }
                }
            }
            else {
                cout << "Value : " << player->hasCountry(str)<< endl;
                cout << "You do not have this country" << endl;
            }
        }
    }
    else{
        cout<< "You do not have enough armies to reinforce at the moment" << endl;
    }
    return true;
}

void BenevolentPlayer::playPhase(Player* player) {
    string txtline;
    bool answered = false;

    giveArmiesForTerritory(player);

    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's " << player->getName() <<"'s turn to reinforceLoop!"<<endl;
    cout<< endl<< "---------------------------------------------"<< endl;

    int armiesFromLand = floor(double(player->getCountries().size()/3));
    cout << player->getName() << " current armies: " << player->getArmies() << endl;
    player->addArmies(armiesFromLand);
    cout << player->getName() << " was given: " << armiesFromLand << " armies" << endl;
    cout << "Player has a total of " << player.getArmies() << endl;

    /**
     * EXCHANGE CARDS
     */
    while (true) {
        cout << "Do you wish to exchange your cards?" << endl;
        //cin >> txtline;
        string txtline = "yes";

        if (txtline == "yes" || txtline == "no") {
            if (txtline == "yes"){
                int exchangedCards = player->getHand().exchange();
                if (exchangedCards == 0) {
                    cout << "You have no cards to exchange this round." << endl ;
                    break;
                }
                else{
                    cout<< "Your cards have been exchanged for " << exchangedCards << " armies";
                    break;
                }
            }
            else if (txtline == "no"){
                cout << "No problem, moving along...." << endl;
                break;
            }
        }
        else {
            cout << "Not a valid answer. Please answer 'yes' or 'no'" << endl;
        }
    }

    reinforceLoop(player);
}
