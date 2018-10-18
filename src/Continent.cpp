#include "Continent.h"
#include "Territory.h"
using namespace std;

Continent::Continent() {
    name = "";
    territoryCount = NULL;
}

Continent::Continent(string n, int tc) {
    name = n;
    territoryCount = tc;
}

Continent::~Continent() {}

string Continent::getName() {
    return name;
}

int Continent::getTerritoryCount() {
    return territoryCount;
}

vector<Territory> Continent::getContainingTerritories() {
    return containingTerritories;
}

void Continent::setName(string n) {
    name = n;
}

void Continent::setTerritoryCount(int tc) {
    territoryCount = tc;
}

void Continent::addTerritories(Territory t1) {
    containingTerritories.push_back(t1);
}
