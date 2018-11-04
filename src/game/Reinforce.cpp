//
// Created by pamel on 2018-11-03.
//
#include <game/Reinforce.h>
#include "/game/Reinforce.h"

using namespace std;

Reinforce::Reinforce() {}

Reinforce::Reinforce(Player player) {
    setPlayer(player);
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
    cout << "Giving you " << newArmies << " more armies.";
    player.addArmies(newArmies);
    cout << "Your total number of armies is now: " << player.getArmies();
    //TODO: give armies for entire continent
}


/***********************************************************
 *              REINFORCEMENT LOOP
 * *********************************************************
 */
void Reinforce::playPhase() {
    string txtline;
    bool answered = false;

    giveArmiesForTerritory();

    /**
     * EXCHANGE CARDS
     */
    while (true) {

        cout << "Do you wish to exchange your cards?";
         cin >> txtline;

             if (txtline == "yes" || txtline == "no") {
                 if (txtline == "yes"){
                     int exchangedCards = player.getHand().exchange();
                     if (exchangedCards == 0) {
                         cout << "You have no cards to exchange this round.";
                         break;
                     }
                 }
                 cout << "No problem, moving along....";
                 break;
             }
             else {
                 cout << "Not a valid answer. Please answer 'yes' or 'no'";
             }
    }


    /*
     * REINFORCE LOOP
     */
    if(player.getArmies()>= 3) {
        while (!answered && player.getArmies() >= 3) {
            cout << "Which countries do you wish to reinforce? Enter 'Done' if you do not wish to";
            getline(cin, txtline);
            if (txtline == "Done") {
                answered = true;
                break;
            } else if (player.hasCountry(txtline)) {
                int numOfArmies = 0;
                while (true) {
                    cout << "How many armies do you wish to place?";
                    cin >> numOfArmies;
                    if (numOfArmies < 3) {
                        cout << "You need to place more than 3 armies per country";
                    } else {
                        player.getCountries().at(player.hasCountry(txtline)).addArmies(numOfArmies);
                        break;
                    }
                }

            } else {
                cout << "You do not have this country";
            }
        }
    }
    else{
        cout<< "You do not have enough armies to reinforce at the moment";
    }
}






