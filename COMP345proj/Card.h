#pragma once
#include <string>
using namespace std;

class Card
{
private:
	enum Type = { infantry, artillery, cavalry };
	Type type;

public:
	Card(Type);
	~Card();
	void setType(Type);
	Type getType();

};

