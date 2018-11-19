//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_BENEVOLENTPLAYER_H
#define RISK_BENEVOLENTPLAYER_H


#include "Strategy.h"

class BenevolentPlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);


};
#endif //RISK_BENEVOLENTPLAYER_H
