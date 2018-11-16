//
// Created by Aloys on 18-10-11.
//

#pragma once
#include <vector>

using namespace std;

class Dice {

public:
    int OneRoll();
    int askNumOfDice();
    vector<int> rolls(int);
    void rollPercentage(int x);
    void displayPercentage();
private:

};