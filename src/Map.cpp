#include "stdafx.h"
#include "../include/Map.h"

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

vector<Continent>& Map::getContinents() {
	return c;
}

vector<Territory>& Map::getTerritory()
{
	return t;
}

int Map::getNbTerritories()
{
	return t.size();
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

void Map::addTerritories(Territory t1)
{
	t.push_back(t1);
}

void Map::createMap(Map m)  //method creates the map representation using an adjacency list. basically a vector storing a list; first index of vector would store territory and a list of adjacent territories
{
	vector<list<string>> adjList(m.getNbTerritories()); //intialize adjacency list to size of Territory container in the map object

	for (int i = 0; i < m.getNbTerritories(); i++)
	{
		adjList[i].push_back(m.getTerritory().at(i).getName());  // store the territories in the vector
		for (int j = 0; j < m.getTerritory().at(i).getNeighbors().size(); j++)
		{
			adjList[i].push_back(m.getTerritory().at(i).getNeighbors().at(j)); // store the neighbors
		}
	}

	/* demo for asg1
	vector<list<string> >::iterator i;  
	
	int c = 0;
	for (vector<list<string> >::iterator i = adjList.begin() ; i != adjList.end(); i++)  //traversing thru the entire adjacency list using iterators.
	{
		list<string> li = *i;
		for (std::list<string>::iterator iter = li.begin(); iter != li.end(); iter++) 
		{
			cout << *iter << " ";
		}
		cout << endl;
		c++;
	}
	*/
	
}

void Map::printContainedTerritories() {
	cout << endl << "contained territories" << endl;
	for (int i = 0; i < c.size(); i++)
	{
		Continent continent = c.at(i);
		vector<Territory> containedTerritories = continent.getContainingTerritories();

		cout << continent.getName() << ": ";

		for (int j = 0; j < containedTerritories.size(); j++)
		{
			cout << containedTerritories.at(j).getName() << " ";
		}
		cout << endl;
	}
}

void Map::checkIfValid(Map m) 
{
	Territory temp;
	Territory temp2;
	bool valid = true;
	for (int i = 0; i < m.getContinents().size() - 1; i++) // to loop thru the 6 continents
	{
		for (int ii = 0; ii < m.getContinents().at(i).getContainingTerritories().size(); ii++) //to loop thru countries in container
		{
			temp = m.getContinents().at(i).getContainingTerritories().at(ii); //first country in first array

			for (int j = i + 1; j < m.getContinents().size(); j++) //comparer loop thru the continents
			{
				for (int jj = 0; jj < m.getContinents().at(j).getContainingTerritories().size(); jj++)  //loop thru the countries 
				{

					temp2 = m.getContinents().at(j).getContainingTerritories().at(jj);
					if (temp.getName() == temp2.getName())
					{
						cout << "map invalid country found in 2 continents" << temp.getName() << " " << temp2.getName() << endl;
						valid = false;
					}
				}
			}
		}
	}

	if (valid == true)
		cout << "map is valid";
}

void Map::setTerritoryCount(int tc) {
	territoryCount = tc;
}

