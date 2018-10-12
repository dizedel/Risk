#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> cards;
public:
	Deck(std::vector<Card>);
	~Deck();
	Card draw();
};

