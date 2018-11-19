#pragma once
#ifndef RISK_STRATEGY_H
#define RISK_STRATEGY_H

class Player;

class Strategy {
public:
    virtual void reinforce(Player* player);
    virtual void attack(Player* player);
    virtual void fortify(Player* player);
    virtual ~Strategy();
};

#endif