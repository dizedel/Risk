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
		void runLoader();

	private:
		ifstream inputFile;
		bool fileInfoFound = false;
		bool continentInfoFound = false;
		bool territoryInfoFound = false;
		Map map1;

};
#endif