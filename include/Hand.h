#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>

class Hand
{
private:
	std::vector<Card> cards;
	int numOfExchanges();
public:
	Hand();
	~Hand();
	int exchange(int);
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
	string toString();

};

