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
#include "MapLoader.h"
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <Player.h>
#include <game/Fortify.h>
#include "Dice.h"
#include "game/Reinforce.h"

using namespace std;

int Hand::exchangedHands = 0;

void GameStart(vector<Player> *vp, MapLoader &loader1, Map &map1, Deck &deck1, Hand &hand1)
{
    char startGame;
    cout << "Would you like to start a game ? (Y or N)" << endl;
    cin >> startGame;

    if (startGame == 'Y')
    {
        //open directory and display and let player select
        ifstream inputFileStream("../maps/listOfMaps.txt");

        if (inputFileStream.fail())
        {
            cout << "error opening directory" << endl;
        }

        //store lines of string into a vector and display it
        vector<string> directoryContent;
        string temp; // to load all the maps in the directory into the vector

        getline(inputFileStream, temp, '\t');
        directoryContent.push_back(temp);
        cout << "0. " <<directoryContent.at(0);

        if (inputFileStream.eof())
            cout << " \nEnd of directory \n " << endl;

        //player selects map
        int playerChoice;
        string mapName;
        cout << " \nPlease select a map to load (0,1,2,......)" << endl;
        cin >> playerChoice;
        cout << "\nMap selected: " << directoryContent.at(playerChoice) << endl;
        mapName = directoryContent.at(playerChoice);
        cout << '\n' << mapName << endl;

        //player selects number of players
        int numberOfPlayers;
        cout << "\n Select number of players between 2 and 6" << endl;
        cin >> numberOfPlayers;
        if (numberOfPlayers < 2 || numberOfPlayers > 6)
        {
            cout << "invalid number of players please select a valid range \n";
            while ((numberOfPlayers < 2 || numberOfPlayers > 6) == true)
            {
                cin >> numberOfPlayers;
                cout << "invalid number of players please select a valid range \n";
            }
        }
        cout << "number of players: " << numberOfPlayers << endl;

        //load map
        loader1.loadMapFile(mapName);

        //create map
        map1 = loader1.getMap();
        map1.createMap(map1);
        cout << " \n \n \n";
        map1.checkIfValid(map1);
        map1.printContainedTerritories(); //same problem as A1 doesnt print contained territories in each content

        //create players, each player is instantiated with a dice object

        int playerCount = 0;

        Player player1("player1");
        vp->push_back(player1);
        playerCount++;

        Player player2("player2");
        vp->push_back(player2);
        playerCount++;
        if (playerCount < numberOfPlayers)
        {
            Player player3("player3");
            vp->push_back(player3);
            playerCount++;
        }
        if (playerCount < numberOfPlayers)
        {
            Player player4("player4");
            vp->push_back(player4);
            playerCount++;
        }
        if (playerCount < numberOfPlayers)
        {
            Player player5("player5");
            vp->push_back(player5);
            playerCount++;
        }
        if (playerCount < numberOfPlayers)
        {
            Player player6("player6");
            vp->push_back(player6);
            playerCount++;
        }

        //print player names
        cout << "Player names : " << endl;
        for (int i = 0; i < vp->size(); i++)
        {
            cout << vp->at(i).getName() << endl;
        }

        //create deck of cards
        Deck tempdeck(map1.getTerritory().size());
        deck1=tempdeck;

        cout << "Number of cards: " << deck1.getCards().size() << endl;

        //assign empty hand to each player
        for (int i = 0; i < vp->size(); i++)
        {
            vp->at(i).setHand(hand1);
        }
    }

}

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

        vp->at(playerIndex).addCountry(tempTVect.back());
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
        vp->at(i).setArmies(startingArmy);
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
    Map map1;
	MapLoader loader;
	Hand hand;
	Deck deck;
    vector<Player> players;

	// assignment 2 demo

	//Part 1
    GameStart(&players, loader, map1, deck, hand);

	//Part 2
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

