#include <iostream>
#include "MapLoader.h"
#include "Dice.h"

using namespace std;

int main() {

    Dice dice;
	MapLoader loader;
	string mapFileName;

	cout << "Enter the map's file name: ";
	getline(cin, mapFileName);
	cout << "Attempting to load " << mapFileName;
	loader.loadMapFile(mapFileName);
	cout << endl;


    dice.Rolls();
    dice.Rolls();
    dice.DisplayPercentage();

	system("pause");


	return 0;
}