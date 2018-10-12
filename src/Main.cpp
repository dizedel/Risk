#include <iostream>
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <Player.h>
#include "Dice.h"

using namespace std;

int main() {

    Dice dice;
	MapLoader loader;
	string mapFileName;

	cout << "*************** \n MAP LOADER DEMO \n***************\n";
	cout << "Enter the map's file name: ";
	getline(cin, mapFileName);
	cout << "Attempting to load " << mapFileName;
	loader.loadMapFile(mapFileName);
	cout << endl;


    cout << "*************** \n CARDS, DECK, HAND DEMO \n***************\n";

	int numOfCards = 100; // to be replaced with number of continents

	Deck deck(numOfCards);

	int infantry = 0;
	int artillery = 0;
	int cavalry = 0;

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

	cout << "*************** \n DICE DEMO \n***************\n";
    dice.rolls();
    dice.rolls();
    dice.displayPercentage();

    cout << "****************\n PLAYER DEMO \n*************\n";
    //TODO:Player DEMO
	system("pause");


	return 0;
}