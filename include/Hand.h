#pragma once

#include "Card.h"

class Hand
{
private:
	Card cardsInHand[];
public:
	Hand(Card[]);
	~Hand();
	void exchange();
};

