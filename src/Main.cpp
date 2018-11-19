/*#include "stdafx.h"
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
#include "Player.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include "Dice.h"
#include "game/Reinforce.h"
#include "MainGame.h"
#include "Pattern/PlayerView.h"


using namespace std;

int Hand::exchangedHands = 0;

void GameStart(vector<Player> *vp, MapLoader &loader1, Map &map1, Deck &deck1, Hand &hand1) {
    char startGame;
    cout << "Would you like to start a game ? (Y or N)" << endl;
    cin >> startGame;

    if (startGame == 'Y' || startGame == 'y') {
        //open directory and  display and let player select
        ifstream inputFileStream("../maps/listOfMaps.txt");

        if (inputFileStream.fail()) {
            cout << "error opening directory" << endl;
        }

        //store lines of string into a vector and display it
        vector<string> directoryContent;
        string temp; // to load all the maps in the directory into the vector

        while (getline(inputFileStream, temp)) {
            directoryContent.push_back(temp);
        }

        for (int i = 0; i < directoryContent.size(); i++) {
            cout << i << ". " << directoryContent.at(i) << endl;
        }

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
        if (numberOfPlayers < 2 || numberOfPlayers > 6) {
            cout << "invalid number of players please select a valid range \n";
            while ((numberOfPlayers < 2 || numberOfPlayers > 6) == true) {
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

        //create the players and create their respective observers(playerView) and attach them to the observerList
        Player  player1("player1");
        vp->push_back(player1);
        playerCount++;

        //create playerview
        Player *pPlayer1 = &player1;
        PlayerView *pvPlayer1 = new PlayerView(pPlayer1);


        Player player2("player2");
        vp->push_back(player2);
        playerCount++;

        //create playerview
        Player *pPlayer2 = &player2;
        PlayerView *pvPlayer2 = new PlayerView(pPlayer2);


        /*if (playerCount < numberOfPlayers)
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
         }*/
