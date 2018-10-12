#include <iostream>
#include "MapLoader.h"
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


	cout << "*************** \n DICE DEMO \n***************\n";
    dice.rolls();
    dice.rolls();
    dice.displayPercentage();
    
	system("pause");


	return 0;
}