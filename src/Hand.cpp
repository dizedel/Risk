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

int Hand::exchange(int index)
{
    if (this->getCards()[index].getType() == "infantry") {
        cards.erase(cards.begin() + index);
        return 1;
    }
    if (this->getCards()[index].getType() == "cavalry"){
        cards.erase(cards.begin() + index);
        return 5;
    }
    if (this->getCards()[index].getType() == "artillery"){
        cards.erase(cards.begin() + index);
        return 10;
    }

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
