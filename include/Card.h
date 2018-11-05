#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Card
{
private:
	string type;

public:
	Card(const string &type);
	~Card();
	const string &getType() const;
	void setType(const string &type);
	void getType(string);

};

