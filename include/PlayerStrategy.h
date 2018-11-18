#pragma once

#include "Player.h"
#include "Attack.h"
#include "Fortify.h"
#include "Reinforce.h"

class PlayerStrategy {
public:
    virtual void takeTurn(Player&);
};

