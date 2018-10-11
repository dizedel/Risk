#include "Card.h"
#include <string>
using namespace std;


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

Type Card::getType()
{
	return type;
}