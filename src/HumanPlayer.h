#pragma  once
#include "PlayerStrategy.h"

class HumanPlayer : public PlayerStrategy{
public:
    HumanPlayer();
    virtual ~HumanPlayer();
    void humanReinforce(Player&);
    bool reinforce(Player&);
    void giveArmiesForTerritory(Player&);
    void humanFortify(Player&);
    virtual void takeTurn(Player&);
};
