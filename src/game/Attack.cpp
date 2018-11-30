//
// Created by aloys on 2018-11-08.
//

#include "game/Attack.h"

using namespace std;

Attack::Attack(){}

Attack::Attack(Player p, vector<Player>* pV, Map &m){
    attacker = p;
    pVector = pV;
    map = m;
}

void Attack::setAttacker(Player p){
    attacker=p;
}

void Attack::setPlayerVector(vector<Player>* pV){
    pVector=pV;
}

void Attack::setMap(Map &m){
    map=m;
}

void Attack::setAttackCountry(string) {

}

Attack::~Attack()
{
}



void Attack::attack() {
    // Player decides if he wishes to attack or pass his turn
    if (!attackOrNot()) {
        return;
    }
    // Player selects the country from which he wishes to initiate attack
    attackCountry = attackingCountrySelection();
    // Give the player a chance to desist the attacking phase
    if (stopAttack()) {
        return;
    }
    // Player selects country to attack from neighbors of selected country
    defendCountry = map.matchTerritory(defendingCountry());
    // Get the number of armies on each territory (Defense and Attack)
    numberOfArmiesAttack = attackCountry.getArmies();
    cout << "Attacker has : " << numberOfArmiesAttack << " armies" << endl;
    numberOfArmiesDefend = defendCountry.getArmies();
    cout << "Defender has : " << numberOfArmiesDefend << " armies." << endl;
    if(stopAttack()){
        return;
    }
    // Attacking and Defending player roll
    diceAttack();

    cout << "Do you wish to attack again? (Type ATTACK)" << endl;
    string answer;
    cin >> answer;

    if(answer == "ATTACK"){
        attack();
    }else{
        return;
    }

}


bool Attack::attackOrNot(){
    cout << "Would " + attacker.getName() + " like to attack ? (Y or N)" << endl;
    string answer;
    cin >> answer;

    if(answer == "Y" || answer == "y"){
        return true;
    }else if(answer == "N" || answer == "n"){
        return false;
    }else{
        cout << "Please try again. Your entry was not valid." << endl;
        return attackOrNot();
    }
}

Territory Attack::attackingCountrySelection(){
    string nameOfAttackCountry;
    Territory tempAttackCountry;
    bool notEnoughArmies = true;
    while(attacker.posOfCountry(nameOfAttackCountry) == -1 || notEnoughArmies) {
        cout << "List of countries you own : " << endl;
        string attackerCountryList = attacker.displayCountries();
        cout << attackerCountryList << endl;
        cout << "Which country do you want to attack from?" << endl;
        cin >> nameOfAttackCountry;
        if(attacker.posOfCountry(nameOfAttackCountry) == -1){
            cout << "You do not own that country. Try Again." << endl;
        }else{
            /*
            vector<Territory> attackCountriesVector = attacker.getCountries();
            int countryPosTemp = attacker.posOfCountry(nameOfAttackCountry);
            tempAttackCountry = attackCountriesVector.at(countryPosTemp);
             */
            tempAttackCountry = map.matchTerritory(nameOfAttackCountry);
            if(tempAttackCountry.getArmies() < 2){
                cout << "Number of armies in attack : " << tempAttackCountry.getArmies() << endl;
                notEnoughArmies = true;
                cout << "Not enough armies on this territory." << endl;
            }else{
                sourceCountryName=nameOfAttackCountry;
                notEnoughArmies = false;
            }
        }
    }

    return tempAttackCountry;
}

