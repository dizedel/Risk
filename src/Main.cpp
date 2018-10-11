#include <iostream>
#include "MapLoader.h"

using namespace std;

int main() {
	
	MapLoader loader;
	string mapFileName;

	cout << "Enter the map's file name: ";
	getline(cin, mapFileName);
	cout << "Attempting to load " << mapFileName;
	loader.loadMapFile(mapFileName);
	cout << endl;
	system("pause");

	return 0;
}