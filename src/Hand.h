#pragma once
class Hand
{
private:
	Card cardsInHand[];
public:
	Hand();
	~Hand();
	void exchange();
};

