//
// Created by pamel on 2018-11-03.
//
#include "game/Reinforce.h"

using namespace std;

Reinforce::Reinforce() {}

Reinforce::Reinforce(Player p) {
    player = p;
}

Reinforce::~Reinforce()
{
}

void Reinforce::setPlayer(Player p) {
    player = p;
}


void Reinforce::giveArmiesForTerritory(){
    //Todo: round down
    int newArmies = player.getCountries().size()/3;
    cout << "Giving you " << newArmies << " more armies.\n";
    player.addArmies(newArmies);
    cout << "Your total number of armies is now: " << player.getArmies() << endl;
    //TODO: give armies for entire continent
}


bool Reinforce::reinforce(){
    string str;
    /******************
     * REINFORCE LOOP
     *****************/
    if(player.getArmies()>= 1) {
        while (player.getArmies()>=1) {
            cout <<"You have --- " << player.getArmies() <<" --- armies. Which countries do you wish to reinforce? Enter 'done' if you do not wish to." << endl;
            cin >> str;
            if (str == "done") {
                break;
            }
            else if (player.hasCountry(str)) {
                int numOfArmies = 0;
                bool finished = false;
                while (!finished) {
                    cout << "How many armies do you wish to place?" << endl;
                    cin >> numOfArmies;
                    if (floor(numOfArmies) == numOfArmies && numOfArmies > 0) {
                        player.setArmies(player.getArmies() - numOfArmies);
                        player.getCountries().at(player.hasCountry(str)).addArmies(numOfArmies);
                        finished = true;
                    }
                    else
                        cout << "Please enter a valid output" << endl;
                }
            }
            else {
                cout << "Value : " << player.hasCountry(str)<< endl;
                cout << "You do not have this country" << endl;
            }
        }
    }
    else{
        cout<< "You do not have enough armies to reinforce at the moment" << endl;
    }
    return true;
}

void Reinforce::playPhase() {
    string txtline;
    bool answered = false;

    giveArmiesForTerritory();

    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's " << player.getName() <<"'s turn to reinforce!"<<endl;
    cout<< endl<< "---------------------------------------------"<< endl;


    /**
     * EXCHANGE CARDS
     */
    while (true) {
        cout << "Do you wish to exchange your cards?" << endl;
         cin >> txtline;

             if (txtline == "yes" || txtline == "no") {
                 if (txtline == "yes"){
                     int exchangedCards = player.getHand().exchange();
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
                 cout << "Not a valid answer. Please answer 'yes' or 'no'";
             }
    }

    reinforce();
}






