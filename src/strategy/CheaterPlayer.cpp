//
// Created by pamel on 2018-12-01.
//

#include "CheaterPlayer.h"

//
// Created by aloys on 2018-11-28.
//
#include <Random>

#include "strategy/RandomPlayer.h"
#include "game/Reinforce.h"
#include "game/Attack.h"
#include "game/Fortify.h"


void RandomPlayer::executeReinforce(Player *p){

   
}

// Not implemented right now
void RandomPlayer::executeAttack(Player *p){

}

void RandomPlayer::executeFortify(Player *p){


}

string RandomPlayer::toString(){
    return "Cheater Player";
}
