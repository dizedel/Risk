#pragma once

#include "Deck.h"
#include "Card.h"
#include <vector>
using namespace std;

class Hand
{
private:
<<<<<<< HEAD
	vector<Card> cards;
	int exchangedHands = 0;
=======
	std::vector<Card> cards;
	int numOfExchanges();
>>>>>>> 9d00f61af3ca94593a2e67a8a96a6d90ef2d39e9
public:
	Hand();
	~Hand();
	int exchange();
	void addCardToHand(Deck&);
	const vector<Card> &getCards() const;
	void setCards(const vector<Card> &cards);
<<<<<<< HEAD
    int getExchangedHands() const;
=======
	string toString();
>>>>>>> 9d00f61af3ca94593a2e67a8a96a6d90ef2d39e9

};

