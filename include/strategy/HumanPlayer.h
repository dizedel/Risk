//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_HUMANPLAYER_H
#define RISK_HUMANPLAYER_H


#include "Strategy.h"

class HumanPlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);

};


#endif //RISK_HUMANPLAYER_H
