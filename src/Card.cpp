#include "../include/Card.h"


Card::Card(const string &type) : type(type) {}

Card::~Card()
{
}

const string &Card::getType() const {
	return type;
}

void Card::setType(const string &type) {
	Card::type = type;
}
