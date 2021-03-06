#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

#include "../include/MapLoader.h"

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
	Continent tempC;
	string delim = "=";
	string txtline;
	int delimPosition;

	getline(ifs, txtline);
	cout << "Parsing the [Continents] block." << endl;

	while (!txtline.empty()) {
		delimPosition = txtline.find(delim);
		tempC.setName(txtline.substr(0, delimPosition));
		tempC.setTerritoryCount(stoi(txtline.substr(delimPosition + 1)));
		map1.addContinents(tempC); //stores continents in the continent container of the map object
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
	vector<Territory> tvect;

	int xco = 0, yco = 0;
	cout << "Parsing the [Territories] block." << endl;

	while (getline(ifs, txtline)) {

		if (txtline != "") {
			int i = 0;
			Territory t;

			cout << tvect.size() << ": ";

			while ((cursor = txtline.find(delim)) != string::npos) {
				switch (i) {
				case 0:
					name = txtline.substr(0, cursor);
					t.setName(name);
					cout << t.getName() << ", (";
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 1:
					xco = stoi(txtline.substr(0, cursor));
					t.setX(xco);
					cout << t.getX() << ", ";
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 2:
					yco = stoi(txtline.substr(0, cursor));
					t.setY(yco);
					cout << t.getY() << "), Continent: ";
					txtline.erase(0, cursor + 1);
					i++;
					break;
				case 3:
					continent = txtline.substr(0, cursor);
					t.setContinent(continent); // store the name of the continent that the territory is located in; store in the territory object
					for (int i = 0; i < map1.getContinents().size(); i++) 
					{
						if (map1.getContinents().at(i).getName() == t.getContinent()) 
						{

							map1.getContinents().at(i).addTerritories(t);
						}
					}
					cout << t.getContinent() << ". Neighbors: ";
					txtline.erase(0, cursor + 1);
					i++;
					break;
				default:	// When index is > 3, we assume that the next strings are neighboring territories
					stringstream ss(txtline);
					while (getline(ss, neighbor, ',')) {
						t.addNeighbor(neighbor); //add name of adjacent territory in the containter of neighbors; store in the territory object
						cout << neighbor;
						if (ss.eof()) {
							cout << ". ";
						}
						else {
							cout << ", ";
						}
					}
					txtline.erase();
					break;
				}
			}
			tvect.push_back(t);
			map1.addTerritories(t); // added by person doing map part, add territory into container of territories in map object.
			cout << endl;

		}
	}
	map1.setTerritoryCount(tvect.size());
	cout << "\nContinents on map: " << map1.getContinents().size();
	cout << "\nTerritories on map: " << map1.getNbTerritories();
	territoryInfoFound = true;	
}

void MapLoader::loadMapFile(string mn) {

	inputFile.open("../maps/"+mn);

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

Map MapLoader::getMap() //added by person doing map part
{
	return MapLoader::map1;
}

