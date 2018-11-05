#pragma once

#include "stdafx.h"
#include <string>
#include <vector>

#include "Territory.h"

using namespace std;

class Continent {

public:
	//vector<Territory> containingTerritories; 
	Continent();
	Continent(string, int); //name and territory count
	~Continent();

	string getName();
	int getTerritoryCount();
	vector<Territory> getContainingTerritories(); //return territories in continent
	

	void setName(string);
	void setTerritoryCount(int);
	void addTerritories(Territory); //add territories in the container

private:
	string name;
	int territoryCount;
	vector<Territory> containingTerritories;

};