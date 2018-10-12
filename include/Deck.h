#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>
class Deck
{
private:
	std::vector<Card> cards;
public:
	Deck(int);
	~Deck();
	Card draw();
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
};

