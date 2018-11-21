//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_HUMANPLAYER_H
#define RISK_HUMANPLAYER_H


#include "Strategy.h"

class HumanPlayer : public Strategy {
public:
    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);
    string toString();

};


#endif //RISK_HUMANPLAYER_H
