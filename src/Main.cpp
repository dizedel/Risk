#include <iostream>
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
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

	vector<Card> cards;

	for (int i = 1; i <= numOfCards; i++)
	{
		if (i % 3 == 0)
			cards.push_back(Card("infantry"));
		else if (i % 2 == 0)
			cards.push_back(Card("artillery"));
		else if (i % 1 == 0)
			cards.push_back(Card("cavalry"));
	}

	Deck deck{cards};

	cout << "*************** \n DICE DEMO \n***************\n";
    dice.rolls();
    dice.rolls();
    dice.displayPercentage();

	system("pause");


	return 0;
}