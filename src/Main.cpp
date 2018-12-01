#include "stdafx.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <vector>

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
#include "strategy/BenevolentPlayer.h"
#include "strategy/AggressivePlayer.h"
#include "strategy/HumanPlayer.h"
#include "Player.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include "game/Reinforce.h"
#include "Dice.h"
#include "MainGame.h"
#include "Pattern/PlayerView.h"
#include "Pattern/GameStats.h"
#include "Tournament.h"

using namespace std;

int Hand::exchangedHands = 0;

bool allArmiesAssigned(vector<Player> *vp) {
    for (Player p : *vp) {
        if (p.getInitialArmies() != 0) {
            return false;
        }
    }
    return true;
}

void startupPhase(vector<Player> *vp, Map &map1) {
        cout << "####### STARTING UP #######" << endl;

        int playerCount = vp->size();

        static auto rng = std::default_random_engine{};

        cout << "There are " << playerCount << " players in the match." << endl;

        // randomizes all players
        std::shuffle(vp->begin(), vp->end(), rng);


        vector<Territory> tempTVect = map1.getTerritory(); // will eventually be empty when all countries are assigned
        vector<Territory> occupiedTerritories; // placeholder vector
        int terrCount = tempTVect.size();
        cout << "There are " << terrCount << " territories to be distributed." << endl;

        int playerIndex = 0;
        string ownerName = "";
        string territoryName = "";

        // randomly distribute territories
        cout << "####### Randomly distributing unoccupied territories #######" << endl;
        for(int i=0; i<terrCount; i++){
            int randomT = rand() % tempTVect.size();
            Territory territoryToBeAssigned = tempTVect.at(randomT);
            Player player = vp->at(playerIndex);

            ownerName = vp->at(playerIndex).getName();  //gets name of player
            territoryName = territoryToBeAssigned.getName(); //gets name of territory

            territoryToBeAssigned.setTerritoryOwner(ownerName);

            for(int j=0;i<terrCount;j++){
                if(map1.getTerritory().at(j).getName()==territoryName){
                    map1.getTerritory().at(j).setTerritoryOwner(ownerName);
                    //vp->at(playerIndex).getCountries().push_back(map1.getTerritory().at(j));
                    break;
                }
            }

            vp->at(playerIndex).addCountry(territoryToBeAssigned);
            territoryToBeAssigned.setTerritoryOwner(ownerName);      //sets the territory owner
            occupiedTerritories.push_back(territoryToBeAssigned);

            cout << ownerName << " was assigned " << territoryToBeAssigned.getName() << " (" << territoryToBeAssigned.getX() << ","
                 << territoryToBeAssigned.getY() << "), now they have " << vp->at(playerIndex).getCountries().size()
                 << " countries." << endl;

            playerIndex = (playerIndex + 1) % playerCount;
            tempTVect.erase(tempTVect.begin() + randomT);
        }

        cout << endl;

        // assign ownership to territories on the original map
        string occupier="";
        for (int i = 0; i < map1.getTerritory().size(); i++) {
            for (int j = 0; j < occupiedTerritories.size(); j++) {
                if (occupiedTerritories.at(j).getName() == map1.getTerritory().at(i).getName()) {
                    occupier = occupiedTerritories.at(j).getTerritoryOwner();
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
        bool doneAssigning = false;
        cout << "####### Begin assigning initial armies to territories #######" << endl;
        while (!doneAssigning) {
            for (int j = 0; j < playerCount; j++) {
                bool successfulTurn = false;

                int userinput = 0;
                while (!successfulTurn && vp->at(j).getInitialArmies()>0) {
                    cout << vp->at(j).getName() << "s turn to assign initial armies." << endl;

                    cout << "Enter the territory number where you want to add armies, reminder that you have " << vp->at(j).getInitialArmies() << " armies left to assign." << endl;
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
                        string chosenTerritory = map1.getTerritory().at(userinput).getName();
                        if (vp->at(j).hasCountry(chosenTerritory)) {
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
                                    if (map1.getTerritory().at(k).getName() == chosenTerritory) {
                                        map1.getTerritory().at(k).addArmies(armySize); // assigns armies to territory on map
                                        vp->at(j).assignInitialArmyToCountry(armySize); // removes initial army count from player

                                        for(int l=0; l<vp->at(j).getCountries().size();l++){
                                            if(vp->at(j).getCountries().at(l).getName()==chosenTerritory){
                                                vp->at(j).getCountries().at(l).copyTerritory(map1.getTerritory().at(k), vp->at(j).getCountries().at(l));

                                                //debugging
                                                //cout << map1.getTerritory().at(k).getArmies() << map1.getTerritory().at(k).getTerritoryOwner() << endl;
                                                //cout << vp->at(j).getCountries().at(l).getArmies() << vp->at(j).getCountries().at(l).getTerritoryOwner() << endl;
                                            }
                                        }

                                        cout << "You now have " << vp->at(j).getInitialArmies() << " left to assign."
                                             << endl;
                                        cout << "####### Army assigned, next player's turn! #######" << endl;
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

        for(Territory te : map1.getTerritory()){
            cout << te.getName() << " occupied by " << te.getTerritoryOwner() << " has " << te.getArmies() <<  " armies stationed." << endl;
        }
        cout << "####### Army assignments done #######" << endl;
}

void populateMapList(int numOfMaps){
    //=================selecting a map==============================================
    string test;    //a temp string to read from the maps txt file
    int mapSelection = 0;   //which map will the user select
    int mapSelectionCounter = 0; //counts how many maps are available
    int numOfMapsToPlay=numOfMaps;
    vector<string> mapNames; //will be used to store map names then used to create the map

    cout << " \nPlease select a map, enter the number of the map(1, 2, etc....) " << endl;
    ifstream listOfMaps("../maps/listOfMaps.txt");
    if(listOfMaps.is_open()){
        cout << "\nAvailable maps:" << endl;
        while (!listOfMaps.eof()) {
            getline(listOfMaps, test);
            cout << mapSelectionCounter << ". " << test << endl;
            mapNames.push_back(test);
            mapSelectionCounter++;
        }
        listOfMaps.close();
        cout << "You have chosen to play " << numOfMapsToPlay << " maps" << endl;
        for(int i=0; i<numOfMapsToPlay; i++){

            bool selectionSuccess=false;
            while (!selectionSuccess) {
                cout << "Now selecting map #" << i << " out of " << numOfMapsToPlay << endl;
                cin >> mapSelection;

                if(mapSelection < 0 || mapSelection >= mapSelectionCounter){
                    cout << "You have selected a map that doesnt exist, please enter the right number" << endl;
                    selectionSuccess=false;
                }
                else{
                    cout << "Map queued." << endl;
                    Tournament::getInstance()->addToMapList(mapNames[mapSelection]);
                    selectionSuccess=true;
                }
            }
        }
    }
    else{
        cout << "Map list file unavailable." << endl;
        exit(0);
    }
}

void inputTournamentSettings(){
    //===================selecting how many players ==============================
    int numberOfMaps;
    cout << "\nEnter the number of maps to be played (1-5) " << endl;
    cin >> numberOfMaps;
    while (numberOfMaps < 1 || numberOfMaps > 5) {
        cout << "You have entered an invalid amount of maps, enter again" << endl;
        cin >> numberOfMaps;
    }
    cout << "Number of maps: " << numberOfMaps <<endl;

    //===================selecting how many players ==============================
    int numberOfPlayers;
    cout << "\nEnter how many players would be playing (2-4) " << endl;
    cin >> numberOfPlayers;
    while (numberOfPlayers < 2 || numberOfPlayers > 4) {
        cout << "You have entered an invalid amount of players, enter again" << endl;
        cin >> numberOfPlayers;
    }
    cout << "Number of players: " << numberOfPlayers <<endl;

    //==================selecting number of games to be played====================
    int numberOfGames;
    cout << "\nEnter how many games are to be played (1-5): " <<endl;
    cin >> numberOfGames;
    while(numberOfGames < 1 || numberOfGames > 5)
    {
        cout << "Invalid number of games to be played, enter a valid number" <<endl;
        cin >> numberOfGames;
    }
    cout << "Number of games to be played : " << numberOfGames <<endl;

    //==================selecting number of turns==================
    int numberOfTurns;
    cout << "\nEnter number of turns to be played, if exceeded game is ended as draw (3 - 50)"<<endl;
    cin >> numberOfTurns;
    while(numberOfTurns < 3 || numberOfTurns > 50)
    {
        cout << "Invalid number of turns, enter valid number" << endl;
        cin >> numberOfTurns;
    }
    cout << "Number of turns : " << numberOfTurns << endl;

    Tournament tnm(numberOfMaps, numberOfPlayers, numberOfGames, numberOfTurns);
    populateMapList(numberOfMaps);
    Tournament::getInstance()->playTournament();
}

void setupGame(int numOfMaps){
    Map map1;
    MapLoader loader1;
    Hand hand1;
    vector<Player> vp;

    if(numOfMaps==1){ //if user chose to play only 1 game
        populateMapList(1);
        //loader1.loadMapFile("../maps/mini.map");
        loader1.loadMapFile(Tournament::getInstance()->getMapList().at(0));
        map1=loader1.getMap();
        cout << "creating map" << endl;
        map1.createMap(map1);
        HumanPlayer* human = new HumanPlayer();
        Player p1("Apple");
        p1.setStrategy(human);
        Player p2("Orange");
        p2.setStrategy(human);
        cout << "p1 strat " << p1.getStrategy()->toString() << endl;
        cout << "p2 strat " << p2.getStrategy()->toString() << endl;
        Deck deck1(map1.getTerritory().size());
        vp.push_back(p1);
        vp.push_back(p2);
        cout << "Number of cards: " << deck1.getCards().size() << endl;

        for (int i = 0; i < vp.size(); i++)
        {
            vp.at(i).setHand(hand1);
        }

        startupPhase(&vp, map1);
        MainGame game(vp, map1);
        GameStats gs(&game);
        game.playGame();
        game.~MainGame();
    }
    else{ // if user chose to play tournament mode
        inputTournamentSettings();
    }
    cout << "####### End of Demo #######" << endl;
}

int main() {
    bool validModeSelection=false;
    cout << "Which mode would you like to play? " << endl;

    while(!validModeSelection){
        cout << "Enter 1 for single game. 2 for tournament mode. " << endl;
        int gameModeSelection;
        cin >> gameModeSelection;
        cout << "You have selected:" << gameModeSelection << endl;
        if (gameModeSelection == 1 || gameModeSelection == 2){
            validModeSelection=true;
            setupGame(gameModeSelection);
        }
        else {
            validModeSelection=false;
            cout << "Invalid mode" << endl;
        }
    }

    //setupMap();

    system("pause");

    return 0;

}
