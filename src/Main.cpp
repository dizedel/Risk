#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "../include/Map.h"
#include "../include/MapLoader.h"
#include "../include/Card.h"
#include "../include/Dice.h"
#include "../include/Deck.h"
#include "../include/Hand.h"
#include "../include/Player.h"

using namespace std;

int Hand::exchangedHands = 0;

void startupPhase(vector<Player> *vp, Map &map1) {
    cout << "STARTING UP" << endl;

    int playerCount = vp->size();

    static auto rng = std::default_random_engine {};

    cout << "There are " << playerCount << " players in the match." << endl;

    // randomizes all players
    std::shuffle(vp->begin(), vp->end(), rng);

    // randomly distribute territories
    vector<Territory> tempTVect = map1.getTerritory(); // will eventually be empty when all countries are assigned
    vector<Territory> occupiedTerritories; // placeholder vector
    int terrCount = tempTVect.size();
    cout << "There are " << terrCount <<" territories to be distributed." << endl;

    int playerIndex = 0;
    string ownerName = "";
    string territoryName = "";

    cout << "====== Randomly assigning territories to players ======" << endl;
    for (Territory te : tempTVect) {
        std::shuffle(tempTVect.begin(), tempTVect.end(), rng);

        ownerName = vp->at(playerIndex).getName();
        territoryName = tempTVect.back().getName();

        vp->at(playerIndex).addTerritory(tempTVect.back());
        tempTVect.back().setTerritoryOwner(ownerName);
        occupiedTerritories.push_back(tempTVect.back());

        cout << ownerName << " was assigned " << territoryName << " (" << tempTVect.back().getX() << "," << tempTVect.back().getY() << "), now they have " << vp->at(playerIndex).getCountries().size() << " countries." << endl;

        playerIndex = (playerIndex + 1) % playerCount;

        tempTVect.pop_back();
    }

    cout << endl;

    // assign ownership to territories on the original map
    for(int i=0;i<map1.getTerritory().size();i++){
        for(int j=0;j<occupiedTerritories.size();j++){
            if(occupiedTerritories.at(j).getName()==map1.getTerritory().at(i).getName()){
                string occupier = occupiedTerritories.at(j).getTerritoryOwner();
                map1.getTerritory().at(i).setTerritoryOwner(occupier);
            }
        }
    }

    cout << endl;

    // assign starting armies to players
    int startingArmy = 50 - (5 * playerCount);
    for(int i=0; i<playerCount; i++){
        vp->at(i).setStartingArmy(startingArmy);
        cout << vp->at(i).getName() << " was given " << vp->at(i).getArmies() << " armies." << endl;
    }

    cout << endl;

    /*
    // assign armies to territories
    // maybe this should be done using reinforce(), will fix when pam is done with her part
    bool allArmiesAssigned=false;
    while(!allArmiesAssigned){
        for(int j=0; j<playerCount; j++){
            cout << vp->at(j).getName() << "\'s turn." << endl;
            bool successfulTurn=false;
            while(!successfulTurn){
                cout << "Enter the territory name where you want to add armies: " << endl;
                string tempstr;
                getline(cin, tempstr);
                if(vp->at(j).hasCountry(tempstr)>0){
                    int armySize;
                    cout << "How many armies do you want to assign to this territory?";
                    cin >> armySize;
                    if(vp->at(j).getArmies()<armySize){
                        cout << "You don't have that many remaining armies to assign." << endl;
                    }
                    else{
                        for(int k=0; k<occupiedTerritories.size(); k++){
                            if(occupiedTerritories.at(k).getName()==tempstr){
                                occupiedTerritories.at(k).addArmies(armySize);
                                cout << "Army assigned, next player's turn!" << endl;
                                successfulTurn=true;
                            }
                        }
                    }
                }
                else{
                    cout << "This territory does not belong to you." << endl;
                }
            }
        }
    }
     */
}


int main() {
	
	Map gen;
	MapLoader loader;
	Hand hand;
	Dice dice;

	int numOfCards;
	int infantry = 0;
	int artillery = 0;
	int cavalry = 0;

	// loading map
	string mapFileName;
	cout << "Enter the map's file name: ";
	getline(cin, mapFileName);
	cout << "Attempting to load " << mapFileName;
	loader.loadMapFile(mapFileName);
	cout << '\n';

	Map map1 = loader.getMap();
	gen.createMap(map1);
	cout << " \n \n \n";
	gen.checkIfValid(map1);
	cout << endl;
	map1.printContainedTerritories();
	cout << endl;	

	// assignment 2 demo

	//Part 2
    Player p1, p2, p3;
    p1.setName("PLAYER ONE");
    p2.setName("PLAYER TWO");
    p3.setName("PLAYER THREE");

    vector<Player> players;
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
	startupPhase(&players, map1);
    cout << "====== Territory Ownerships ======" << endl;
    for (Player& p : players){
        cout << p.getName() << " owns " << p.getCountries().size() << " territories:" << endl;
        cout << p.displayCountries() << endl;
    }
    for(int i=0; i<map1.getTerritory().size();i++){
        cout << map1.getTerritory().at(i).getName() << " is owned by " << map1.getTerritory().at(i).getTerritoryOwner() << endl;
    }
    /*
     * to do: assign armies to countries
     *
     *
     *
     */
	
	system("pause");
	

	return 0;
}

