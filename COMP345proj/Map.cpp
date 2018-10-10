#include "stdafx.h"
#include "map.h"

using namespace std;

Map::Map()
{
	author = "";
	image = "";
	wrap = "";
	scroll = "";
	warn = "";
}

Map::Map(string a, string img, string wrp, string scr, string wrn) {
	author = a;
	image = img;
	wrap = wrp;
	scroll = scr;
	warn = wrn;
}

Map::~Map() {}

vector<Continent> Map::getContinents() {
	return c;
}

string Map::getAuthor() {
	return author;
}

string Map::getImage() {
	return image;
}

string Map::getWrap() {
	return wrap;
}

string Map::getScroll() {
	return scroll;
}

string Map::getWarn() {
	return warn;
}

void Map::setAuthor(string a) {
	author = a;
}

void Map::setImage(string img) {
	image = img;
}

void Map::setWrap(string wrp) {
	wrap = wrp;
}

void Map::setScroll(string scr) {
	scroll = scr;
}

void Map::setWarn(string wrn) {
	warn = wrn;
}

void Map::addContinents(Continent c1) {
	c.push_back(c1);
}