#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "Map.h"
#include "Continent.h"
#include "Territory.h"

using namespace std;

class MapLoader {
	public:
		void parseFileInfo(ifstream&);
		void parseContinents(ifstream&);
		void parseTerritories(ifstream&);
		void loadMapFile(string);
		Map getMap(); //a function that would return the map, added by person doing map part
		
	private:
		ifstream inputFile;
		bool fileInfoFound = false;
		bool continentInfoFound = false;
		bool territoryInfoFound = false;
		Map map1; // a Map object that will store all the info parsed from the map txt file.
};