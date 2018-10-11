#pragma once

#include "Deck.h"
#include "Card.h"

class Deck
{
private:
	Card cards[];
public:
	Deck(Card[]);
	~Deck();
	Card draw();
	int cardsRemaining();
};

