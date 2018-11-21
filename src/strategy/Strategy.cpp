#include <iostream>
#include "Strategy.h"

Strategy::Strategy() {
    cout << "Initializing strategy";
}
void Strategy::executeReinforce(Player*) {

}

void Strategy::executeAttack(Player *) {

}

void Strategy::executeFortify(Player *) {

}

string Strategy::toString(){
    return "General Strategy Object";
}

Strategy::~Strategy() {}