/*
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

    bool allArmiesAssigned(vector<Player> *vp) {
        for (Player p : *vp) {
            if (p.getInitialArmies() != 0) {
                return false;
            }
        }
        return true;
    }

    void startupPhase(vector<Player> *vp, Map &map1) {
        cout << "STARTING UP" << endl;

        int playerCount = vp->size();

        static auto rng = std::default_random_engine{};

        cout << "There are " << playerCount << " players in the match." << endl;

        // randomizes all players
        std::shuffle(vp->begin(), vp->end(), rng);

        // randomly distribute territories
        vector<Territory> tempTVect = map1.getTerritory(); // will eventually be empty when all countries are assigned
        vector<Territory> occupiedTerritories; // placeholder vector
        int terrCount = tempTVect.size();
        cout << "There are " << terrCount << " territories to be distributed." << endl;

        int playerIndex = 0;
        string ownerName = "";
        string territoryName = "";

        cout << "====== Randomly assigning territories to players ======" << endl;
        for (Territory te : tempTVect) {
            std::shuffle(tempTVect.begin(), tempTVect.end(), rng);

            ownerName = vp->at(playerIndex).getName();  //gets name of player
            territoryName = tempTVect.back().getName(); //gets name of territory

            vp->at(playerIndex).addTerritory(tempTVect.back());  //adding a territory to a player from the player vector vp, added a notify()
            tempTVect.back().setTerritoryOwner(ownerName);      //sets the territory owner
            occupiedTerritories.push_back(tempTVect.back());    //adds the territory into occupied territories

            cout << ownerName << " was assigned " << territoryName << " (" << tempTVect.back().getX() << ","
                 << tempTVect.back().getY() << "), now they have " << vp->at(playerIndex).getCountries().size()
                 << " countries." << endl;

            playerIndex = (playerIndex + 1) % playerCount;

            tempTVect.pop_back();
        }

        cout << endl;

        // assign ownership to territories on the original map
        for (int i = 0; i < map1.getTerritory().size(); i++) {
            for (int j = 0; j < occupiedTerritories.size(); j++) {
                if (occupiedTerritories.at(j).getName() == map1.getTerritory().at(i).getName()) {
                    string occupier = occupiedTerritories.at(j).getTerritoryOwner();
                    map1.getTerritory().at(i).setTerritoryOwner(occupier);  //added a notify in its function definition
                }
            }
        }

        for (Player &p : *vp) {
            cout << p.getName() << " owns " << p.getCountries().size() << " territories:" << endl;
            cout << p.displayCountries() << endl;
        }

        cout << endl;

        // assign starting armies to players
        int startingArmy = 50 - (5 * playerCount);
        for (int i = 0; i < playerCount; i++) {
            vp->at(i).setInitialArmies(startingArmy);
            vp->at(i).addArmies(startingArmy);
            cout << vp->at(i).getName() << " was given " << vp->at(i).getInitialArmies() << " armies." << endl;
        }

        cout << endl;

        // assign armies to territories
        // maybe this should be done using reinforce(), will fix when pam is done with her part
        bool doneAssigning = false;
        while (!doneAssigning) {
            for (int j = 0; j < playerCount; j++) {
                bool successfulTurn = false;

                int userinput = 0;
                while (!successfulTurn) {
                    cout << vp->at(j).getName() << "s turn to assign initial armies." << endl;

                    cout << "Enter the territory number where you want to add armies:" << endl;
                    for (int k = 0; k < map1.getNbTerritories(); k++) {
                        for (int l = 0; l < vp->at(j).getCountries().size(); l++) {
                            if (map1.getTerritory().at(k).getName() == vp->at(j).getCountries().at(l).getName()) {
                                cout << "#" << k << " - " << map1.getTerritory().at(k).getName() << endl;
                            }
                        }
                    }
                    cin >> userinput;


                    if (userinput >= map1.getNbTerritories()) {
                        cout << "Invalid territory number." << endl;
                    } else {
                        string tempstr = map1.getTerritory().at(userinput).getName();
                        if (vp->at(j).hasCountry(tempstr)) {
                            int armySize;
                            cout << "How many armies do you want to assign to this territory?" << endl;
                            cin >> armySize;
                            if (armySize > vp->at(j).getInitialArmies()) {
                                cout << "You only have " << vp->at(j).getInitialArmies() << " armies to assign."
                                     << endl;
                                cin.clear();
                                cin.sync();
                            } else {
                                for (int k = 0; k < map1.getTerritory().size(); k++) {
                                    if (map1.getTerritory().at(k).getName() == tempstr) {
                                        map1.getTerritory().at(k).addArmies(armySize);
                                        vp->at(j).assignInitialArmyToCountry(armySize);
                                        cout << "You only have " << vp->at(j).getInitialArmies() << " left to assign."
                                             << endl;
                                        cout << "Army assigned, next player's turn!" << endl;
                                        cin.clear();
                                        cin.sync();
                                        successfulTurn = true;
                                    }
                                }
                            }
                        } else {
                            cout << "This territory does not belong to you." << endl;
                        }
                    }
                }
                doneAssigning = allArmiesAssigned(vp);
            }
        }
        cout << "Army assignments done." << endl;
    }

int main() {

    Map gen;
    Map map1;
    MapLoader loader;
    Hand hand;
    Deck deck;
    vector<Player> players;

    GameStart(&players, loader, map1, deck, hand);

    startupPhase(&players, map1);
    cout << "====== Territory Ownerships ======" << endl;
    for (Player& p : players){
        cout << p.getName() << " owns " << p.getCountries().size() << " territories:" << endl;
        cout << p.displayCountries() << endl;
    }
    for(int i=0; i<map1.getTerritory().size(); i++) {
        cout << map1.getTerritory().at(i).getName() << " is owned by " << map1.getTerritory().at(i).getTerritoryOwner()
             << " and it currently has " << map1.getTerritory().at(i).getArmies() << " armies" << endl;
    }

    MainGame game(players, map1);
    game.playGame();

    system("pause");



    return 0;

}
*/
