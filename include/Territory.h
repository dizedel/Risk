#pragma once

#include "stdafx.h"
#include "Continent.h"
#include <string>
#include <vector>
#include "Pattern/Subject.h"

//#include "Continent.h"

using namespace std;

class Territory : public Subject{

public:
	Territory();
	Territory(string, int, int, vector<string>, string); // contstructor, Name , X & Y coord, Neighbors, owner
	~Territory();

	string getName();	//return Name of territory
	int getX();	
	int getY();
	string getContinent();	//return name of continent territory is in
	vector<string> getNeighbors(); //return the container of neighbors for the territory
	int getArmies(); //return number armies the territory has	

	void setName(string);
	void setX(int);
	void setY(int);
	void setContinent(string);
	void addNeighbor(string);

	void setArmies(int a);
	void addArmies(int);

	string getTerritoryOwner();
	void setTerritoryOwner(string);

private:
	string territoryName;
	int coordX;
	int coordY;
	string continent;
	vector<string> neighbors;
	int armies=0;
	string territoryOwner;

	//Player owner;
};