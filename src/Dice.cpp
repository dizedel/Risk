/*
 * Dice.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: Aloys
 */
#include "../include/Dice.h"
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

int diceRollPercentage[] = {0, 0, 0, 0, 0, 0}; //how to make it private?
int totalRolls = 0;

int Dice::OneRoll() {

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

int Dice::askNumOfDice() {
    int nOfDice = 1;

    cout << "How many dice would you like to roll? (1 to 3)" << endl;
    cin >> nOfDice;

    while(nOfDice > 3 || nOfDice < 1){
        cout << "Not in range, try again:";
        cin >> nOfDice;
    }

    return nOfDice;
}

vector<int> Dice::rolls(int max) {
    int counter = 0;
    vector<int> RollVec;
    totalRolls += max;

    while(counter < max){
        int roll = OneRoll();
        RollVec.push_back(roll);
        rollPercentage(roll);
        if(roll < 1 || roll > 6){
            cout << "Error, the dice returned a number outside of the range." <<endl;
        }
        counter++;
    }

    return RollVec;
}

void Dice::displayPercentage() {
    for(int i=0; i<6; i++){
        double temp = (double(diceRollPercentage[i])/totalRolls)*100;
        cout << "The dice has rolled " << i+1 << " : " << temp << "%" << endl;
    }
    cout <<endl;
}

void Dice::rollPercentage(int x){
    diceRollPercentage[x-1]++;
}