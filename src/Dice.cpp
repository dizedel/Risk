/*
 * Dice.cpp
 *
 *  Created on: 10 oct. 2018
 *      Author: Aloys
 */
#include "stdafx.h"
#include "../include/Dice.h"
#include <cstdlib>
#include <iostream>


using namespace std;

int diceRollPercentage[] = {0, 0, 0, 0, 0, 0}; //how to make it private?
int totalRolls = 0;

int Dice::OneRoll() {

    int a = rand()%6+1;
    cout << a <<endl;
    return a;
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

int *Dice::rolls() {
    int a = askNumOfDice();
    int counter = 0;
    int *RollArray = new int[a];
    totalRolls += a;

    while(counter < a){
        RollArray[counter] = OneRoll();
        rollPercentage(RollArray[counter]);
        if(RollArray[counter] < 1 || RollArray[counter] > 6){
            cout << "Error, the dice returned a number outside of the range." <<endl;
        }
        counter++;
    }

    return RollArray;
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







