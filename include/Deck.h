#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>

using namespace std;

class Deck
{
private:
	vector<Card> cards;
public:
	Deck(int);
	~Deck();
	Card draw();
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
};

