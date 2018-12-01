 //
// Created by pamel on 2018-12-01.
//

#ifndef RISK_CHEATERPLAYER_H
#define RISK_CHEATERPLAYER_H


#include <Strategy.h>

 class CheaterPlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);
    string toString();
};


#endif //RISK_CHEATERPLAYER_H
