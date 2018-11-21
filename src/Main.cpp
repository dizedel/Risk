
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
#include <strategy/BenevolentPlayer.h>
#include <strategy/AggressivePlayer.h>
#include <strategy/HumanPlayer.h>
#include "Player.h"
#include "game/Fortify.h"
#include "game/Attack.h"
#include "Dice.h"
#include "game/Reinforce.h"
#include "MainGame.h"
#include "Pattern/PlayerView.h"
#include "Pattern/GameStats.h"


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

            for(int j=0;i<terrCount;j++){
                if(map1.getTerritory().at(j).getName()==territoryName){
                    map1.getTerritory().at(j).setTerritoryOwner(ownerName);
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
        Territory territoryInPlaceholder;
        Territory territoryInActualMap;
        string occupier="";
        for (int i = 0; i < map1.getTerritory().size(); i++) {
            for (int j = 0; j < occupiedTerritories.size(); j++) {
                territoryInPlaceholder = occupiedTerritories.at(j);
                territoryInActualMap = map1.getTerritory().at(i);
                if (territoryInPlaceholder.getName() == territoryInActualMap.getName()) {
                    occupier = territoryInPlaceholder.getTerritoryOwner();
                    territoryInActualMap.setTerritoryOwner(occupier);  //added a notify in its function definition
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


void testGameStats(){
    Map map1;
    MapLoader loader1;
    loader1.loadMapFile("../maps/mini.map");
    map1=loader1.getMap();
    cout << "creating map" << endl;
    map1.createMap(map1);
    BenevolentPlayer* benevolent = new BenevolentPlayer();
    HumanPlayer* human = new HumanPlayer();
    AggressivePlayer* aggressive = new AggressivePlayer;
    Player p1("Apple");
    p1.setStrategy(human);
    Player p2("Orange");
    p2.setStrategy(human);
    cout << "p2 strat " << p2.getStrategy().toString();
    vector<Player> vp;
    Hand hand1;
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
    cout << "####### End of Demo #######" << endl;
}

int main() {
    testGameStats();

    system("pause");

    return 0;

}
