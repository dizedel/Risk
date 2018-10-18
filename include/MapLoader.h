#pragma once

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <string>
#include <vector>

#include "Map.h"
#include <fstream>

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
		Map map1;

};
#endif