#include <iostream>
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <Player.h>
#include <game/Fortify.h>
#include "Dice.h"
#include "game/Reinforce.h"

using namespace std;

int Hand::exchangedHands = 0;

int main() {





    cout << "/*********************************"<< endl;
    cout << "*    REINFORCE DEMO "              << endl;
    cout << "*******************************/"  << endl;
    Player tom = Player("Tom");
    Deck d     = Deck(100);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.addArmies(5);

    cout << "Player: " << tom.getName() << endl;
    Reinforce r_tom = Reinforce(tom);
    cout << "cards:" <<tom.getHand().getCards().size()<< endl;
    for(int i = 0; i < tom.getHand().getCards().size(); i++){
        cout << "Card "<< (tom.getHand().getCards().at(0)).getType() << endl;
    }

    Territory canada("Canada",3,3,{"h","i"});

    tom.addCountry(canada);

    cout<< tom.posOfCountry("Canada")<< endl;
    r_tom.playPhase();

    //Fortify f_tom = Fortify(tom);
    //f_tom.playPhase();

    system("pause");




	return 0;
}