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
        int getX();
        int getY();
        string getContinent();	//return name of continent territory is in
        vector<string> getNeighbors(); //return the container of neighbors for the territory
        int getArmies(); //return number armies the territory has

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