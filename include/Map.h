#ifndef MAP_H
#define MAP_H

#include "Continent.h"

#include <string>
#include <vector>
#include "stdafx.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Map {

	public:
		Map();
		Map(string, string, string, string, string);
		~Map();

		string getAuthor();
		string getImage();
		string getWrap();
		string getScroll();
		string getWarn();
		vector<Continent> getContinents();
		int getTerritoryCount();
		vector<Territory> getTerritory(); // return territories found in the map
		int getNbTerritories();  //return number of territories stored in the container; returns size of Territories container

		void setAuthor(string);
		void setImage(string);
		void setWrap(string);
		void setScroll(string);
		void setWarn(string);
		void addContinents(Continent);
		void setTerritoryCount(int);
		void addTerritories(Territory); //add territory to the container
		void createMap(Map m); // create the graph structure to represent the map, using Adjacency List
		void checkIfValid(Map m);// checks to see every country is only in 1 continent
		void printContainedTerritories(); //prints

	private:
		string author;
		string image;
		string wrap;
		string scroll;
		string warn;
		int territoryCount;
		vector<Continent> c; // all continents
		vector<Territory> t; //all territories

};
#endif