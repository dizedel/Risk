//
// Created by aloys on 2018-11-08.
//

#include "game/Attack.h"

using namespace std;

Attack::Attack(){}

Attack::Attack(Player p, vector<Player> pV){
    attacker = p;
    pVector = pV;

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
    defendCountry = defendingCountry();
    // Get the number of armies on each territory (Defense and Attack)
    numberOfArmiesAttack = attacker.getArmies();
    cout << "Attacker has :" << numberOfArmiesAttack << " armies" << endl;
    numberOfArmiesDefend = defender.getArmies();
    cout << "Defender has :" << numberOfArmiesDefend << " armies." << endl;
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
            vector<Territory> attackCountriesVector = attacker.getCountries();
            int countryPosTemp = attacker.posOfCountry(nameOfAttackCountry);
            tempAttackCountry = attackCountriesVector.at(countryPosTemp);
            if(tempAttackCountry.getArmies() < 2){
                notEnoughArmies = true;
                cout << "Not enough armies on this territory." << endl;
            }else{
                notEnoughArmies = false;
            }
        }
    }

    return tempAttackCountry;
}

Territory Attack::defendingCountry(){
    vector<string> attackCountryNeighborsList = attackCountry.getNeighbors();
    cout << "List of countries you can attack : " << endl;
    for(auto i : attackCountryNeighborsList){
        cout << i << endl;
    }

    bool countryIsNeighbor = false;
    string nameOfDefendCountry;
    while(!countryIsNeighbor) {
        cout << "Which country would you like to attack?" << endl;
        cin >> nameOfDefendCountry;
        for(auto i : attackCountryNeighborsList ){
            if(i == nameOfDefendCountry){
                countryIsNeighbor = true;
            }else{
                cout << "Country is not a neighbor or does not exist. Please check your spelling." << endl;
            }
        }
    }
    // Find the defend country territory object
    Territory tempDefendCountry;
    for( auto i : pVector){
        vector<Territory> pTemp = i.getCountries();
        if(i.hasCountry(nameOfDefendCountry)){
            int pos = i.posOfCountry(nameOfDefendCountry);
            tempDefendCountry = pTemp[pos];
            defender = i;
        }
    }
    return tempDefendCountry;
 }

 void Attack::diceAttack(){
     int numberOfAttackDice = 0;
     while(numberOfAttackDice <= 0 || numberOfAttackDice > numberOfArmiesAttack-1 || numberOfAttackDice > 3){
         cout << "How many dice would the attacker like to roll? (1 to 3, max: Armies-1)" << endl;
         cin >> numberOfAttackDice;
     }
     int numberOfDefendDice = 0;
     while(numberOfDefendDice <= 0 || numberOfAttackDice > numberOfArmiesDefend-1 || numberOfAttackDice > 2){
         cout << "How many dice would the defender like to roll? (1 to 2, max: Armies-1)" << endl;
         cin >> numberOfDefendDice;
     }
     Dice attackerDice = attacker.getDice();
     Dice defenderDice = defender.getDice();

     while(numberOfArmiesAttack != 0 && numberOfArmiesDefend != 0){
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
     attackCountry.setArmies(numberOfArmiesAttack);
     defendCountry.setArmies(numberOfArmiesDefend);
     if(numberOfArmiesAttack == 0){
         cout << "Defender " << defender.getName() << " has won this round of attack! Both countries keep their respective territories." << endl;
     }else{
         cout << "Attacker " << attacker.getName() << " has won this round of attack! They now own : " << defendCountry.getName() << endl;
         // Set Territory to have new owner and then remove from defender's territory vector
         defendCountry.setTerritoryOwner(attacker.getName());
         int tempPos = defender.posOfCountry(defendCountry.getName());
         vector<Territory> tempCountryVectorDefender = defender.getCountries();
         tempCountryVectorDefender.erase(tempCountryVectorDefender.begin()+tempPos);
         defender.setCountries(tempCountryVectorDefender);
         // Set Territory to attacker
         attacker.addCountry(defendCountry);
     }
}


bool Attack::stopAttack(){
    cout << "Would you like to stop the attack? (Type 'STOP')" << endl;
    string answer;
    cin >> answer;
    if(answer=="STOP"){
        return false;
    }else{
        return true;
    }
}