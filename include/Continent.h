#pragma once

#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>

#include "Territory.h"

using namespace std;

class Continent {

public:
	Continent();
	Continent(string, int);
	~Continent();

	string getName();
	int getTerritoryCount();
	vector<Territory> getContainingTerritories(); //return territories in continent

	void setName(string);
	void setTerritoryCount(int);
	void addTerritories(Territory);

private:
	string name;
	int territoryCount;
	vector<Territory> containingTerritories;

};
#endif