//
// Created by ramy on 2018-11-28.
//
#include <Tournament.h>
#include <fstream>
#include <MapLoader.h>
#include <strategy/BenevolentPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <random>
#include <MainGame.h>
#include <GameStats.h>

// Applying singleton pattern to Tournament
Tournament* Tournament::instance=0;

Tournament* Tournament::getInstance(){
    if(instance==0){
        cout << "Tournament created" << endl;
        instance=new Tournament();
    }
    return instance;
}
Tournament::Tournament(){}

Tournament::Tournament(int numMaps, int numPlayers, int numGames, int numTurns) {
    if(instance==0){
        numOfMaps=numMaps;
        numOfPlayers=numPlayers;
        numOfGames=numGames;
        numOfTurns=numTurns;
        instance=this;
        cout << "Tournament created2" << endl;
    }
}

void Tournament::setNumPlayers(int n) {
    numOfPlayers=n;
}

void Tournament::setNumGames(int n){
    numOfGames=n;
}

void Tournament::setNumTurns(int n) {
    numOfTurns=n;
}

void Tournament::setNumMaps(int n) {
    numOfMaps=n;
}

int Tournament::getNumMaps(){
    return numOfMaps;
}

int Tournament::getNumPlayers() {
    return numOfPlayers;
}

int Tournament::getNumGames(){
    return numOfGames;
}

int Tournament::getNumTurns() {
    return numOfTurns;
}

void Tournament::addToMapList(string s){
    mapList.push_back(s);
}

void Tournament::setMapList(vector<string> vs) {
    mapList=vs;
}

vector<string> Tournament::getMapList() {
    return mapList;
}

void Tournament::printMapList(){
    string temp="Maps to be played: \n";
    if(mapList.size()>0){
        for(int i=0; i<mapList.size(); i++){
            temp = temp + to_string(i) + " - " + mapList[i] + "\n";
        }
    }
    else{
        temp= "The map list is empty.";
    }
    cout << temp;
}

bool Tournament::allArmiesAssigned(vector<Player> *vp) {
    for (Player p : *vp) {
        if (p.getInitialArmies() != 0) {
            return false;
        }
    }
    return true;
}

void Tournament::startupPhase(vector<Player> *vp, Map &map1) {
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


void Tournament::setUpPlayers(int playerCount, vector<Player> *vp){
    BenevolentPlayer* benevolent = new BenevolentPlayer();
    AggressivePlayer* aggressive = new AggressivePlayer();
    for(int pc=0; pc<playerCount; pc++){

        //Setting up player objects and vector
        Player player("PLAYER" + to_string(pc));
        bool stratSelectSuccess=false;
        int strat=0;
        while(!stratSelectSuccess){
            cout << "Enter a number to select the strategy for player #" << pc << endl;
            cout << "1: Aggressive" << endl;
            cout << "2: Benevolent" << endl;
            cout << "3: Random" << endl;
            cout << "4: Cheater" << endl;
            cin >> strat;
            if(strat<1 || strat>4){
                cout << "Invalid selection." << endl;
            }
            else{
                stratSelectSuccess=true;
                switch(strat){
                    case '1':
                        player.setStrategy(aggressive);
                    case '2':
                        player.setStrategy(benevolent);
                    case '3':
                        // STRATEGY IS NOT YET IMPLEMENTED
                        //player.setStrategy(random);
                    case '4':
                        // STRATEGY IS NOT YET IMPLEMENTED
                        //player.setStrategy(cheater);
                    default:
                        break;
                }
            }
            vp->push_back(player);
        }
    }
}

void Tournament::playTournament(){
    cout<< "Num of maps: " << getNumMaps() <<endl;
    cout<< "Num of games: " << getNumGames() <<endl;
    cout<< "Num of players: " << getNumPlayers() <<endl;
    cout<< "Num of turns: " << getNumTurns() <<endl;
    printMapList();

    for(int i=0; i<getNumMaps(); i++){
        for(int j=0; j<getNumGames(); j++){
            cout << "Now playing game #" << j << " on map #" << i << endl;
            setUpPlayers(getNumPlayers(), &tournamentPlayers);

            //startup

            //autoplay

            //declare winner and save winner into vector for future use

            tournamentPlayers.clear();
            cout << "Game over!" << endl;
        }
    }

}



