#include "stdafx.h"
#include <list>
#include <vector>
#include "../include/Continent.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*int main()
{
	int nbOfTerritories = 0; //will be input to size of adj list
	vector<Territory> territories; //all territories
	vector<Continent> continents; // all continents
	
	

	Territory Alaska = Territory();
	nbOfTerritories++;
	Alaska.setName("alaska");
	Alaska.setContinent("NorthAmerica");
	Alaska.setXY(70, 126);
	Alaska.addNeighbor("Northwest Territory");
	Alaska.addNeighbor("Alberta");
	Alaska.addNeighbor("Kamtchatka");

	territories.push_back(Alaska);

	Territory NorthwestTerritory = Territory();
	nbOfTerritories++;
	NorthwestTerritory.setName("Northwest Territory");
	NorthwestTerritory.setContinent("NorthAmerica");
	NorthwestTerritory.setXY(148, 127);
	NorthwestTerritory.addNeighbor("Alaska");
	NorthwestTerritory.addNeighbor("Alberta");
	NorthwestTerritory.addNeighbor("Ontario");
	NorthwestTerritory.addNeighbor("GreenLand");

	territories.push_back(NorthwestTerritory);

	Territory CentralAmerica = Territory();
	nbOfTerritories++;
	CentralAmerica.setName("Central America");
	CentralAmerica.setContinent("NorthAmerica");
	CentralAmerica.setXY(183, 262);
	CentralAmerica.addNeighbor("Western United States");
	CentralAmerica.addNeighbor("Eastern United States");
	CentralAmerica.addNeighbor("Venezuala");

	territories.push_back(CentralAmerica);

	vector<list<string>> adjList(nbOfTerritories); //create adjList with size equal to nb of countries
	
	for (int i = 0; i < nbOfTerritories; i++)
	{
		adjList[i].push_back(territories.at(i).getName());
		for (int j = 0; j < territories.at(i).getNeighbors().size(); j++)
		{
			adjList[i].push_back(territories.at(i).getNeighbors().at(j));
		}
	}

	std::vector<std::list<string> >::iterator i;
	int c = 0;
	for (std::vector<std::list<string> >::iterator i = adjList.begin(); i != adjList.end(); i++) {


		cout << "Country and its neighbors" << " are ";
		//cout<<*i;

		std::list<string> li = *i;
		for (std::list<string>::iterator iter = li.begin(); iter != li.end(); iter++) {

			cout << *iter << " ";
		}
		cout << endl;
		c++;
	}

}*/
