//
// Created by pamel on 2018-10-11.
//
#include <strategy/HumanPlayer.h>
#include "Player.h"


Player::Player() {
    Hand *h = new Hand();
    Dice d;
    hand = *h;
    dice = d;
    armies = 0;
    strategy = NULL;
}

Player::Player(string name) {
    playerName = name;
    Hand *h = new Hand();
    Dice d;
    hand = *h;
    dice = d;
    armies = 0;
    strategy = NULL;
}

Player::~Player()
{
}


string Player::getName(){
    return Player::playerName;
}

vector<Territory>& Player::getCountries(){
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

Strategy Player::getStrategy() {
    return *strategy;
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

void Player::setArmies(int a){
    armies = a;

}

void Player::addArmies(int numOfArmies) {
    armies+=numOfArmies;
    Notify();
}

void Player::addCountry(Territory t) {
    countries.push_back(t);
}

int Player::posOfCountry(string countryName){
    for (int i = 0; i < countries.size(); i++) {
        if (countries.at(i).getName() == countryName){
            return i;
        }
    }
    return -1;
}

bool Player::hasCountry(string countryName){
    if(posOfCountry(countryName)==-1)
        return false;
    else
        return true;
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

void Player::addTerritory(Territory t) {
    countries.push_back(t);
    Notify();
}

void Player::setInitialArmies(int n){
    initialArmies=n;
}

void Player::setStrategy(Strategy* strat) {
    strategy = strat;
}

void Player::assignInitialArmyToCountry(int n){
    initialArmies-=n;
}

int Player::getInitialArmies(){
    return initialArmies;
}

void Player::doReinforce(Player * p) {
    //TODO:Could add GiveArmiesFromLand in here
    strategy->executeReinforce(this);
}

void Player::doAttack(Player * p) {
    strategy->executeAttack(this);

}

void Player::doFortify(Player * p) {
    strategy->executeFortify(this);

}