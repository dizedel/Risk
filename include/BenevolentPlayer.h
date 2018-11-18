#pragma once

#include "PlayerStrategy.h"

class BenevolentPlayer : public PlayerStrategy{
public:
    BenevolentPlayer();
    virtual ~BenevolentPlayer();
    virtual void takeTurn(Player&);
};