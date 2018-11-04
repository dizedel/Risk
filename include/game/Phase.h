//
// Created by pamel on 2018-11-04.
//

#ifndef PHASE_H
#define PHASE_H


#include <Player.h>

class Phase {
public:
    Phase();
    ~Phase();
    void playerPhase();

    void setPlayer();

    Player getPlayer();


private:
    Player player;
};


#endif //PHASE_H
