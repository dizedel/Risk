//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_AGGRESSIVEPLAYER_H
#define RISK_AGGRESSIVEPLAYER_H


#include "Strategy.h"

class AggressivePlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);

};

#endif //RISK_AGGRESSIVEPLAYER_H
