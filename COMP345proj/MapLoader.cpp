#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

#include "include/MapLoader.h"
#include "include/Continent.h"
#include "include/Territory.h"
#include "include/Map.h"

using namespace std;

void MapLoader::parseFileInfo(ifstream& ifs) {
	string delim = "=";
	string txtline;
	int delimPosition;
	string fileInfo[5];

	cout << "Parsing the [Map] block." << endl;

	for (int i = 0; i < 5; i++) {
		getline(ifs, txtline);
		delimPosition = txtline.find(delim);
		fileInfo[i] = txtline.substr(delimPosition + 1);
		cout << fileInfo[i] << endl;
	}
	map1.setAuthor(fileInfo[0]);
	map1.setImage(fileInfo[1]);
	map1.setWrap(fileInfo[2]);
	map1.setScroll(fileInfo[3]);
	map1.setWarn(fileInfo[4]);
	fileInfoFound = true;
	cout << "Done." << endl;
}

void MapLoader::parseContinents(ifstream& ifs) {
	Continent c;
	string delim = "=";
	string txtline;
	int delimPosition;

	getline(ifs, txtline);
	cout << "Parsing the [Continents] block." << endl;

	while (!txtline.empty()) {
		delimPosition = txtline.find(delim);
		c.setName(txtline.substr(0, delimPosition));
		c.setTerritoryCount(stoi(txtline.substr(delimPosition + 1)));
		cout << "Name: " << c.getName() << ", Territories: " << c.getTerritoryCount() << endl;
		map1.addContinents(c);
		getline(ifs, txtline);
	}
	continentInfoFound = true;
	cout << "Done." << endl;
}

void MapLoader::parseTerritories(ifstream& ifs) {

	string delim = ",";
	string txtline;
	size_t cursor = 0;
	string name = "", continent = "", neighbor = "";
	Continent cont;

	int xco = 0, yco = 0;

	getline(ifs, txtline);

	while (getline(ifs, txtline)) {

		if (txtline != "") {
			int i = 0;
			Territory t;

			while ((cursor = txtline.find(delim)) != string::npos) {
				switch (i) {
				case 0:
					name = txtline.substr(0, txtline.find(delim));
					t.setName(name);
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 1:
					xco = stoi(txtline.substr(0, txtline.find(delim)));
					t.setX(xco);
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 2:
					yco = stoi(txtline.substr(0, txtline.find(delim)));
					t.setY(yco);
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 3:
					continent = txtline.substr(0, txtline.find(delim));
					t.setContinent(continent);
					txtline.erase(0, cursor + 1);
					i++;
					break;
				default:	// When index is > 3, we assume that the next strings are neighboring territories
					neighbor = txtline.substr(0, txtline.find(delim));
					t.addNeighbor(neighbor);
					txtline.erase(0, cursor + 1);
					break;
				}
			}
			cout << t.getName() << ", " << t.getX() << ", " << t.getY() << ", " << t.getContinent()  <<endl;
			cont.addTerritories(t);

		}
		else {
			getline(ifs, txtline); // skips empty line
		}
	}
	territoryInfoFound = true;
}

void MapLoader::loadMapFile(string mn) {

	inputFile.open(mn);

	if (inputFile) {

		cout << "\nFile found.";
		string txtline;
		string delim;

		while (inputFile.good()) {

			getline(inputFile, txtline);

			if (txtline == "[Map]") {
				parseFileInfo(inputFile);
			}
			else if (txtline == "[Continents]") {
				parseContinents(inputFile);
			}
			else if (txtline == "[Territories]") {
				parseTerritories(inputFile);
			}
		}
	}
	else {
		cout << "\nFile not found.";
	}
	cout << "\nMap loaded.";
}


