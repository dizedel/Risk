#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>
using namespace std;

class Hand
{
private:
	vector<Card> cards;

public:
	Hand();
	~Hand();
    static int exchangedHands;
	int exchange();
	void addCardToHand(Deck&);
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
    static int getExchangedHands();
	string toString();

};