string Attack::defendingCountry(){
    // Countries that player can attack are listed
    vector<string> attackCountryNeighborsList = filterNeighbors(attackCountry.getNeighbors());
    cout << "List of countries you can attack : " << endl << endl;
    for(auto i : attackCountryNeighborsList){
        cout << i << endl;
    }
    //
    bool countryIsNeighbor = false;
    string nameOfDefendCountry;
    while(!countryIsNeighbor) {
        cout << "Which country would you like to attack?" << endl;
        cin >> nameOfDefendCountry;
        for(auto i : attackCountryNeighborsList ){
            if(i == nameOfDefendCountry){
                countryIsNeighbor = true;
                targetCountryName=nameOfDefendCountry;


                for(int j=0; j<pVector->size(); j++){
                    for(int k=0; k<pVector->at(j).getCountries().size(); k++){
                        if(targetCountryName==pVector->at(j).getCountries().at(k).getName()){
                            defender=pVector->at(j);
                        }
                    }
                }


                break;
            }
        }
        if(!countryIsNeighbor){
            cout << "Your entry is invalid, please try again." << endl;
        }
    }
    return nameOfDefendCountry;
 }

 void Attack::diceAttack(){
     int numberOfAttackDice = 0;
     while(numberOfAttackDice <= 0 || numberOfAttackDice >= numberOfArmiesAttack-1 || numberOfAttackDice > 3){
         cout << "How many dice would the attacker like to roll? (1 to 3, max: Armies-1)" << endl;
         cin >> numberOfAttackDice;
     }
     int numberOfDefendDice = 0;
     while(numberOfDefendDice <= 0 || numberOfDefendDice >= numberOfArmiesDefend-1 || numberOfDefendDice > 2){
         cout << "How many dice would the defender like to roll? (1 to 2, max: Armies-1)" << endl;
         cin >> numberOfDefendDice;
     }
     Dice attackerDice = attacker.getDice();
     Dice defenderDice = defender.getDice();

     int count = 0;

     while(numberOfArmiesAttack != 0 && numberOfArmiesDefend != 0){
         count++;
         cout << "ROLL # " << count << endl;
         cout << "Number of armies attacker : " << numberOfArmiesAttack << endl;
         cout << "Number of armies defender : " << numberOfArmiesDefend << endl;
         vector<int> attackerDiceV = attackerDice.rolls(numberOfAttackDice);
         vector<int> defenderDiceV = defenderDice.rolls(numberOfDefendDice);
         // sorted both vectors of dice
         sort(attackerDiceV.begin(), attackerDiceV.end());
         reverse(attackerDiceV.begin(), attackerDiceV.end());
         sort(defenderDiceV.begin(), defenderDiceV.end());
         reverse(defenderDiceV.begin(), defenderDiceV.end());
         // compare by pairs
         int compares=0;
         if(numberOfAttackDice < numberOfDefendDice){
             compares = numberOfAttackDice;
         }else{
             compares = numberOfDefendDice;
         }
         for(int i = 0; i < compares; i++){
             if(attackerDiceV[i] <= defenderDiceV[i]){
                 cout << "Defender has won this pair ! Attacker Role : " << attackerDiceV[i] << "; Defender Role: " << defenderDiceV[i] << endl;
                 numberOfArmiesAttack--;
             }else{
                 cout << "Attacker has won this pair ! Attacker Role : " << attackerDiceV[i] << "; Defender Role: " << defenderDiceV[i] << endl;
                 numberOfArmiesDefend--;
             }
         }
     }
     cout << "Number of armies on attacking country left : " << numberOfArmiesAttack << endl;
     cout << "Number of armies on defending country left : " << numberOfArmiesDefend << endl;
     attackCountry.setArmies(numberOfArmiesAttack);
     defendCountry.setArmies(numberOfArmiesDefend);
     if(numberOfArmiesAttack == 0){
         cout << "Defender " << defender.getName() << " has won this round of attack! Both countries keep their respective territories." << endl;
     }else{
         wasConquered=true;
         cout << "Attacker " << attacker.getName() << " has won this round of attack! They now own : " << defendCountry.getName() << endl;
         // Set Territory to have new owner and then remove from defender's territory vector


         defendCountry.setTerritoryOwner(attacker.getName());
        // int tempPos = defender.posOfCountry(defendCountry.getName());
         vector<Territory> tempCountryVectorDefender = defender.getCountries();

         /*
          * Aloys's code
         for( vector<Territory>::iterator i = tempCountryVectorDefender.begin(); i != tempCountryVectorDefender.end(); i++){
             if(i->getName() == defendCountry.getName()) {
                 tempCountryVectorDefender.erase(i);
             }
         }*/

        //new
         for(int i=0; i<pVector->size(); i++){
             for(int j=0; j<tempCountryVectorDefender.size(); j++){
                 if(targetCountryName==tempCountryVectorDefender.at(j).getName()){
                     tempCountryVectorDefender.erase(tempCountryVectorDefender.begin()+j);
                 }
             }
         }


         bool numberOfArmiesBool = false;
         while(!numberOfArmiesBool) {
             int numberOfArmiesToAdd = 0;
             cout << "How many armies do you wish to move to your new conquest?" << endl;
             cout << "Number of armies left on attacking country : " << attackCountry.getArmies() << endl;
             cin >> numberOfArmiesToAdd;
             if(numberOfArmiesToAdd == 0){
                 break;
             }else if (numberOfArmiesToAdd > attackCountry.getArmies() - 1 || numberOfArmiesToAdd < 0) {
                 cout << "Invalid, you must leave at least one army on attacking country and must be positive." << endl;
             }else{
                 cout << numberOfArmiesToAdd << endl;
                 defendCountry.setArmies(numberOfArmiesToAdd);
                 attackCountry.setArmies(attackCountry.getArmies()-numberOfArmiesToAdd);

                 defender.setCountries(tempCountryVectorDefender); // refreshes defender's country vector
                 attacker.addCountry(defendCountry); // set newly conquered territory to attacker

                 numberOfArmiesBool = true;

                // copies
                 for(int i=0; i<attacker.getCountries().size(); i++){
                     if(attacker.getCountries().at(i).getName()==attackCountry.getName()){
                         attacker.getCountries().at(i).copyTerritory(attackCountry, attacker.getCountries().at(i));
                     }
                 }

                 for(int i=0; i<defender.getCountries().size(); i++){
                     if(defender.getCountries().at(i).getName()==defendCountry.getName()){
                         defender.getCountries().at(i).copyTerritory(defendCountry, defender.getCountries().at(i));
                     }
                 }

                 // assigns ownership in player vectors
                 for(int i=0; i<pVector->size(); i++){
                     if(pVector->at(i).getName()==attacker.getName()){
                         pVector->at(i).setCountries(attacker.getCountries());
                     }
                 }
                 for(int i=0; i<pVector->size(); i++){
                     if(pVector->at(i).getName()==defender.getName()){
                         pVector->at(i).setCountries(defender.getCountries());
                     }
                 }

                 // assigns ownership in territory vectors
                 Player currentPlayer;
                 for(int i=0; i<map.getTerritory().size(); i++){
                     for(int j=0; j<pVector->size(); j++){
                         currentPlayer=pVector->at(j);
                         for(int k=0; k< currentPlayer.getCountries().size(); k++){
                             if(currentPlayer.getCountries().at(k).getName() == map.getTerritory().at(i).getName()){
                                 map.getTerritory().at(i).setTerritoryOwner(currentPlayer.getName());
                             }
                         }
                     }
                 }

                 // assigns army counts
                 for(int i=0; i<map.getTerritory().size(); i++){
                     for(int j=0; j<pVector->size(); j++){
                         for(Territory te : pVector->at(j).getCountries()){
                             if(te.getName()==map.getTerritory().at(i).getName()){
                                 map.getTerritory().at(i).copyTerritory(te, map.getTerritory().at(i));
                             }
                         }
                     }
                 }

                 //updates player armies
                 //works
                 int newArmyCount;
                 for(int q=0; q<pVector->size(); q++){
                     newArmyCount=0;
                     for(int i=0; i<pVector->at(q).getCountries().size(); i++){
                         for(int j=0; j<map.getTerritory().size(); j++){
                             if(pVector->at(q).getCountries().at(i).getName()==map.getTerritory().at(j).getName()){
                                 newArmyCount+=map.getTerritory().at(j).getArmies();
                             }
                         }
                     }
                     pVector->at(q).setArmies(newArmyCount);
                 }


                cout<< "##########" <<endl;
                 //debugging
                 Territory te;
                 for(int i=0; i<map.getTerritory().size(); i++){
                     te = map.getTerritory().at(i);
                     cout << te.getName() << " | " << te.getArmies() << " | " << te.getTerritoryOwner() << endl;
                 }
                 cout<< "##########" <<endl;
                 //debugging
                 for(int i=0; i<pVector->size(); i++){
                     for(int j=0; j<pVector->at(i).getCountries().size(); j++){
                         cout << pVector->at(i).getCountries().at(j).getName() << " | " << pVector->at(i).getCountries().at(j).getArmies() << endl;
                     }
                 }

             }
         }

         cout << "Number of armies on attacking country : " << attackCountry.getArmies() << endl;
         cout << "Number of armies on defending country : " << defendCountry.getArmies() << endl;

     }
}


bool Attack::stopAttack(){
    cout << "Would you like to stop the attack? (Type 'STOP')" << endl;
    string answer;
    cin >> answer;
    if(answer=="STOP"){
        cout << "Stopping attack..." << endl;
        return true;
    }else{
        cout << "Ok, continuing attack..." << endl;
        return false;
    }
}

vector<string> Attack::filterNeighbors(vector<string> neighbors){
    vector<Territory> tempVector = attacker.getCountries();
    for(auto i : tempVector){
        for(int j = 0; j < size(neighbors); j++){
            if(i.getName() == neighbors[j]){
                neighbors.erase(neighbors.begin()+j);
            }
        }
    }
    return neighbors;
}

bool Attack::wasTerritoryConquered(){
    return wasConquered;
}

void Attack::autoAttack(){
    attackCountry.setNumber
}