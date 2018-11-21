#include <Continent.h>
#include "stdafx.h"
#include "../include/Territory.h"
#include <iostream>

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

Territory& Territory::operator=(const Territory& te){
	territoryName = te.territoryName;
	coordX = te.coordX;
	coordY = te.coordY;
	neighbors = te.neighbors;
	territoryOwner = te.territoryOwner;
	armies = te.armies;
	return *this;

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
}

void Territory::setNeighbors(vector<string> vs){
	neighbors.erase(neighbors.begin(),neighbors.end());
	for(string s: vs){
		neighbors.push_back(s);
	}
}

void Territory::copyTerritory(Territory& source, Territory& target) {
	target.setName(source.getName());
	target.setTerritoryOwner(source.getTerritoryOwner());
	target.setX(source.getX());
	target.setY(source.getY());
	target.setNeighbors(source.getNeighbors());
	target.setArmies(source.getArmies());
	/*
	 * debugging
	cout << territoryName << coordX << coordY << territoryOwner <<armies ;
	for(string s : neighbors){
		cout << s;
	}
	cout << endl;
	 */
}