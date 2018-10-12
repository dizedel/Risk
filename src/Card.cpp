#include "../include/Card.h"


Card::Card(Type typeOfCard)
{
	type = typeOfCard;

}

Card::~Card()
{
}

void Card::setType(Type typeOfCard)
{
	type = typeOfCard;
}

Card::Type Card::getType()
{
	return type;
}