#include "../include/Hand.h"
#include "../include/Deck.h"
#include "../include/Card.h"
#include <vector>
#include <iostream>

Hand::Hand()
{
}


Hand::~Hand()
{
}

int Hand::exchange()
{
    int infantry = 0;
    int artillery = 0;
    int cavalry = 0;

    bool infantryFlag = true;
    bool artilleryFlag = true;
    bool cavalryFlag = true;

    for (int i = 0; i < cards.size(); i++)
    {
        if (cards[i].getType() == "infantry")
            infantry++;
        if (cards[i].getType() == "artillery")
            artillery++;
        if (cards[i].getType() == "cavalry")
            cavalry++;
    }

    if ((infantry >= 3 || artillery >= 3 || cavalry >= 3)||(infantry > 0 && artillery > 0 && cavalry > 0))
    {
        if (infantry >= 3 || artillery >= 3 || cavalry >= 3)
        {
            int cardsToDiscard = 3;

            if (infantry < 3)
                infantryFlag = false;

            if (artillery < 3)
                artilleryFlag = false;

            if (cavalry < 3)
                cavalryFlag = false;

            while (cardsToDiscard > 0)
            {
                for (int i = 0; i < cards.size(); i++)
                {
                    if (infantryFlag == true && cards[i].getType() == "infantry")
                    {
                        cards.erase(cards.begin() + i);
                        cardsToDiscard--;
                    }

                    else if (artilleryFlag == true && cards[i].getType() == "artillery")
                    {
                        cards.erase(cards.begin() + i);
                        cardsToDiscard--;
                    }

                    else if (cavalryFlag == true && cards[i].getType() == "cavalry")
                    {
                        cards.erase(cards.begin() + i);
                        cardsToDiscard--;
                    }
                }
            }
        }

        else
        {
            infantryFlag = true;
            artilleryFlag = true;
            cavalryFlag = true;

            for (int i = 0; i < cards.size(); i++)
            {
                if (infantryFlag == true && cards[i].getType() == "infantry")
                {
                    cards.erase(cards.begin() + i);
                    infantryFlag == false;
                }

                if (artilleryFlag == true && cards[i].getType() == "artillery")
                {
                    cards.erase(cards.begin() + i);
                    artilleryFlag = false;
                }

                if (cavalryFlag == true && cards[i].getType() == "cavalry")
                {
                    cards.erase(cards.begin() + i);
                    cavalryFlag = false;
                }
            }
        }


        if (exchangedHands == 0)
        {
            exchangedHands++;
            return 4;
        }

        if (exchangedHands == 1)
        {
            exchangedHands++;
            return 6;
        }

        if (exchangedHands == 2)
        {
            exchangedHands++;
            return 8;
        }

        if (exchangedHands == 3)
        {
            exchangedHands++;
            return 10;
        }

        if (exchangedHands == 4)
        {
            exchangedHands++;
            return 12;
        }

        if (exchangedHands == 5)
        {
            exchangedHands++;
            return 15;
        }

        if (exchangedHands > 5)
        {
            exchangedHands++;
            return 15 + 5 * (exchangedHands - 6);
        }
    }
    else
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
   else
   {
       cout << "Your hand is full.\nPlease exchange cards in your hand for armies before drawing again." << endl;
   }
}

int Hand::getExchangedHands() const {
    return exchangedHands;
}

