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

void Player::reinforce(int numOfArmies, string country) {
   string txtline;
   bool answered = false;

   giveArmiesForTerritory();

   //-----------------EXCHANGE CARDS------------------------
   cout << "Do you wish to exchange your cards?";
   getline(cin, txtline);
   while (!answered){
      if (txtline=="yes"){
         /*int cardArmies = hand.exchange();
          * if (cardArmies != 0){
            armies+=hand.exchange();
            cout >> "You have exchanged your cards for " + cardArmies + " armies."
          }*/
         else{
            cout << "You have no cards that can be exchanged."
         }
         answered = true;
      }
      else if(txtline=="no"){
         cout << "No cards will be exchanged this turn";
         answered = true;
      }
   }
   answered = false;

   //-----------------EXCHANGE CARDS------------------------




}

void Player::attack(int numOfArmies, string country){

   armies-=numOfArmies;
}

void Player::fortify(int numOfArmies, string country){
   armies-=numOfArmies;
}







