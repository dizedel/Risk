#pragma once

#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>

#include "territory.h"

using namespace std;

class Continent {

public:
	vector<Territory> t;
	Continent();
	Continent(string, int);
	~Continent();

	string getName();
	int getTerritoryCount();
	vector<Territory> getTerritories();

	void setName(string);
	void setTerritoryCount(int);
	void addTerritories(Territory);

private:
	string name;
	int territoryCount;

};
#endif