//
// Created by ramy on 2018-11-28.
//
#include <tournament.h>
#include <fstream>
#include <MapLoader.h>
#include <strategy/BenevolentPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <random>
#include <MainGame.h>
#include <GameStats.h>

tournament::tournament() {
    cout << "which mode would you like to select? " << endl;
    cout << " 1 for single game. 2 for tournament mode. " << endl;

    int gameModeSelection;
    cin >> gameModeSelection;
    cout << "you have selected : game mode " << gameModeSelection << endl;

    if (gameModeSelection == 1)
        cout << "lol not implemented yet" << endl;
    else {

            //=================selecting a map==============================================
            string test;    //a temp string to read from the maps txt file
            int mapSelection = 0;   //which map will the user select
            int mapSelectionCounter = 0; //counts how many maps are available
            vector<string> mapNames; //will be used to store map names then used to create the map

            cout << " \n please select a map, enter the number of the map(1, 2, etc....) " << endl;
            ifstream myFile("C:\\Users\\alway\\Documents\\GitHub\\Risk\\maps\\listOfMaps.txt");
            if (myFile.is_open())
                cout << "\n file could be opened" << endl;
            while (!myFile.eof()) {
                getline(myFile, test);
                mapSelectionCounter++;
                mapNames.push_back(test);
                cout << mapSelectionCounter << ". " << test << endl;
            }
            myFile.close();

            cin >> mapSelection;
            while (mapSelection <= 0 || mapSelection > mapSelectionCounter) {
                cout << "you have selected a map that doesnt exist please enter a new number" << endl;
                cin >> mapSelection;
            }
            cout << "loading map : " << mapNames.at(mapSelection - 1) << endl;


            //===================selecting how many players ==============================
            int numberOfPlayers;

            cout << "\n enter how many players would be playing (2-4) " << endl;
            cin >> numberOfPlayers;
            while (numberOfPlayers < 2 || numberOfPlayers > 4) {
                cout << "you have entered an invalid amount of players, enter again" << endl;
                cin >> numberOfPlayers;
            }
            cout << "number of players: " << numberOfPlayers <<endl;


            //==================selecting number of games to be played====================
            int numberOfGames;

            cout << "enter how many games are to be played (1-5): " <<endl;
            cin >> numberOfGames;
            while(numberOfGames < 1 || numberOfGames > 5)
            {
                cout << "invalid number of games to be played, enter a valid number" <<endl;
                cin >> numberOfGames;
            }
            cout << "number of games to be played : " << numberOfGames <<endl;

            //selecting number of turns
            int numberOfTurns;

            cout << "enter number of turns to be played, if exceeded game is ended as draw (3 - 50)"<<endl;
            cin >> numberOfTurns;
            while(numberOfTurns < 3 || numberOfTurns > 50)
            {
                cout << "invalid number of turns, enter valid number" << endl;
                cin >> numberOfTurns;
            }
            cout << "number of turns : " << numberOfTurns << endl;

            //====================loading the map============================================
            MapLoader mapLoader;
            string mapName = mapNames.at(mapSelection - 1);

            mapLoader.loadMapFile(mapName); //load the map
            Map map = mapLoader.getMap();   //store the loaded map into a map object

            //===================Creating Players============================================
            vector<Player> *playersVector = new vector<Player>;   //a vector to hold all players

            //having troubles with creating strategies, and setting them for the players

            //vector<*Strategy> strategies;
            BenevolentPlayer *benevolent  = new BenevolentPlayer();
            AggressivePlayer *aggressive = new AggressivePlayer();
            //CheaterPlayer *cheater;    //to be implemented
            //RandomPlayer *random;      //to be implemented
            //strategies->push_back(benevolent);
            //strategies->push_back(aggressive);
            //strategies->push_back(cheater);       //to be implemented
            //strategies->push_back(random);         //to be implemented

            int setter = 0;
            for (int i = 0; i < numberOfPlayers ; ++i)
            {
                //setter = rand()%strategies.size();
                string playerName = "player" + to_string(i+1);
                Player player;
                player.setName(playerName);
                //player.setStrategy(&strategies.at(setter));
                playersVector->push_back(player);
            }


            cout << "\n \nplayersVector consists of: " << playersVector->size() << "players" <<endl;
           cout << "with strategies : " << " will fix later"<< endl;
            playersVector->at(0).setStrategy(benevolent);
            playersVector->at(1).setStrategy(aggressive);
            cout << " player 0 has strat " << playersVector->at(0).getStrategy()->toString()<<endl;
            cout << "player 1 has strat " << playersVector->at(1).getStrategy()->toString()<<endl;

            //========================startup Phase, Assigning armies=============================================
            startupPhase(playersVector, map);


            //========================play the game===============================================================
            vector<Player> &playersVector1 = *playersVector;
            MainGame mainGame = MainGame(playersVector1, map);

            //cout << "plase work" << mainGame.getPlayers().size();
            //cout << mainGame.getMap().getTerritory().size();

            GameStats gs(&mainGame);
            mainGame.playGame();
    }
}

void tournament::startupPhase(vector<Player> *vp, Map &map1)
{
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

bool tournament::allArmiesAssigned(vector<Player> *vp) {
    for (Player p : *vp) {
        if (p.getInitialArmies() != 0) {
            return false;
        }
    }
    return true;
}



