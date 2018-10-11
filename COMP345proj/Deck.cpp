#include "Deck.h"
#include "Card.h"
#include <time.h>

Deck::Deck(Card cardsInDeck[])
{
	cards = cardsInDeck;
}


Deck::~Deck()
{
}

Card Deck::draw()
{
	srand(time(NULL));

	int randomIndex = rand() % cardsRemaining();
	Card toDraw = cards[randomIndex];

	if (cardsRemaining() > 0)
	{
		Card temp = cards[cardsRemaining() - 1];
		cards[randomIndex] = temp;
		cards[cardsRemaining() - 1] = NULL;
	}

	return toDraw;
}

int Deck::cardsRemaining()
{
	int cardsRemaining;
	int i = 0;

	while (cards[i] != NULL)
	{
		i++;
	}

	cardsRemaining = i;

	return cardsRemaining;
}
