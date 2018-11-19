//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_AGGRESSIVEPLAYER_H
#define RISK_AGGRESSIVEPLAYER_H


#include "Strategy.h"

class AggressivePlayer : public Strategy {

    void reinforce(Player *);
    void attack(Player *);
    void fortify(Player *);

};

#endif //RISK_AGGRESSIVEPLAYER_H
