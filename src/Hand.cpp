#include "../include/Hand.h"
#include "../include/Deck.h"
#include "../include/Card.h"
#include <vector>

Hand::Hand()
{
}


Hand::~Hand()
{
}

int Hand::exchange()
{
    return 0;
}

const vector<Card> &Hand::getCards() const
{
    return cards;
}

void Hand::setCards(const vector<Card> &cards)
{
    Hand::cards = cards;
}

void Hand::addCardToHand(Deck &deck)
{
   if(cards.size() < 5)
       Hand::cards.push_back(deck.draw());
}