#pragma once

#ifndef TERRITORY_H
#define TERRITORY_H

#include <string>
#include <vector>

using namespace std;

class Territory {

    public:
        Territory();
        Territory(string, int, int, vector<string>);
        ~Territory();

        string getName();
        int getArmies();
        int getX();
        int getY();
        string getContinent();
        vector<string> getNeighbors();

        void setName(string);
        void setArmies(int);
        void setX(int);
        void setY(int);
        void setContinent(string);
        void addArmies(int);
        void addNeighbor(string);

    private:
        string name;
        int armies;
        int coordX;
        int coordY;
        string continent;
        vector<string> neighbors;
    };
#endif