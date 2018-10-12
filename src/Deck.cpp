#include "../include/Deck.h"
#include "../include/Card.h"
#include <time.h>
#include <vector>

Deck::Deck(int numOfCards)
{
	for (int i = 1; i <= numOfCards; i++)
	{
		if (i % 3 == 0)
			cards.push_back(Card("infantry"));
		else if (i % 2 == 0)
			cards.push_back(Card("artillery"));
		else if (i % 1 == 0)
			cards.push_back(Card("cavalry"));
	}

}


Deck::~Deck()
{
}

Card Deck::draw()
{
	srand(time(NULL));

	int randomIndex = rand() % cards.size();
	Card toDraw = cards[randomIndex];
	cards.erase(cards.begin() + randomIndex);
	return toDraw;
}

const vector<Card> &Deck::getCards() const
{
	return cards;
}

void Deck::setCards(const vector<Card> &cards)
{
	Deck::cards = cards;
}
