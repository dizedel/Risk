//
// Created by ramy on 2018-11-28.
//
#include <tournament.h>
#include <fstream>
#include <MapLoader.h>
#include <strategy/BenevolentPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <random>


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
        vector<Player> playersVector;   //a vector to hold all players

        //having troubles with creating strategies, and setting them for the players

        //vector<*Strategy> strategies;
       //BenevolentPlayer *benevolent ;
        //AggressivePlayer *aggressive;
        //CheaterPlayer *cheater;    //to be implemented
        //RandomPlayer *random;      //to be implemented
        //strategies->push_back(benevolent);
        //strategies->push_back(aggressive);
        //strategies->push_back(cheater);       //to be implemented
        //strategies->push_back(random);         //to be implemented

        int setter = 0;
        while(playersVector.size() < numberOfPlayers)
        {
            //setter = rand()%strategies.size();
            Player player;
            //player.setStrategy(&strategies.at(setter));
            playersVector.push_back(player);
        }


        cout << "\n \nplayersVector consists of: " << playersVector.size() << "players" <<endl;
       cout << "with strategies : " << " will fix later"<< endl;


    }
}
