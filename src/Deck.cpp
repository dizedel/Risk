#include "../include/Deck.h"
#include "../include/Card.h"
#include <time.h>
#include <vector>

Deck::Deck(std::vector<Card> cardsInDeck)
{
	cards = cardsInDeck;
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
