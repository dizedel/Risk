#include <Continent.h>
#include "stdafx.h"
#include "../include/Territory.h"

using namespace std;

Territory::Territory() {
	territoryName = "";
	coordX = NULL;
	coordY = NULL;
	territoryOwner = "";
	armies = 0;
}

Territory::Territory(string n, int x, int y, vector<string> v, string s) {
	territoryName = n;
	coordX = x;
	coordY = y;
	neighbors = v;
	territoryOwner = "";
	armies = 0;
}

Territory::~Territory() {}

string Territory::getName() {
	return territoryName;
}

int Territory::getX() {
	return coordX;
}

int Territory::getY() {
	return coordY;
}

string Territory::getContinent() {
	return continent;
}

void Territory::setName(string n){
	territoryName = n;
}

void Territory::setX(int x) {
	coordX = x;
}

void Territory::setY(int y) {
	coordY = y;
}


void Territory::setContinent(string c) {
	continent = c;
}

void Territory::addNeighbor(string t) {
	neighbors.push_back(t);
}

void Territory::setArmies(int a)
{
	armies = a;
}

vector<string> Territory::getNeighbors() {
	return neighbors;
}

int Territory::getArmies()
{
	return armies;
}

void Territory::addArmies(int a) {
	armies += a;
}


string Territory::getTerritoryOwner() {
	return territoryOwner;
}

void Territory::setTerritoryOwner(string s) {
	territoryOwner = s;
	Notify();
}


