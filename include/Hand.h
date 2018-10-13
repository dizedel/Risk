#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>

class Hand
{
private:
	std::vector<Card> cards;
public:
	Hand();
	~Hand();
	int exchange();
	void addCardToHand(Deck&);
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);

};

