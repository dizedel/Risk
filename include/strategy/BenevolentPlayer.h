//
// Created by pamel on 2018-11-18.
//

#ifndef RISK_BENEVOLENTPLAYER_H
#define RISK_BENEVOLENTPLAYER_H

#include <string>
#include "Strategy.h"

using namespace std;

class BenevolentPlayer : public Strategy {

    void executeReinforce(Player *);
    void executeAttack(Player *);
    void executeFortify(Player *);

    void giveArmiesForTerritory(Player*);
    string weakestCountry(Player*);
    bool reinforceLoop(Player*);
    void playPhase(Player*);

};
#endif //RISK_BENEVOLENTPLAYER_H
