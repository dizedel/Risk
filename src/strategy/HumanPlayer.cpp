//
// Created by pamel on 2018-11-18.
//

#include "strategy/HumanPlayer.h"
#include <iostream>
#include "game/Reinforce.h"
#include "game/Attack.h"
#include "game/Fortify.h"

using namespace std;

void HumanPlayer::executeReinforce(Player* p){
    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's HUMAN " << p->getName() <<"'s turn to reinforce!"<<endl;
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
    Fortify* f = new Fortify();
    cout<< endl<< "---------------------------------------------"<< endl;
    cout<< "It's HUMAN" << p->getName() <<"'s turn to reinforce!"<<endl;
    cout<< endl<< "---------------------------------------------"<< endl;

    while(true){
        string fortifiedCountry;
        string providerCountry;

        cout<< "Which country do you wish to fortify? If you are done, say 'done'";
        cin >> fortifiedCountry;

        if(fortifiedCountry == "done")
            break;
        else if (!p->hasCountry(fortifiedCountry)) {
            cout << "You do not have that country";
        }
        else{
            f->setCountryToFortify(fortifiedCountry);
            while(true) {
                cout << "Which country do you want to take armies from?" << endl;
                cin >> providerCountry;
                if (!p->hasCountry(providerCountry)) {
                    cout << "You do not have that country";
                }
                else if ( p->getCountries().at(p->posOfCountry(providerCountry)).getArmies() <= 1) {
                    cout << "You do not have enough armies to take from this country";
                }
                else {
                    f->setCountryToTakeFrom(providerCountry);
                    cout<<"How many armies should we fortify with?";
                    int num;
                    cin >> num;
                    int providerCountryArmies = p->getCountries().at(p->posOfCountry(providerCountry)).getArmies();
                    while(num >= providerCountryArmies){
                        cout << "Provider country only has " << providerCountryArmies << " armies.";
                        cout << "Choose a number of Armies lower than " << providerCountryArmies;
                        cin >> num;
                    }
                    f->setNumOfTransferArmies(num);
                    f->fortify();
                    break;
                }
            }
        }
    }
}

string HumanPlayer::toString(){
    return "Human Player";
}