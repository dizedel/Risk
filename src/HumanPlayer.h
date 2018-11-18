#pragma  once
#include "PlayerStrategy.h"

class HumanPlayer : public PlayerStrategy{
public:
    HumanPlayer();
    virtual ~HumanPlayer();
    virtual void takeTurn();
};
