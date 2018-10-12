//
// Created by pamel on 2018-10-11.
//
#include "Player.h"
#include "Territory.h"
#include <vector>
#include <iostream>

using namespace std;

string Player::getName(){
   return playerName;
}
vector<Territory> Player::getCountries(){
   return countries;
}

void Player::setName(string name) {
   playerName = name;
}

void Player::setCountries(vector<Territory> c) {
   countries = c;
}

void Player::addArmies(int numOfArmies) {
   armies+=numOfArmies;
}

int Player::hasCountry(string countryName){
    for (int i = 0; i < countries.size(); i++) {
        if (countries.at(i).getName() == countryName){
            return i;
        }
    }
    return -1;
}

void Player::giveArmiesForTerritory(){
   //TODO: round down
   armies += countries.size()/3;
   //TODO: give armies for entire continent
   //Search if the person posesses the country selected.
   /*for(int i=0; i<countries.size(); i++){
      if (countries[i].getName()==country){
         countries[i].addArmies(numOfArmies);
         armies-=numOfArmies;
         return true;
      }
   }
   return false;*/
}

/***********************************************************
 *              REINFORCEMENT
 * *********************************************************
 */
void Player::reinforce() {
   string txtline;
   bool answered = false;

   giveArmiesForTerritory();

   //-----------------EXCHANGE CARDS------------------------
   cout << "Do you wish to exchange your cards? \n";
   getline(cin, txtline);
   while (!answered){
      if (txtline=="yes"){
         int cardArmies = hand.exchange(0); //This is a test value and needs to be fixed once the exchange function is fixed
          if (cardArmies != 0){
            armies+=cardArmies;
            cout << "\n You have exchanged your cards for " << cardArmies << " armies.";
          }
         else{
            cout << "You have no cards that can be exchanged.";
         }
         answered = true;
      }
      else if(txtline=="no"){
         cout << "No cards will be exchanged this turn";
         answered = true;
      }
      else{
          cout<< "Not a valid answer.";
      }
   }
   answered = false;

   //-----------------ADD ARMIES TO COUNTRIES------------------------

   //TODO: Receive  armies for entire continents
   if(armies>= 3) {
       while (!answered && armies >= 3) {
           cout << "Which countries do you wish to reinforce? Enter 'Done' if you do not wish to";
           getline(cin, txtline);
           if (txtline == "Done") {
               answered = true;
               break;
           } else if (hasCountry(txtline)) {
               int numOfArmies = 0;
               while (true) {
                   cout << "How many armies do you wish to place?";
                   cin >> numOfArmies;
                   if (numOfArmies < 3) {
                       cout << "You need to place more than 3 armies per country";
                   } else {
                       countries.at(hasCountry(txtline)).addArmies(numOfArmies);
                       break;
                   }
               }

           } else {
               cout << "You do not have this country";
           }
       }
   }
   else{
       cout<< "You do not have enough armies to reinforce at the moment";
   }
}

/***********************************************************
 *                       ATTACK
 * *********************************************************
 */

void Player::attack(int numOfArmies, string country){
    //TODO: Implement Attack function
}


/***********************************************************
 *                   FORTIFICATION
 * *********************************************************
 */
void Player::fortify(int numOfArmies, string country){
    //TODO: Implement fortification function
}







