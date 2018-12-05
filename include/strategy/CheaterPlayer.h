#pragma once
#include <Strategy.h>
class CheaterPlayer : public Strategy {
    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);
    string toString();
};