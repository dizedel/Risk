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
    return coordY;
}

int Territory::getArmies() {
    return armies;
}

string Territory::getContinent() {
    return continent;
}

void Territory::setName(string n){
    name = n;
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

vector<string> Territory::getNeighbors() {
    return neighbors;
}

void Territory::addArmies(int a){
    armies += a;
}
