//
// Created by pamel on 2018-11-18.
//

#include "strategy/HumanPlayer.h"
#include <iostream>
#include <game/Reinforce.h>

using namespace std;

void HumanPlayer::executeReinforce(Player* p) {
    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's " << p->getName() <<"'s turn to reinforce!"<<endl;
    cout<< endl<< "---------------------------------------------"<< endl;

    Player& player = *p;
    string str;
    Reinforce r;
    string txtline;
    bool answered = false;

    p->giveArmiesForTerritory();

   //EXCHANGE CARDS
    while (true) {
        cout << "Do you wish to exchange your cards?" << endl;
        cin >> txtline;

        if (txtline == "yes" || txtline == "no") {
            if (txtline == "yes"){
                int exchangedCards = p->getHand().exchange();
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

    //REINFORCE
    if(p->getArmies()>= 1) {
        while (p->getArmies()>=1) {
            cout <<"You have --- " << p->getArmies() <<" --- armies. Which countries do you wish to reinforce? Enter 'done' if you do not wish to." << endl;
            getline(cin, str);
            if (str == "done") {
                break;
            }
            else if (p->hasCountry(str)) {
                string countryToReinforce = str;
                int numOfArmies = 0;
                bool finished = false;
                while (!finished) {
                    int n;
                    cout << "How many armies do you wish to place?" << endl;
                    cin>>n;
                    if (floor(n) == n && n > 0) {
                        r.setNumOfArmiesToPutDown(numOfArmies);
                        finished = true;
                    }
                    else{
                        cout << "Please enter a valid output" << endl;
                        delete(&n);
                    }
                }
            }
            else {
                cout << "You do not have this country" << endl;
            }
        }
    }
    else{
        cout<< "You do not have enough armies to reinforce at the moment" << endl;
    }
    r.reinforce();

}
void HumanPlayer::executeAttack(Player* p) {

}
void HumanPlayer::executeFortify(Player* p) {

}