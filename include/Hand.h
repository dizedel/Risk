#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>

using namespace std;

class Hand
{
private:
	vector<Card> cards;
	int exchangedHands = 0;
public:
	Hand();
	~Hand();
	int exchange();
	void addCardToHand(Deck&);
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
    int getExchangedHands() const;

};

