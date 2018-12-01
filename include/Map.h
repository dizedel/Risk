#ifndef MAP_H
#define MAP_H
#include "stdafx.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "../include/Continent.h"
#include "../include/Territory.h"

using namespace std;

class Map {

	public:
		//vector<Continent> c;
		Map();
		Map(string, string, string, string, string); //details of map , i.e author, image , etc......
		~Map();

		string getAuthor();
		string getImage();
		string getWrap();
		string getScroll();
		string getWarn();
		vector<Continent>& getContinents(); //return continents in the map
		vector<Territory>& getTerritory(); // return territories found in the map
		Territory matchTerritory(string); // returns territory that matches string name, if it doesn't exist returns empty territory
		bool hasTerritory(string);
		int getNbTerritories();  //return number of territories stored in the container; returns size of Territories container

		void setAuthor(string);
		void setImage(string);
		void setWrap(string);
		void setScroll(string);
		void setWarn(string);
		void addContinents(Continent); //add continent to the container
		void addTerritories(Territory); //add territory to the container

		void createMap(Map m); // create the graph structure to represent the map, using Adjacency List
		void checkIfValid(Map m);// checks to see every country is only in 1 continent
		void printContainedTerritories(); //prints
		vector<Territory*> getPlayerCountries(string);
		void setTerritoryCount(int);

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