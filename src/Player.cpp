//
// Created by pamel on 2018-10-11.
//
#include "Player.h"
#include "Territory.h"
#include <vector>
#include <iostream>
#include <Map.h>

using namespace std;
Player::Player() {

}

Player::Player(string name) {
    playerName = name;
    Hand h;
    Dice d;
    hand = h;
    dice = d;
}

Player::~Player()
{
}


string Player::getName(){
   return Player::playerName;
}
vector<Territory> Player::getCountries(){
   return countries;
}

Dice Player::getDice() {
    return dice;
}

Hand Player::getHand() {
    return hand;
}

int Player::getArmies() {
    return armies;
}

void Player::setName(string name) {
   playerName = name;
}

void Player::setHand(Hand h) {
    hand = h;
}

void Player::setCountries(vector<Territory> c) {
   countries = c;
}

void Player::addArmies(int numOfArmies) {
   armies+=numOfArmies;
}

bool Player::addTerritory(string countryName, Map map) {
    return false;
}

int Player::hasCountry(string countryName){
    for (int i = 0; i < countries.size(); i++) {
        if (countries.at(i).getName() == countryName){
            return i;
        }
    }
    return -1;
}

string Player::displayCountries() {
    string str = "";
    for (int i =0; i<countries.size(); i++){
        str += countries.at(i).getName();
        str += "\n";
    }
    return str;
}

void Player::giveArmiesForTerritory(){
    //Todo: round down
    armies += countries.size()/3;
    //TODO: give armies for entire continent
}
