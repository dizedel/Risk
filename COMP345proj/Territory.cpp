#include "stdafx.h"
#include "Territory.h"

using namespace std;

Territory::Territory() {
	name = "";
	coordX = NULL;
	coordY = NULL;
}

Territory::Territory(string n, int x, int y, vector<string> v) {
	name = n;
	coordX = x;
	coordY = y;
	neighbors = v;
}

Territory::~Territory() {}

string Territory::getName() {
	return name;
}

int Territory::getX() {
	return coordX;
}

int Territory::getY() {
	return coordX;
}

string Territory::getContinent() {
	return continent;
}

void Territory::setName(string nameX){
	name = nameX;
}

void Territory::setX(int val) {
	coordX = val;
}

void Territory::setY(int val) {
	coordY = val;
}

void Territory::setContinent(string cont) {
	continent = cont;
}

void Territory::addNeighbor(string terr) {
	neighbors.push_back(terr);
}

vector<string> Territory::getNeighbors() {
	return neighbors;
}

