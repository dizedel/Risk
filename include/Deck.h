#pragma once
#include "stdafx.h"
#include <vector>
#include "Deck.h"
#include "Card.h"
using namespace std;

class Deck
{
private:
	vector<Card> cards;
public:
	Deck();
	Deck(int);
	~Deck();
	Card draw();
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
};

