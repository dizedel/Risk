#include <iostream>
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include "Dice.h"

using namespace std;

int main() {

    int numOfCards;
    int infantry = 0;
    int artillery = 0;
    int cavalry = 0;
    Hand hand;

    Dice dice;
	MapLoader loader;
	string mapFileName;

	cout << "*************** \n MAP LOADER DEMO \n***************\n";
	cout << "Enter the map's file name: ";
	getline(cin, mapFileName);
	cout << "Attempting to load " << mapFileName;
	loader.loadMapFile(mapFileName);
	cout << endl;


    cout << "************************* \n CARDS, DECK, HAND DEMO \n*************************\n";

	numOfCards = 100; // to be replaced with number of continents

	Deck deck(numOfCards);


	for (int i = 0; i < deck.getCards().size(); i++)
    {
	    if (deck.getCards()[i].getType() == "infantry")
	        infantry++;
	    if (deck.getCards()[i].getType() == "artillery")
	        artillery++;
	    if (deck.getCards()[i].getType() == "cavalry")
	        cavalry++;
    }

    cout << "DECK CONTENTS"<< endl;
	cout << "Infantry: " << infantry << endl;
	cout << "Artillery: " << artillery << endl;
	cout << "Cavalry: " << cavalry << endl;
	cout << "This deck contains " << deck.getCards().size() << " cards." << endl;
	cout << "---------------" << endl;

    infantry = 0;
    artillery = 0;
    cavalry = 0;


    hand.addCardToHand(deck);
    hand.addCardToHand(deck);
    hand.addCardToHand(deck);
    hand.addCardToHand(deck);
    hand.addCardToHand(deck);

    for (int i = 0; i < deck.getCards().size(); i++)
    {
        if (deck.getCards()[i].getType() == "infantry")
            infantry++;
        if (deck.getCards()[i].getType() == "artillery")
            artillery++;
        if (deck.getCards()[i].getType() == "cavalry")
            cavalry++;
    }

    cout << "5 cards were drawn at random." << endl;
    cout << "NEW DECK CONTENTS"<< endl;
    cout << "Infantry: " << infantry << endl;
    cout << "Artillery: " << artillery << endl;
    cout << "Cavalry: " << cavalry << endl;
    cout << "This deck contains " << deck.getCards().size() << " cards." << endl;
    cout << "---------------" << endl;


    cout << "HAND CONTENTS" << endl;


    for (int i = 0; i < hand.getCards().size(); i++)
    {
        cout << "Card at index " << i << ": " << "Type: " << hand.getCards()[i].getType() << endl;
    }

	cout << "*************** \n DICE DEMO \n***************\n";
    dice.rolls();
    dice.rolls();
    dice.displayPercentage();

	system("pause");


	return 0;
}