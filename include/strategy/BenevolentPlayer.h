//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_BENEVOLENTPLAYER_H
#define RISK_BENEVOLENTPLAYER_H


#include "Strategy.h"

class BenevolentPlayer : public Strategy {

    void reinforce(Player *);
    void attack(Player *);
    void fortify(Player *);

};
#endif //RISK_BENEVOLENTPLAYER_H
