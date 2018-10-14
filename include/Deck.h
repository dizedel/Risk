#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>
<<<<<<< HEAD
using namespace std;
=======
>>>>>>> 9d00f61af3ca94593a2e67a8a96a6d90ef2d39e9

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

