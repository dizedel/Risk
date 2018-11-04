#include <iostream>
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <Player.h>
#include "Dice.h"
#include "/game/Reinforce.h"

using namespace std;

int Hand::exchangedHands = 0;

int main() {



    Player tom = Player("Tom");
    Deck d     = Deck(100);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);
    tom.getHand().addCardToHand(d);

    /*********************************
     *    REINFORCE DEMO
     * ******************************/
    Reinforce r = Reinforce(tom);
    r.playPhase();

    system("pause");




	return 0;
}